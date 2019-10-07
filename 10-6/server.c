#include"comm.h"
int main()
{
  int shmid=createShm(4096);
  char *addr=(char*)shmat(shmid,NULL,0);
  sleep(2);
  int i=0;
  while(i++<26){
    printf("client# %s\n",addr);
    sleep(1);
  }
  shmdt(addr);
  sleep(2);
  destoryShm(shmid);
  return 0;
}
