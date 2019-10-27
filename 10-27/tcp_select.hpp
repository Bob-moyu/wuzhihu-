#pragma once 
#include<vector>
#include<unordered_map>
#include<functional>
#include<sys/select.h>
inline void PrintFdSet(fd_set *fds,int max_fd){
  printf("celect fds:");
  for(int i=0;i<max_fd;++i){
    if(!FD_ISSET(i,fds)){
      continue;
    }
    printf("%d",i);
  }
  printf("\n");
}
typedef std::function<void (const std::string& req,std::string* resp)>Handler;
class Selector{
  public:
    Selector(){
      max_fd_ = 0;
      FD_ZERO(&read_fds_);
    }
    bool Add(const TcpSocket& sock){
      int fd=sock.Getfd();
      printf("[Selector::Add] %d\n",fd);
      if(fd_map_.find(fd) != fd_map_.end()){
        printf("Add failed! fd has in Selector!\n");
        return false;
      }
      fd_map_[fd] = sock;
      FD_SET(fd,&read_fds_);
      if(fd> max_fd_){
        max_fd_=fd;
      }
      return true;
    }
    bool Del(const TcpSOcket& sock){
      int fd = sock.Getfd();
      printf("[Selector::Del] %d\n",fd);
      if(fd_map_.find(fd) == fd_map_.end()){
        printf("Del failed! fd has not in Select!\n");
        return false;
      }
      fd_map_.erase(fd);
      FD_CLR(fd,&read_fds_);
      for(int i=max_fd_;i>=0;--i){
        if(!FD_ISSET(i,&read_fds_)){
          continue;
        }
        max_fd_=i;
        break;
      }
      return true;
    }
    bool Wait(std::vector<TcpSocket>* output){
      output->clear();
      fd_set tmp=read_fds_;
      PrintfFdSet(&tmp,max_fd_);
      int nfds = select(max_fd_+1,&tmp,NULL,NULL,NULL);
      if(nfds<0){
        perror("Select");
        return false;
      }
      for(int i=0;i<max_fd_+1;++i){
        if(!FD_ISSET(i,&tmp)){
          continue;
        }
        output->push_back(fd_map_[i]);
      }
      return true;
    }
  private:
    fd_set read_fds_;
    int max_fd_;
    std::unordered_map<int,TcpSocket> fd_map_;
};
class TcpSelectServer{
  public:
    TcpSelectServer(const std::string& ip,uint16_t port):ip_(ip),port_(port){
      bool Start(Handler handler)const{
        TcpSocket listen_sock;
        bool ret=listen_sock.Socket();
        if(!ret){
          return false;
        }
        ret=listen_sock.Bind(ip_,port_);
        if(!ret)
        {
          return false;
        }
        ret=listen_sock.Listen(5);
        if(!ret){
          return false;
        }
        Selector selector;
        selector.Add(listen_sock);
        for(;;){
          std::vector<TcpSocket> output;
          bool ret=selector.Wait(&output);
          if(!ret){
            continue;
          }
          for(size_t i=0;i<output.size();++i){
            if(output[i].GetFd()==listen_sock.GetFd()){
              TcpSocket new_sock;
              listen_sock.Accpet(&new_sock,NULL,NULL);
              selector.Add(new_sock);
            }
            else{
              std::string req,resp;
              bool ret=output[i].Recv(&req);
              if(!ret){
                selector.Del(output[i]);
                output[i].Close();
                continue;
              }
              handler(req,&reap);
              output[i].Send(resp)''
            }
          }
        }
      }
      return true;
    }
  private:
    std::string ip_;
    uint16_t port_;
};
