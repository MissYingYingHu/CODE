#include <iostream>
using namespace std;

template<class T>
class singletion
{
public:
  static T* GetInstance()
  {
    if(value == NULL)
    {
      cout<<"GetInstance"<<endl;
      value = new T();
    }
    return value;
  }
private:
  static T* value;
};
template<class T>
T* singletion<T>::value = NULL;

//改为线程安全模式
template<class T>
class singletion1
{
public:
  static T* GetInstance()
  {
    if(value == NULL)
    {
      //lock
      if(value == NULL)
      {
        value = new T();
      }
      //unlcok
    }
    return value;
  }
private:
   volatile static T* value;
};
int main()
{
  singletion<int> s;
  s.GetInstance();
  return 0;
}
