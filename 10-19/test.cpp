#include<iostream>
#include<vector>
using namespace std;
void Func(int n,int m)
{
  vector<int>v;
  int num=n;
  int ret=0;
  while(num>0)
  {
    ret=num%m;
    v.insert(v.begin(),ret);
    num/=m;
  }
  for(int i=0;i<v.size();i++)
  {
    cout<<v[i];
  }
  cout<<endl;
}
int main()
{
  int n,m;
  cin>>n>>m;
  Func(n,m);
  return 0;
}
