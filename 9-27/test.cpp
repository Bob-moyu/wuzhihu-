#include<iostream>
#include<mutex>
using namespace std;
//class Singleton
//{
//  public:
//    static Singleton* GetInstance()
//    {
//      if(a==nullptr)
//      {
//        _mutex.lock();
//        if(a==nullptr)
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
//        ~Garbage()
//        {
//          if
//            (Singleton::a) 
//            delete Singleton::a;
//        }
//    };
//    static Garbage ga;
//  private:
//    static Singleton* a;
//    Singleton(){};
//    Singleton(const Singleton&)=delete;
//    Singleton& operator=(const Singleton&)=delete; 
//    static std::mutex _mutex;
//};
//std::mutex Singleton::_mutex;
//Singleton* Singleton::a;
//Singleton::Garbage ga;
//class Singleton
//{
//  public:
//    static Singleton* GetInstance()
//    {
//      return &a;
//    }
//  private:
//    Singleton(){};
//    Singleton(const Singleton&)=delete;
//    Singleton& operator=(const Singleton&)=delete;
//    static Singleton a;
//};
//Singleton Singleton::a;
typedef struct ListNode
{
  int value;
  ListNode* next;
};
//ListNode* Reverse(ListNode* head)
//{
//  if(head==nullptr || head->next==nullptr)
//    return head;
//  ListNode* cur=head;
//  ListNode* pre=nullptr;
//  while(cur!=nullptr)
//  {
//    ListNode* p=cur;
//    cur=cur->next;
//    p->next=pre;
//    pre=p;
//  }
//  return pre;
//}
