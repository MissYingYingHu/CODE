#pragma once

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

