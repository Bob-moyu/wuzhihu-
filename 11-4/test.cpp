#include<iostream>
#include<mutex>
using namespace std;
//class Singleton
//{
//  public:
//    static Singleton* GetIncetance()
//    {
//      if(_a==nullptr)
//      {
//        _mutex.lock();
//        if(_a==nullptr)
//        {
//          _a=new Singleton();
//        }
//        _mutex.unlock();
//      }
//      return _a;
//    }
//    class Garbage
//    {
//      public:
//        ~Garbage()
//        {
//          if(Singleton::_a!=nullptr)
//            delete Singleton::_a;
//        }
//    };
//    Garbage ga;
//private:
//    Singleton(){}
//    Singleton(const Singleton&)=delete;
//    Singleton& operator=(const Singleton&)=delete;
//    static Singleton* _a;
//    static mutex _mutex;
//};
//Singleton::Garbage ga;
//Singleton* Singleton::_a=nullptr;
//mutex Singleton::_mutex;
int main()
{
  return 0;
}
