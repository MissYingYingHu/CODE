#include"List.h"
#include"List.cpp"
using namespace std;

template<class T,template<class T> class Container>
//template<class T,class Container>
class Queue
{
public:
    void Push(const T& value)
    {
        con.PushBack(value);
    }
    void Pop()
    {
        con.PopFront();
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
    Queue<int,LinkList> q;
//    Queue<int,LinkList<int> > q;
    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.Push(4);
    cout<<q.Empty()<<endl;
    cout<<q.Top()<<" ";
    q.Pop();
    cout<<q.Top()<<" ";
    q.Pop();
    cout<<q.Top()<<" ";
    q.Pop();
    cout<<q.Top()<<" "<<endl;
    q.Pop();
    cout<<q.Empty()<<endl;
    return 0;
}
