#pragma once
#include <stdio.h>

//声明,否则找不到
template<class T>
class Weak_Ptr;

template<class T>
class Share_Ptr
{
    friend class Weak_Ptr<T>;
public:
    Share_Ptr(T* _ptr)
        :ptr(_ptr)
         ,count(new int(1))
    {}
    ~Share_Ptr()
    {
        if(--(*count) == 0)
        {
            delete count;
            if(ptr)
            {
                delete ptr;
                printf("~Share_Ptr()\n");
            }
        }
    }
    T& operator*()
    {
        return *ptr;
    }
    T* operator->()
    {
        return ptr;
    }
    Share_Ptr(Share_Ptr<T>& s)
        :ptr(s.ptr)
         ,count(s.count)
    {
        ++(*count);
    }
    Share_Ptr<T>& operator=(Share_Ptr<T>& s)
    {
        //if(this != &s)
        if(ptr != s.ptr)
        {
            if(--(*count) == 0)
            {
                delete ptr;
                delete count;
            }
            ptr = s.ptr;
            count = s.count;
            ++(*count);
        }
        return *this;
    }
protected:
    T* ptr;
    int* count;
};

//数组的处理方式
//析构不同
template<class T>
class Share_Array
{
    friend class Weak_Ptr<T>;
public:
    Share_Array(T* _ptr)
        :ptr(_ptr)
         ,count(new int(1))
    {}
    ~Share_Array()
    {
        if(--(*count) == 0)
        {
            delete count;
            if(ptr)
            {
                delete[] ptr;
                printf("~Share_Array()\n");
            }
        }
    }
    T& operator[](size_t pos)
    {
        return ptr[pos];
    }
    Share_Array(Share_Array<T>& s)
        :ptr(s.ptr)
         ,count(s.count)
    {
        ++(*count);
    }
    Share_Array<T>& operator=(Share_Array<T>& s)
    {
        //if(this != &s)
        if(ptr != s.ptr)
        {
            if(--(*count) == 0)
            {
                delete ptr;
                delete count;
            }
            ptr = s.ptr;
            count = s.count;
            ++(*count);
        }
        return *this;
    }
protected:
    T* ptr;
    int* count;
};
template<class T>
class Weak_Ptr
{
    public:
        Weak_Ptr(const Share_Ptr<T>& s)
            :ptr(s.ptr)
        {}
        T& operator*()
        {
            return *ptr;
        }
        T* operator->()
        {
            return ptr;
        }
    private:
        T* ptr;
};

//struct ListNode
//{
//    Share_Ptr<ListNode> prev;
//    Share_Ptr<ListNode> next;
//    int data;
//
//    ListNode()
//        :prev(NULL)
//        ,next(NULL)
//    {}
//};
struct ListNode
{
    Weak_Ptr<ListNode> prev;
    Weak_Ptr<ListNode> next;
    int data;

    ListNode()
        :prev(NULL)
        ,next(NULL)
        ,data(int())
    {}
};

void TestCycle()
{
    //ListNode* n1 = new ListNode;
    //ListNdoe* n2 = new ListNode;
    //可能存在异常引起执行流乱跳不能正常释放资源
    //delete n1;
    //delete n2;
    
    //使用智能指针,但是存在循环引用的问题
    //Share_Ptr<ListNode> n1 = new ListNode; 
    //Share_Ptr<ListNode> n2 = new ListNode;
    Share_Ptr<ListNode> n1(new ListNode); 
    Share_Ptr<ListNode> n2(new ListNode);
    n1->next = n2;
    n2->prev = n1;
    
    //解决智能指针的循环引用的问题,增加一个weak_ptr弱指针去辅助智能指针,
    //只要在循环引用中不增加引用计数就可以避免这样的问题.
    
}
