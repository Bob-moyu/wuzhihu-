#include<iostream>
using namespace std;
const int N=10100+5;
int n,x,c;
int arr[N];
int main()
{
  cin>>n>>x;
  c=x+100;
  arr[0]=1;
  for(int i=0;i<n;i++)
  {
    int a;
    cin>>a;
    for(int j=c;j>=a;--j)
    {
      if(arr[i]==1)
      {
        cout<<i;
        break;
      }
    }
  }
  return 0;
}
