#pragma once
#include <iostream>
#include<assert.h>
#include<string.h>
#include<stddef.h>

template<class T>
class Vector
{
public:
    Vector();
    Vector(const Vector<T>& v);
    size_t Size();
    size_t Capacity();
    void Expand(size_t n);
    Vector<T>& operator=(const Vector<T>& v);
    void PushBack(const T& value);
    void PopBack();
    void Insert(size_t pos,const T& value);
    void Erase(size_t pos);
    ~Vector();
    bool Empty();
    T& Front();
    void Show(const char* msg);
protected:
    T *_first;
    T *_finish;
    T *_endofstorage;
};
