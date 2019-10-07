//#include<stdio.h>
//#include<unistd.h>
//int main()
//{
//  int count=14;
//  alarm(1);
//  for(;1;count++)
//  {
//    printf("count = %d\n",count);
//  }
//  return 0;
//}
//#include<stdio.h>
//#include<signal.h>
//void handler(int sig)
//{
//  printf("catch a sig: %d\n",sig);
//}
//int main()
//{
//  signal(2,handler);
//  while(1);
//  return 0;
//}
#include<unistd.h>
#include<stdio.h>
#include<signal.h>
void hangler(int sig)
{
  printf("catch a sig : %d\n",sig);
}
int main()
{
  sleep(1);
  int *p=NULL;
  *p=100;
  while(1);
  return 0;
}
