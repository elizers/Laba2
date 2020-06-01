#pragma once
#include <iostream>
#include <string>
#include "Utils.h"

class Date
{
private:
    int _day;
    int _month;
    int _year;

public:
    Date(int d = 1, int m = 1, int y = 1970);
    Date(const Date& date);

    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    void setDate(int day, int month, int year);

    friend int daysInYear(int year);
    friend bool isLeapYear(int year);
    friend int daysInMonth(int year, int month);

    friend std::ostream& operator<< (std::ostream& out, const Date& date);
    friend std::istream& operator>>(std::istream& in, Date& date);
    friend void input_date(Date& date);
    friend bool correct_date(int day, int month, int year);

    friend bool operator== (const Date& d1, const Date& d2);
    friend bool operator!= (const Date& d1, const Date& d2);
    friend bool operator< (const Date& d1, const Date& d2);
    friend bool operator> (const Date& d1, const Date& d2);
    friend bool operator<= (const Date& d1, const Date& d2);
    friend bool operator>= (const Date& d1, const Date& d2);
};