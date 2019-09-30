#include<iostream>
#include<algorithm>
#include<mutex>
//using namespace std;
//class Singleton
//{
//  public:
//    static Singleton* GetInstance()
//    {
//      if(a==NULL)
//      {
//        _mutex.lock();
//        if(a==NULL)
//        {
//          a=new Singleton;
//        }
//        _mutex.unlock();
//      }
//      return a;
//    }
//    class Garbage
//    {
//      public:
//      ~Garbage()
//      {
//        if(Singleton::a)
//          delete Singleton::a;
//      }
//    };
//    static Garbage ga;
//  private:
//    Singleton(){};
//    Singleton(const Singleton&)=delete;
//    Singleton& operator=(const Singleton&)=delete;
//    static Singleton* a;
//    static mutex _mutex;
//};
//Singleton* Singleton::a=NULL;
//mutex Singleton::_mutex;
//Singleton::Garbage ga;
//class Singleton 
//{
//  public:
//    static Singleton* GetInstance()
//    {
//      return &a;
//    }
//  private:
//    static Singleton a;
//    Singleton(){};
//    Singleton(const Singleton&)=delete;
//    Singleton& operator=(const Singleton&)=delete;
//};
//Singleton Singleton::a;
//void AdjustDown(int arr[],int sz,int root)
//{
//  int i=2*root+1;
//  if(i>=sz)
//    return;
//  int j=2*root+2;
//  int m=i;
//  if(j<sz && arr[m]<arr[j])
//    m=j;
//  if(arr[m]>arr[root])
//  {
//    std::swap(arr[root],arr[m]);
//    AdjustDown(arr,sz,m);
//  }
//}
//void CreateHeap(int arr[],int sz)
//{
//  for(int i=(sz-2)/2;i>=0;i--)
//  {
//    AdjustDown(arr,sz,i);
//  }
//}
//void HeapSort(int arr[],int sz)
//{
//  CreateHeap(arr,sz);
//  for(int i=0;i<sz;i++)
//  {
//    std::swap(arr[0],arr[sz-i-1]);
//    AdjustDown(arr,sz-i-1,0);
//  }
//}
//int main()
//{
//  int arr[]={21,43,654,321,64,32,546,432,654,43,67,43,542};
//  int sz=sizeof(arr)/sizeof(int);
//  HeapSort(arr,sz);
//  for(int i=0;i<sz;i++)
//  {
//    std::cout<<arr[i]<<" ";
//  }
//  std::cout<<std::endl;
//  return 0;
//}
struct ListNode 
{
  int value;
  ListNode* next;
};
ListNode* Reserve(ListNode* head)
{
  if(head==NULL || head->next==NULL)
    return head;
  ListNode* cur=head;
  ListNode* pre=NULL;
  while(cur!=NULL)
  {
    ListNode* p=cur;
    cur=cur->next;
    p->next=pre;
    pre=p;
  }
  return pre;
}
