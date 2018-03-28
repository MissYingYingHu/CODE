#pragma once

class Date
{
public:
    Date(int year = 1900 ,int month = 1 ,int day = 1 )
        :_year (year)
        ,_month (month)
        ,_day (day)
    {}
    bool IsInvalid();
    int GetCorrectDay(int _year,int _month);
    bool IsLeapYear(int _year)
    {
        return ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0);
    }
    void Print();
    Date& operator=(const Date& d);
    bool operator<(const Date& d);
    bool operator==(const Date& d);
    bool operator!=(const Date& d);
    bool operator<=(const Date& d);
    bool operator>(const Date& d);
    bool operator>=(const Date& d);
    Date operator++(int);   //后置++
    Date& operator++();     //前置++（默认是）
    Date operator--(int);
    Date& operator--();
    Date operator+(const int day);
    Date& operator+=(const int day);
    Date operator-(const int day);
    Date& operator-=(const int day);
    int operator-(Date& d);
private:
    int _year;
    int _month;
    int _day;
};
