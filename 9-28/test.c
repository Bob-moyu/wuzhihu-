//#include<stdio.h>
//#include<stdlib.h>
//#include<sys/types.h>
//#include<unistd.h>
//int main()
//{
// // printf("pid:%d\n",getpid());
// // printf("ppid:%d\n",getppid());
//  int ret=fork();
//  //printf("pid:%d,ret:%d\n",getpid(),ret);
//  if(ret<0){
//    perror("fork");
//    return 1;
//  }
//  else if(ret==0)
//  {
//    printf("I am child pid:%d,ret:%d\n",getpid(),ret);
//    sleep(10);
//  }
//  else{
//    printf("I am father pid:%d,ret:%d\n",getpid(),ret);
//    sleep(3);
//    exit(0);
//  }
//  sleep(1);
//  return 0;
//}
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
//int main(void)
//{
//  pid_t pid;
//  if(pid=fork()==-1)
//    perror("fork"),exit(1);
//  if(pid==0){
//    sleep(20);
//    exit(10);
//  }   
//  else{
//    int st;
//    int ret=wait(&st);
//    if(ret>0 && (st & 0X7F)==0){
//      printf("child exit code:%d\n",(st>>8)&0XFF);
//    }
//    else if(ret>0){
//      printf("sig code:%d\n",st&0X7F);
//    }
//  }
//}
int main()
{
  pid_t pid;
  pid = fork();
  if(pid < 0){
    printf("%s fork error\n",__FUNCTION__);
    return 1;

  } else if( pid == 0  ){ //child
  printf("child is run, pid is : %d\n",getpid());
  sleep(20);
  exit(257);
  } else{
    int status = 0;
    pid_t ret = waitpid(-1, &status, 0);//阻塞式等待，等待5S
    printf("this is test for wait\n");
    if( WIFEXITED(status) && ret == pid  ){
      printf("wait child 5s success, child return code is:%d.\n",WEXITSTATUS(status));

    }else{
      printf("wait child failed, return.\n");
      return 1;

    }

  }
  return 0;

}
