#include"vector.cpp"
#include<string>
using namespace std;

void Test()
{
    Vector<int> v;
    cout<<v.Empty()<<endl;
    //cout<<v.Front()<<endl;
    v.Insert(0,1);
    v.Insert(0,2);
    v.Insert(0,3);
    v.Show("插入三个元素");
    v.PushBack(4);
    v.Show("尾插一个元素");
    cout<<v.Front()<<endl;
    Vector<int> v1;
    v1.Insert(0,1);
    v1.Insert(0,2);
    v1.Insert(0,4);
    v1.Show("插入三个元素");
    v1 = v;
    v1.Show("赋值v:");
    Vector<int> v2(v1);
    v2.Show("拷贝构造:");
    v.Erase(0);
    v.Show("删除首元素后");
    v.Erase(5);
    cout<<v.Empty()<<endl;
    v.Show("删除尾元素后");
    Vector<string> s;
    s.Show("尾插5个字符串:");
    s.PushBack("aaa");
    s.Show("尾插5个字符串:");
    s.PushBack("bbbb");
    s.PushBack("ccccc");
    s.PushBack("dddddd");
    s.PushBack("eeeeeee");
    s.Show("尾插5个字符串:");
    Vector<string> s1(s);
    s1.Show("拷贝构造:");
    Vector<string> s2;
    s2 = s;
    s2.Show("赋值:");
    cout<<s2.Front()<<endl;
}

int main()
{
    Test();
    return 0;
}

