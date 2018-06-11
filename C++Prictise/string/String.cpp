#include"String.h"
#include<assert.h>

void String:: Expend(size_t len)
{
    char* str = new char[len + 1];
    strcpy(str,_str);
    delete[] _str;
    _str = str;
    _capacity = len;
}
void String:: PushBack(char ch)
{
    if(this->_size >= this->_capacity)
    {
        Expend(_capacity*2); 
    }
    _str[_size++] = ch;
    _str[_size] = '\0';
}
void String:: PushBack(const char* s)
{
    if((_size + (strlen(s))) >= _capacity)
    {
        Expend(strlen(s)+_size);
    }
    strcpy(_str + _size,s);
    _size += strlen(s);
}
void String:: PopBack()
{
    if(this->_size > 0)
    {
       this->_str[_size - 1] = '\0';
       --this->_size;
    }
}
void String::PushFront(char ch)
{
    if(_size >= _capacity)
    {
        Expend(_capacity * 2);
    }
    int i = _size;
    for(;i >= 0;--i)
    {
        _str[i] = _str[i - 1];
    }
    _str[0] = ch;
    _size += 1;
}
void String::PushFront(const char* s)
{
    int len = strlen(s);
    if(_size > _capacity)
    {
        Expend(_size + len);
    }
    int i = _size;
    for(;i >= 0;--i)
    {
        _str[i + len] = _str[i];
    }
    strncpy(_str,s,len);
    _size += len;
}
void String::PopFront()
{
    if(_size < 1)
    {
        return;
    }
    size_t i = 0;
    for(;i < _size;++i)
    {
        _str[i] = _str[i + 1];
    }
    _size -= 1;
}
void String::Insert(size_t pos,char ch)
{
    assert(pos <=  _size);
    if(_size >= _capacity)
    {
        Expend(_capacity * 2);
    }
    int i = _size;
    for(;i >= (int)pos;--i)
    {
        _str[i] = _str[i - 1];
    }
    _str[pos] = ch;
    _size += 1;
}
void String::Insert(size_t pos,const char* s)
{
    assert(pos <= _size);
    int len = strlen(s);
    if(_size + len >= _capacity)
    {
        Expend(_size + len);
    }
    int i = _size;
    for(;i >= (int)pos;--i)
    {
        _str[i + len] = _str[i];
    }
    strncpy(_str+pos,s,len);
    _size += len;
}
void String::Erase(size_t pos,size_t len)
{
    assert(pos < _size);
    if(pos + len >= _size)
    {
        _str[pos] = '\0';
        _size = pos;
        return;
    }
    int i = pos;
    for(;i <= (int)_size;++i)
    {
        _str[i] = _str[i + len]; 
    }
    _size -= len;
}
size_t String::Find(char ch)
{
    if(_size < 1)
    {
        return (size_t)-1;
    }
    size_t i = 0;
    for(;i < _size;++i)
    {
        if(_str[i] == ch)
        {
            return i + 1;
        }
    }
    //如果找不到就返回-1（无穷大）
    return (size_t)-1;
}
size_t String::Find(const char* s)
{
    assert(s != NULL);
    if(_size < 1)
    {
        return (size_t)-1;
    }
    int len = strlen(s);
    size_t i = 0;
    int j = 0;
    for(;i < _size;++i)
    {
        if(_str[i] == s[0])
        {
            j = 0;
            for(;j < len;++j,++i)
            {
                if(_str[i] != s[j])
                {
                    i = i - j;
                    break;
                }
            }
            if(j == len )
            {
                return i - j;
            }
        }
    }
    return -1;
}
void String::Replace(char ch1,char ch2)
{
    size_t i = 0;
    for(;i < _size;++i)
    {
        if(_str[i] == ch1)
        {
            _str[i] = ch2;
        }
    }
}
void String::Replace(const char* sub1,const char* sub2)
{
    assert(sub1 != NULL && sub2 != NULL);
    size_t pos = Find(sub1);
    int len1 = strlen(sub1);
    int len2 = strlen(sub2);
    if(pos < _size)
    {
        if(len2 == len1)
        {
            strncpy(_str+pos,sub2,len1);
        }
        else if(len1 < len2)
        {
            Insert(pos+len1,sub2);
            Erase(pos,len1);
        }
        else
        {
            Insert(pos,sub2);
            Erase(pos + len2,len2);
        }
    }
}
bool String:: operator>(const String& s)
{
    char *s1 = _str;
    char *s2 = s._str;
    while(*s1 && *s2)
    {
        if(*s1 > *s2)
        {
            return true;
        }
        else if(*s1 < *s2)
        {
            return false;
        }
        else
        {
            ++s1;
            ++s2;
        }
    }
    if(*s1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool String:: operator==(const String& s)
{
    char *s1 = _str;
    char *s2 = s._str;
    if(_size != s._size)
    {
        return false;
    }
    while(*s1 && *s2)
    {
        if(*s1 != *s2)
        {
            return false;
        }
        ++s1;
        ++s2;
    }
    return true;
}
bool String:: operator>=(const String& s)
{
    if(*this == s ||  *this > s)
    {
        return true;
    }
    return false;
}
bool String:: operator<(const String& s)
{
    if((*this > s)==false && (*this == s)==false)
    {
        return true;
    }
    return false;
}
bool String:: operator<=(const String& s)
{
    if(*this > s)
    {
        return false;
    }
    return true;
}
bool String:: operator!=(const String& s)
{
    if(*this == s)
    {
        return false;
    }
    return true;
}
String String:: operator+(char ch)
{
    String tmp(*this);
    tmp.PushBack(ch);
    return *this;
}
String String:: operator+=(char ch)
{
    this->PushBack(ch);
    return *this;
}
String String::operator+(const char* s)
{
    String tmp(*this);
    tmp.PushBack(s);
    return *this;
}
String& String::operator+=(const char* s)
{
    this->PushBack(s);
    return *this;
}
int main()
{
    String str("hello");
    String str1("hello 3244");
    str1.Replace("hello","986");
    cout<<str1.c_str()<<endl;
    //cout<<(str == str1)<<endl;
    //cout<<(str != str1)<<endl;
    //cout<<(str > str1)<<endl;
    //cout<<(str >= str1)<<endl;
    //cout<<(str < str1)<<endl;
    //cout<<(str <= str1)<<endl;
    return 0;
}
