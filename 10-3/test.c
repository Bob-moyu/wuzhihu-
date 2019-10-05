#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include<errno.h>
#define  ERR_EXIT(m)
void exit(int status);
//int main()
//{
//  printf("hello");
 // pid_t pid;
 // pid=fork();
 // if(pid<0)
 // {
 //   perror("fork");
 //   return 1;
 // }
 // else if(pid==0)
 // {
 //   printf("child is run,pid=%d\n",getpid());
 //   sleep(5);
 //   exit(257);
 // }
 // else 
 // {
 //   int status=0;
 //   pid_t ret=waitpid(-1,&status,0);//阻塞式等待，等待5秒
 //   printf("this is test for wait\n");
 //   if(WIFEXITED(status) && ret==pid){
 //     printf("wait child 5s success,child return code is:%d.\n",WIFEXITED(status));
 //   }
 //   else{
 //     printf("wait child failed,return.\n");
 //     return 1;
 //   }
 // }
 // pid_t pid;
 // pid =fork();
 // if(pid<0)
 // {
 //   printf("%s fork error\n",__FUNCTION__);
 //   return 1;
 // }
 // else if(pid==0)
 // {
 //   printf("child if run,pid=%d\n",getpid());
 //   sleep(5);
 //   exit(1);
 // }
 // else 
 // {
 //   int status=0;
 //   pid_t ret=0;
 //   do
 //   {
 //     ret=waitpid(-1,&status,WNOHANG);
 //     if(ret==0)
 //     {
 //       printf("child is runing\n");
 //     }
 //     sleep(1);
 //   }
 //   while(ret==0);
 //   if(WIFEXITED(status) && ret==pid)
 //   {
 //     printf("wait child 5s success,child return code is:%d.\n",WEXITSTATUS(status));
 //   }
 //   else{
 //     printf("wait child failed,return\n");
 //     return 1;
 //   }
 // }
 // FILE *fp=fopen("myfile","w");
 // if(!fp)
 // {
 //   printf("fopen error!\n");
 // }
 // const char* msg="hello bit!\n";
 // int count=5;
 // while(count--)
 // {
 //   fwrite(msg,strlen(msg),1,fp);
 // }
 // fclose(fp);
//  return 0;
//}
//int main(void)
//{
//  int fds[2];
//  char buff[100];
//  int len;
//  if(pipe(fds)==-1)
//    perror("make pipe"),exit(1);
//  while(fgets(buff,100,stdin)){
//    len=strlen(buff);
//    if(write(fds[1],buff,len)!=len){
//      perror("write to pipe");
//      break;
//    }
//    memset(buff,0x00,sizeof(buff));
//    if((len=read(fds[0],buff,100))==-1){
//      perror("read from pipe");
//      break;
//    }
//    if(write(1,buff,len)!=len){
//      perror("write to stdout");
//      break;
//    }
//  }
//}
int main(int argc,char* argv[])
{
  int pfd[2];
  if(pipe(pfd)==-1)
    ERR_EXIT("pipe error");
  pid_t pid;
  pid=fork();
  if(pid==-1)
    ERR_EXIT("fork error");
  if(pid==0){
    close(pfd[0]);
    write(pfd[1],"hello",5);
    close(pfd[1]);
    exit(EXIT_SUCCESS);
  }
  close(pfd[1]);
  char buff[2]={0};
  read(pfd[0],buff,10);
  printf("buff=%s\n",buff);
  return 0;
}
