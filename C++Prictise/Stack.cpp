#include"vector.h"
#include"vector.cpp"
using namespace std;
template<class T,template<class T> class Container> //模板的模板参数
//template<class T,class Container>  //适配器模式
class Stack
{
public:
    void Push(const T& value)
    {
        con.PushBack(value);
    }
    void Pop()
    {
        con.PopBack();
    }
    T& Top()
    {
        con.Front();
    }
    bool Empty()
    {
        con.Empty();
    }
protected:
    Container<T> con;
//    Container con;
};

int main()
{
    Stack<int,Vector> s;  //可以避免少出错
//    Stack<int,Vector<int> > s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Push(5);
    cout<<s.Empty()<<endl;
    cout<<s.Top()<<" ";
    s.Pop();
    cout<<s.Top()<<" ";
    s.Pop();
    cout<<s.Top()<<" ";
    s.Pop();
    cout<<s.Top()<<" ";
    s.Pop();
    cout<<s.Top()<<endl;
    s.Pop();
    s.Pop();
    cout<<s.Empty()<<endl;
    cout<<s.Empty()<<endl;
    Stack<string,Vector> s1;
    s1.Push("aaaa");
    s1.Push("BBBB");
    s1.Push("CCCC");
    s1.Push("DDDD");
    s1.Push("EEEE");
    cout<<s1.Empty()<<endl;
    cout<<s1.Top()<<" ";
    s1.Pop();
    cout<<s1.Top()<<" ";
    s1.Pop();
    cout<<s1.Top()<<" ";
    s1.Pop();
    cout<<s1.Top()<<" ";
    s1.Pop();
    cout<<s1.Top()<<endl;
    s1.Pop();
    cout<<s1.Empty()<<endl;
    cout<<s1.Empty()<<endl;
    return 0;
}
