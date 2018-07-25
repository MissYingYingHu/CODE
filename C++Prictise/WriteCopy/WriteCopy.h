#pragma once
#include<iostream>
#include<string.h>
using namespace std;
class String
{
public:
    String(const char* s = "")
    :_str(new char[strlen(s) + 1])
    ,_pcount(new size_t[1])
    {
        strcpy(_str,s);
        *_pcount = 1;
    }

    String(const String& s)
  {
      _str = s._str;
      _pcount = s._pcount;
      ++(*_pcount);
  }
    ~String()
    {
        if((*_pcount) == 1)
        {
            delete[] _str;
            _str = NULL;
            _pcount = NULL;
        }
    }
    const char* c_str()
    {
        return _str;
    }
    void CopyOnwrite()
   {
       //如果当前的引用计数就是1，那么就可以直接对该字符串进行读写
       if((*_pcount) == 1)
       {
           return;
       }
       //当前的引用计数不为1，就要重新开辟一段空间，将字符串拷贝过来，减减引用计数的值
       char* tmp = new char[strlen(_str) + 1];
       size_t* p = new size_t[1];
       --(*_pcount);
       strcpy(tmp,_str);
       _str = tmp;
       _pcount = p;
       (*_pcount) = 1;
   }
    String& operator=(const String& s)
  {
      if(&s != this)
      {
          if(--(*_pcount) == 0)
          {
              delete[] _str;
              _pcount = NULL;
          }
          _str = s._str;
          _pcount = s._pcount;
          ++(*_pcount);
      }
      return *this;
  }
    char& operator[](size_t pos)
  {
      CopyOnwrite();
      return _str[pos];
  }
private:
    char* _str;
    size_t* _pcount;
};
