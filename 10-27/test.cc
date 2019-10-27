//#include<stdio.h>
//#include<unistd.h>
//#include<fcntl.h>
//#include<sys/select.h>
////void SetNoBlock(int fd)
////{
////  int f1=fcntl(fd,F_GETFL);
////  if(f1<0){
////    perror("fcntl");
////    return;
////  }
////  fcntl(fd,F_SETFL,f1 | O_NONBLOCK);
////}
////
////int main()
////{
////  SetNoBlock(0);
////  while(1)
////  {
////    char buf[1024]={0};
////    ssize_t read_size = read(0,buf,sizeof(buf)-1);
////    if(read_size < 0){
////      perror("read");
////      sleep(1);
////      continue;
////    }
////    printf("input:%s\n",buf);
////  }
////  return 0;
////}
//int main()
//{
//  fd_set read_fds;
//  FD_ZERO(&read_fds);
//  FD_SET(0,&read_fds);
//
//  for(;;){
//    printf("> ");
//    fflush(stdout);
//    int ret = select(1,&read_fds,NULL,NULL,NULL);
//    if(ret<0){
//      perror("select");
//      continue;
//    }
//    if(FD_ISSET(0,&read_fds)){
//      char buf[1024] = {0};
//      read(0,buf,sizeof(buf)-1);
//      printf("input:%s",buf);;
//    }
//    else{
//      printf("error! invaild fd\n");
//      continue;
//    }
//    FD_ZERO(&read_fds);
//    FD_SET(0,&read_fds);
//  }
//  return 0;
//  }
