#include"List.cpp"
#include<string>
int main()
{
    LinkList<int> L;
    L.PushBack(1);
    L.PushBack(2);
    L.PushBack(3);
    L.PushBack(4);
    L.PushFront(5);
    L.Show("尾插4个元素头插一个元素:");
    L.PopBack();
    L.Show("尾删一个元素:");
    L.PopFront();
    L.Show("头删一个元素:");
    LinkList<int> L1(L);
    L1.PushBack(6);
    L1.Show("拷贝构造:");
    LinkList<int> L3;
    L3 = L1;
    L3.Show("赋值运算符重载:");

    LinkList<string> s;
    s.PushBack("aaaaa");
    s.PushBack("bbbbbb");
    s.PushBack("ccccccc");
    s.PushBack("dddddddd");
    s.PushFront("wwwwwwwwwwwwwww");
    s.Show("尾插4个字符串,头插一个字符串:");
    s.PopBack();
    s.Show("尾删一个字符串:");
    s.PopFront();
    s.Show("头删一个字符串:");
    LinkList<string> s1(s);
    s1.PushBack("qqqqqqqqqqqqqqq");
    s1.Show("拷贝构造并尾插一个元素:");
    LinkList<string> s2;
    s2 = s1;
    s2.PushBack("qqqqqqqqqqqqqqq");
    s2.Show("赋值运算符重载并尾插:");
    return 0;
}
