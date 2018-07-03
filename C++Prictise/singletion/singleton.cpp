#include <iostream>
using namespace std;

template<class T>
class Singleton
{
public:
    static T* GetSingleton()
    {
        return &value;
    }
private:
    static T value;
};
template<class T>
T Singleton<T>::value = T();

int main()
{
    Singleton<int>::GetSingleton();
    return 0;
}
