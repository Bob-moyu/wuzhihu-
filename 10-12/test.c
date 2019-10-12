#include<iostream>
#include<algorithm>
using namespace std;
void SelectSort(int arr[],int sz)
{
  int min=0;
  int i=0,j=0;
  for(i=0;i<sz-1;i++)
  {
    min=i;
    for(j=i+1;j<sz;j++)
    {
      if(arr[min]>arr[j])
        min=j;
      }
    if(i!=min)
      swap(arr[min],arr[i]);
    }
}
int main()
{
  int arr[]={2,1,3,5,4,6,4,7,9,7,6,0,6,3};
  int sz=sizeof(arr)/sizeof(int);
  SelectSort(arr,sz);
  for(int i=0;i<sz;i++)
  {
    cout<<arr[i]<<endl;
  }
  return 0;
}
