#include <iostream>
using namespace std;

//懒汉模式
template<class T>
class singleton
{
public:
    static T* GetSingleton()
    {
        if(value == NULL)
        {
            value = new T();
        }
        return value;
    }
private:
    static T* value;
};
template<class T>
T* singleton<T>::value = NULL;

int main()
{
    singleton<int>::GetSingleton();
    return 0;
}


//如果在多线程的模式下是不安全的,所以就需要加锁
template<class T>
class singleton
{
public:
    static T* GetSingleton()
    {
        if(value == NULL)    //这样就只有为空才会进来进行加锁解锁(这样就不会频繁获取锁)
        {
            lock(); //这是一句伪代码
            //如果在这儿加锁,所有的线程到这儿都会先加锁(这也是一种消耗),再判断,这样就会造成效率低.所以在这儿之前再进行一次判断
            //但是在这儿加锁也会满足线程安全
            if(value == NULL)
            {
                value = new T();
            }
            unlock();  
        }
        return value;
    }
private:
    static volatile  T* value;  //加上volatile为了防止编译器过度优化
};
template<class T>
volatile T* singleton<T>::value = NULL;

int main()
{
    return 0;
}
