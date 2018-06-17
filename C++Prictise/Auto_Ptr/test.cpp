#include <iostream>
#include<vector>
#include"Auto_Ptr.h"
#include"Scoped_Ptr.h"
#include"Share_Ptr.h"
using namespace std;

struct AA
{
    int a;
    int b;
};
void fun1(Auto_Ptr<AA> p)
{
    (void)p;
}
void fun()
{

    Auto_Ptr<AA> a(new AA);
    a->a = 10;
    a->b = 20;
    Auto_Ptr<AA> b(a);
    fun1(b); //由于管理权转移使b释放了,对象a就会变成野指针
    cout<<"a:"<<(*a).a<<endl;
    cout<<"a:"<<a.operator*().a<<endl;
    cout<<"b:"<<a->b<<endl;
    cout<<"b:"<<a.operator->()->b<<endl;
    cout<<"b"<<endl;
    vector<int> v;
    v.at(0);
    cout<<"释放arr"<<endl;
}
void Test_Scoped()
{
    Scoped_Ptr<AA> s(new AA);
    //Scoped_Ptr<AA> s1(s); //防止拷贝,编译不通过
}
void Test_SharePtr()
{
    Share_Ptr<AA> s(new AA);
    s->a = 10;
    s->b = 20;
    Share_Ptr<AA> s1(s);
    cout<<"s1->a:"<<s1->a<<endl;
    cout<<"s1->b:"<<s1->b<<endl;
}
int main()
{
    //fun();
    //Test_Scoped();
    //Test_SharePtr();
    TestCycle();
    return 0;
}
