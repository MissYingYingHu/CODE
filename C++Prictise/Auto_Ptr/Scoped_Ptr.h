#pragma once
#include<stdio.h>

template<class T>
class Scoped_Ptr
{
public:
    Scoped_Ptr(T* _ptr)
        :ptr(_ptr)
    {}
    ~Scoped_Ptr()
    {
        if(ptr)
        {
            delete ptr;
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
private:
    Scoped_Ptr(Scoped_Ptr<T>& _ptr);
    Scoped_Ptr<int>& operator=(Scoped_Ptr<T>& _ptr);
protected:
    T* ptr;
};

//防拷贝智能指针也有自己的数组实现
template<class T>
class Scoped_Array
{
public:
    Scoped_Array(T* _ptr)
        :ptr(_ptr)
    {}
    ~Scoped_Array()
    {
        if(ptr)
        {
            delete ptr;
        }
    }
    T& operator[](size_t pos)
    {
        return ptr[pos];
    }
private:
    Scoped_Array(Scoped_Array<T>& _ptr);
    Scoped_Array<int>& operator=(Scoped_Array<T>& _ptr);
protected:
    T* ptr;
};

