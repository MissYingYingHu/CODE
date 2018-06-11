#include"vector.h"
using namespace std;

template<class T> 
Vector<T>::Vector()
    :_first(NULL)
    ,_finish(NULL)
    ,_endofstorage(NULL)
{}

template<typename T> 
size_t Vector<T>::Size() 
{
    return _finish - _first;
}

template<class T> 
size_t Vector<T>::Capacity()
{
    return _endofstorage - _first;
}

template<class T> 
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
    if(this != &v)
    {
        T* tmp = new T[v._finish - v._first];
        memcpy(tmp,v._first,sizeof(T)*(v._finish - v._first));
        delete[] _first;
        _first = tmp;
        _finish = _first + (v._finish - v._first);
        _endofstorage = _first + (v._finish - v._first);
    }
    return *this;
}

template<class T> 
Vector<T>::Vector(const Vector<T>& v)
{
    if(v._first != v._finish)
    {
       T* tmp = new T[v._finish - v._first];
       memcpy(tmp,v._first,sizeof(T)*(v._finish - v._first));
       _first = tmp;
       _finish = tmp + (v._finish - v._first);
       _endofstorage = tmp + (v._finish - v._first);
    }
}
 
template<class T>
void Vector<T>::PushBack(const T& value)
{
    Insert(Size(),value);
}

template<class T>
void Vector<T>::Expand(size_t n)
{
    if(_first == _finish)
    {
        _first = new T[2];
        _finish = _first;
        _endofstorage = _first + 2;
    }
    else
    {
        T* tmp = new T[n];
        int size = Size();
        int i = 0;
        for(;i < size;++i)
        {
            tmp[i] = _first[i];
        }
        delete[] _first;
        _first = tmp;
        _finish = _first + size;
        _endofstorage = _first + n;
    }
}

template<class T>
void Vector<T>::Insert(size_t pos,const T& value)
{
    if(Capacity() <= Size())
    {
        Expand(Capacity()*2);
    }
    T* end = _finish;
    for(; end > (_first + pos);--end)
    {
        *(end) = *(end - 1);
    }
    *(_first + pos) = value;
    ++_finish;
}

template<class T>
void Vector<T>::PopBack()
{
    Erase(Size() - 1);
}

template<class T>
void Vector<T>::Erase(size_t pos)
{
    if(_first == _finish)
    {
        return;
    }
    T* start = _first + pos;
    for(;start < _finish;++start)
    {
        *start = *(start + 1);
    }
    --_finish;
}

template<class T>
Vector<T>::~Vector()
{
    delete[] _first;
    _first = _finish = _endofstorage = NULL;
}

template<class T>
bool Vector<T>::Empty()
{
    return _first == _finish;
}

template<class T>
T& Vector<T>::Front()
{
    assert(_first != _finish);
    return _first[Size() - 1];
}

template<class T>
void Vector<T>::Show(const char* msg)
{
    cout<<msg;
    T* start = _first;
    while(start != _finish)
    {
        cout<<*start<<" ";
        ++start;
    }
    cout<<endl;
}
