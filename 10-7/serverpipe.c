#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#define ERR_EXIT(m)
int main()
{
  umask(0);
  if(mkfifo("mypipe",0664)<0){
    ERR_EXIT("mkfifo");
  }
  int rfd=open("mypipe",O_RDONLY);
  if(rfd<0){
    ERR_EXIT("open");
  }
  char buff[1024];
  while(1){
    buff[0]=0;
    printf("Please wait...\n");
    ssize_t s=read(rfd,buff,sizeof(buff)-1);
    if(s>0){
      buff[s-1]=0;
      printf("client say# %s\n",buff);
    }else if(s==0)
    {
      printf("client quit,exit now!\n");
      exit(EXIT_SUCCESS);
    }
    else{
      ERR_EXIT("read");
    }
  }
  close(rfd);
  return 0;
}
