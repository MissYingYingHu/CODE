#pragma once
#include<iostream>
#include<string.h>
using namespace std;
//将引用计数放在字符串的头部
class String2
{
public:
    int& GetRefCount()
    {
        return *((int*)(_str - 4));
    }
    String2(const char* s = "")
        :_str(new char[strlen(s) + 5])//多开辟4个字节，是因为要给引用计数留够位置
    {
        _str += 4;
        strcpy(_str,s);
		GetRefCount() = 1;
    }
    ~String2()
    {
        if(--GetRefCount() == 0)
        {
            delete[] (_str - 4);
            _str = NULL;
        }
    }
    const char* c_str()
    {
        return _str;
    }

    String2(const String2& s)
    {
        _str = s._str;
        ++GetRefCount();
    }
    String2& operator=(const String2& s)
    {
        if(s._str != _str)
        {
            if(--GetRefCount() == 0)
            {
                delete[] (_str - 4);
                _str = NULL;
            }
            _str = s._str;
            ++GetRefCount();
        }
        return *this;
    }
    void WriteOnCopy()
    {
        if(GetRefCount() == 1)
        {
            return;
        }
		--GetRefCount();
        char* tmp = new char[strlen(_str) + 5];
        tmp += 4;
        strcpy(tmp,_str);
		_str = tmp;
		GetRefCount() = 1;
    }
    char& operator[](size_t pos)
    {
        WriteOnCopy();
        return _str[pos];
    }

private:
    char* _str;
};
