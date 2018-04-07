#pragma once
#include <iostream>
#include <string.h>
using namespace std;
//空字符串有空间，1个字节的空间
class String
{
public:
    //构造函数
    //处理空字符串的情况
    String()
        :_str(new char[1])
    {
        _str[0] = '\0';
        _size = 0;
        _capacity = 0;
    }
    //字符串非空的情况
    String(const char* str)
        :_str(new char[strlen(str) + 1])
        ,_size(strlen(str))
        ,_capacity(strlen(str))
    {
        strcpy(_str,str);
    }
    const char* c_str()//C语言形式的字符串，返回的是字符串的首指针，遇到\0结束，
                       //所以当创建对象时，如果不传参数，就会崩
    {
        return _str;
    }
    //或者直接一点，把上面的两种情况合二为一
//    String(const char* str = "")
//        :_str(new char[strlen(str) + 1])
//        ,_size_t(strlen(str))
//        ,_capacity(_size)
//        {}
//比较直观的拷贝构造
//    String(const String& s)
//    {
//        this->_str = new char[strlen(s._str) + 1];
//        this->_size = strlen(s._str);
//        this->_capacity = this->_size;
//        strcpy(this->_str,s._str);
//    }
     void Swap(String& tmp)
     {
         swap(_str,tmp._str);
         swap(_size,tmp._size);
         swap(_capacity,tmp._capacity);
     }
//比较简便的写法
//思想：
    String(const String& s)
        :_str(NULL) //因为创建出来的对象传过来的是随机值，当下面的交换后tmp就会交换为随机值，
        ,_size(0)
        ,_capacity(0) //而delete一个随机值就会出现问题，但是释放NULL就不会出现问题
    {
        String tmp(s._str);
        _str = tmp._str;
        _size = tmp._size;
        _capacity = tmp._capacity;
        //Swap(tmp);
       // swap(_str,tmp._str);
       // _size = s._size;
       // _capacity = s._capacity;
    }
//传统的赋值
//String& operator=(String& s)
//{
//    //如果自己给自己赋值，本来的那段空间就会变成随机值
//    if(this != &s)
//    {
//        char* str = new char[strlen(s._str) + 1];//先申请空间，再释放空间，因为放在下面可能会开辟失败，
//        delete[] _str;
//        _str = str;
//        strcpy(_str,s._str );
//        _size = s._size ;
//        _capacity = s._capacity ;
//    }
//        return *this;
//}
//方法2赋值 ----复用
    String& operator=(String& s)
    {
        if(&s != this)
        {
            delete [] _str;
             String tmp(s);
             Swap(tmp);
        }
         return *this;
    }

    void Expend(size_t len);
    void PushBack(char ch);
    void PushBack(const char* s);
    void PopBack();
    void PushFront(char ch);
    void PushFront(const char* s);
    void PopFront();
    void Insert(size_t pos,char ch);
    void Insert(size_t pos,const char* s);
    void Erase(size_t pos,size_t len);
    void Replace(char ch1,char ch2);
    void Replace(const char* sub1,const char* sub2);
    size_t Find(char ch);
    size_t Find(const char* s);
    String operator+(char ch);
    String operator+=(char ch);
    String operator+(const char* s);
    String& operator+=(const char* s);

    bool operator>(const String& s);
    bool operator>=(const String& s);
    bool operator<(const String& s);
    bool operator<=(const String& s);
    bool operator==(const String& s);
    bool operator!=(const String& s);
    ~String()
    {
        if(_str != NULL)
        {
            _size = 0;
            _capacity = 0;
            delete[] _str;
            _str = NULL;
        }
    }

private:
    char* _str;
    size_t _size;
    size_t _capacity;
};
