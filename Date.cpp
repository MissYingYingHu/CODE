#include <iostream>
using namespace std;
#include"Date.h"
bool Date::IsInvalid()
{
    if(this->_year < 0 || this->_month < 0 || this->_month > 13 || this->_day < 0 || this ->_day > GetCorrectDay(this->_year,this->_month))
    {
        return false;
    }
    return true;
}
int Date::GetCorrectDay(int year,int month)
{
    int m_day = 0;
    int day[13] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};
    if(month == 2 && IsLeapYear(year))
    {
        m_day = 29;
    }
    else
    {
        m_day = day[month];
    }
    return m_day;
}
void Date::Print()
{
    cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
}
Date& Date::operator=(const Date& d)
{
    _year = d._year ;
    _month = d._month ;
    _day = d._day ;
    return *this;
}
bool Date::operator<(const Date& d)
{
    if(_year < d._year || (_year == d._year && _month < d._month) || (_year == d._year && _month == d._month && _day < d._day ))
    {
        return true;
    }
    return false;
}
bool Date::operator==(const Date& d)
{
    if(_year == d._year && _month == d._month && _day == d._day)
    {
        return true;
    }
    return false;
}
bool Date::operator!=(const Date& d)
{
    if((*this == d) == false)
    {
        return true;
    }
    return false;
}
bool Date::operator<=(const Date& d)
{
    if(*this < d || *this == d)
    {
        return true;
    }
    return false;
}
bool Date::operator>(const Date& d)
{
    if(!(*this < d) && !(*this == d))
    {
        return true;
    }
    return false;
}
bool Date::operator>=(const Date& d)
{
    if((*this > d) || (*this == d))
    {
        return true;
    }
    return false;
}
Date Date::operator+(const int day)
{
    if(day < 0)
    {
        return (*this - (-day));
    }
    Date tmp(*this);
    tmp._day  += day;
    while(tmp.IsInvalid() == false)
    {
        if(tmp._month > 12)
        {
           tmp. _year += 1;
           tmp._month = 1;
        }
        int m_day = GetCorrectDay(tmp._year,tmp._month);
        tmp._day -= m_day;
        ++tmp._month;
    }
    return tmp;
}
Date& Date::operator+=(const int day)
{
    *this = *this + day;
    return *this;
}
Date Date::operator-(const int day)
{
    if(day < 0)
    {
        return (*this + (-day));
    }
    Date tmp(*this);
    tmp._day -= day;
    while(tmp.IsInvalid() == false )
    {
        if(tmp._month <= 1)
        {
            tmp._month = 12;
            tmp._year -= 1;
        }
        int m_day = GetCorrectDay(tmp._year,tmp._month - 1);
        tmp._day -= m_day;
        --tmp._month;
    }
    return tmp;
}
Date& Date::operator-=(const int day)
{
    *this = *this - day;
    return *this;
}
Date Date::operator++(int)
{
    Date tmp(*this);
    *this += 1;
    return tmp;
}
Date& Date::operator++()
{
    *this += 1;
    return *this;
}
Date Date::operator--(int)
{
    Date tmp(*this);
    *this -= 1;
    return tmp;
}
Date& Date::operator--()
{
    *this -= 1;
    return *this;
}
int Date::operator-(Date& d)
{
    int count = 0;
    while(*this != d)
    {
        if(*this > d)
        {
            ++d;
            ++count;
        }
        else if(*this < d)
        {
            ++(*this);
            ++count;
        }
    }
    return count;
}
int main()
{
    Date d(2018,3,27);
    Date d1(2018,3,3);
    cout<<(d == d1)<<endl;
    cout<<(d < d1)<<endl;
    cout<<(d <= d1)<<endl;
    cout<<(d > d1)<<endl;
    cout<<(d >= d1)<<endl;
    cout<<(d1 - d)<<endl;
    d = d + 430;
    d.Print();
    --d;
    d.Print();
    d++;
    d.Print();
    d--;
    d.Print();
    d = d + 2;
    d1 = d1 + 30;
    d.Print();
    d1.Print();
    return 0;
}
