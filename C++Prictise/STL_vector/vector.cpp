#include"vector.h"
#include<string>
#include<time.h>

int main()
{
    MyVector<int> v;
    v.Insert(v.Begin(),0);
    v.PushBack(1);
    v.PushBack(2);
    v.Insert(v.End(),3);
    v.PushBack(3);
    v.PushBack(4);
    v.PushBack(5);
    v.PushBack(6);
    v.Insert(v.Begin()+3,9);
    v.Print(v);
    v.Erase(v.Begin());
    v.Print(v);

    cout<<"拷贝构造"<<endl;
    MyVector<int> v1(v);
    v1.Insert(v1.End(),100);
    v1.Print(v1);
    cout<<"capacity:"<<v1.Capacity()<<endl;
    cout<<"size:"<<v1.Size()<<endl;
    for(size_t i = 0;i < v1.Size();++i)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    v1.Print(v1);

    cout<<"赋值运算符重载"<<endl;
    MyVector<int> v3;
    v3 = v1;
    v3.Print(v3);

    v.Reserve(3);
    cout<<"capacity:"<<v.Capacity()<<endl;
    cout<<"size:"<<v.Size()<<endl;
    for(size_t i = 0;i < v.Size();++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl<<endl;
    v.Print(v);

    v.Resize(2);
    cout<<"capacity:"<<v.Capacity()<<endl;
    cout<<"size:"<<v.Size()<<endl;

    for(size_t i = 0;i < v.Size();++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    v.Print(v);
    cout<<endl;

    cout<<"Assgin"<<endl;
    v.Assgin(1,100);
    cout<<"capacity:"<<v.Capacity()<<endl;
    cout<<"size:"<<v.Size()<<endl;

    for(size_t i = 0;i < v.Size();++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    v.Print(v);
    return 0;
}
