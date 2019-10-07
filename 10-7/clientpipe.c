#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#define ERR_EXIT(m)
int main()
{
  int wfd=open("mypipe",O_WRONLY);
  if(wfd<0){
    ERR_EXIT("open");
  }
  char buff[1024];
  while(1)
  {
    buff[0]=0;
    printf("please enter# \n");
    fflush(stdout);
    ssize_t s=read(0,buff,sizeof(buff)-1);
    if(s>0){
      buff[s]=0;
      write(wfd,buff,strlen(buff));
    }
    else if(s==0)
    {
      ERR_EXIT("read");
    }
  }
  close(wfd);
  return 0;
}
