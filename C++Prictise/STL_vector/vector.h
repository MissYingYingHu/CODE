#pragma once
#include <iostream>
#include<assert.h>
using namespace std;

template <class T>
class MyVector
{
public:
    typedef T* Iterator;
    typedef const T* ConstInterator;
    MyVector()
        :_first(NULL)
         ,_finish(NULL)
         ,_endofstorage(NULL)
    {}

    MyVector(const MyVector<T>& v)
        :_first(NULL)
         ,_finish(NULL)
         ,_endofstorage(NULL)
    {
        if(v.Size() > 0)
        {
            T* tmp = new T[v.Size()];
            for(size_t i = 0;i < v.Size();++i)
            {
                tmp[i] = v._first[i];
            }
            _first = tmp;
            _finish = _first + v.Size();
            _endofstorage = _first + v.Size();
        }
    }

    MyVector<T>& operator=(const MyVector<T>& v)
    {
        if(this != &v)
        {
            if(v.Size() > 0)
            {
                T* tmp = new T[v.Size()];
                for(size_t i = 0;i < v.Size();++i)
                {
                    tmp[i] = v._first[i];
                }
                delete[] _first;
                _first = tmp;
                _finish = _first + v.Size();
                _endofstorage = _first + v.Size();
            }
            else
            {
                _finish = _first;
            }
        }
        return *this;
    }

    ~MyVector()
    {
        if(_first)
        {
            delete[] _first;
            _first = _finish = _endofstorage = NULL;
        }
    }

    void Expand(size_t n)
    {
        if(Capacity() < n)
        {
            size_t size = Size();
            T* tmp = new T[n];
            size_t i = 0;
            for(i = 0;i < size;++i)
            {
                tmp[i] = _first[i];
            }
            delete[] _first;
            _first = tmp;
            _finish = _first + size;
            _endofstorage = _first + n;
        }
    }

    size_t Size() const
    {
        return _finish - _first;
    }

    size_t Capacity()
    {
        return _endofstorage - _first;
    }

    //只扩容
    void Reserve(size_t n)
    {
        if(n > Capacity())
        {
            Expand(n);
        }
    }


    //扩容并且初始化,但是已经存在的数据不会修改
    void Resize(size_t n,T value = T())
    {
        if(n <= Size())
        {
            //可能给的n小于Size(),这并没有减小容量,只是清除了数据.
            _finish = _first + n;
        }
        else
        {
            if(n > Capacity())
            {
                Expand(n);
            }
            //Resize()的范围可能没有大于Capacity()
            while(_finish < _first + n)
            {
                *_finish = value;
                ++_finish;
            }
        }
    }

    //会扩容并且会把原来的值给修改为给定的值
    void Assgin(size_t n,T value = T())
    {
        if(n > Capacity())
        {
            Expand(n);
        }
        T* b = _first;
        _finish = _first + n;
        T* e = _finish;
        while(b < e)
        {
            *b = value;
            ++b;
        }
    }

    void PushBack(const T& value)
    {
        if(_finish == _endofstorage)
        {
            size_t capacity = Capacity();
            capacity = capacity == 0 ? 3 : capacity*2;
            Expand(capacity);
        }
        *_finish = value;
        ++_finish;
    }

    void PopBack()
    {
        if(Size() == 0)
        {
            return;
        }
        --_finish;
    }

    Iterator Insert(Iterator pos,const T& value)
    {
        assert(pos <= End());
        if(_finish == _endofstorage)
        {
            size_t size = pos - _first;
            size_t capacity = Capacity();
            capacity = capacity == 0 ? 3 : capacity*2;
            Expand(capacity);
            //如果容量不够进行了扩容,可是POS是传进来的值,扩容后指向的还是以前那块空间的位置,
            //但是POS应该指向当前这块空间的相应的位置.
            pos = _first + size;
        }
        T* e = _finish;
        while(pos < e)
        {
            *e = *(e - 1);
            --e;
        }
        *pos = value;
        ++_finish;
        //size_t i = Size();
        //for(;i > (pos - Begin());--i)
        //{
        //    _first[i] = _first[i - 1];
        //}
        //*pos = value;
        //++_finish;
    }

    Iterator Erase(Iterator pos)
    {
        assert(pos < End());
        Iterator cur = pos;
        while(cur < End() - 1)
        {
            *cur = *(cur + 1);
            ++cur;
        }
        --_finish;
    }

    ConstInterator Begin() const
    {
        return _first;
    }

    ConstInterator End() const
    {
        return _finish;
    }

    Iterator Begin()
    {
        return _first;
    }

    Iterator End()
    {
        return _finish;
    }

    T& operator[](size_t pos)
    {
        assert(pos < Size());
        return _first[pos];
    }

    const T& operator[](size_t pos)const
    {
        assert(pos < Size());
        return _first[pos];
    }

    void Print(const MyVector<T>& V)
    {
        cout<<"打印数组"<<endl;
        MyVector<T>::ConstInterator it = V.Begin();
        while(it != V.End())
        {
            cout<<*it<<" ";
            ++it;
        }
        cout<<endl;
    }
private:
    Iterator _first;
    Iterator _finish;
    Iterator _endofstorage;
};
//vector不会缩容.
