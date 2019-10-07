//#include<iostream> 
//#include<algorithm>
//#include<mutex>
////懒汉模式
//class Singleton
//{
//  public:
//    static Singleton* GetIntance()
//    {
//      if(_a==NULL)
//      {
//        _mutex.lock();
//        if(_a==NULL)
//        {
//          _a=new Singleton;
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
//          if(Singleton::_a!=NULL)
//            delete Singleton::_a;
//        }
//    };
//    static Garbage _g;
//  private:
//    static Singleton* _a;
//    static std::mutex _mutex;
//    Singleton(){};
//    Singleton(const Singleton&)=delete;
//    Singleton& operator=(const Singleton&)=delete;
//};
//Singleton* Singleton::_a=NULL;
//std::mutex Singleton::_mutex;
//Singleton::Garbage _g;
////饿汉模式
//class Singleton
//{
//  public:
//    static Singleton* GteIntace()
//    {
//      return &_a;
//    }
//  private:
//    static Singleton _a;
//    Singleton(){}
//    Singleton(const Singleton&)=delete;
//    Singleton& operator=(const Singleton&)=delete;
//};
//Singleton Singleton::_a;
//void AdjustDown(int arr[],int sz,int root)
//{
//  int i=2*root+1;
//  if(i>=sz)
//    return;
//  int j=2*root+2;
//  int m=i;
//  if(j<sz && arr[m]<arr[j])
//    m=j;
//  if(arr[root]<arr[m])
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
//  int arr[]={12,22,32,44,1,2,43,5,32,54,65,31,0};
//  int sz=sizeof(arr)/sizeof(int);
//  HeapSort(arr,sz);
//  for(int i=0;i<sz;i++)
//  {
//    std::cout<<arr[i]<<" ";
//  }
//  std::cout<<std::endl;
//  return 0;
//}
