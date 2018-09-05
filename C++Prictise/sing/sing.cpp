#include <iostream>
using namespace std;

//恶汉模式
template<class T>
class singletion
{
public:
  static T* GetInstance()
  {
      cout << "GetInstance"<<endl;
      return &value;
  }
private:
  static T value;
};
template<class T>
T singletion<T>::value = T();

int main()
{
  singletion<int> s;
  s.GetInstance();
  return 0;
}
