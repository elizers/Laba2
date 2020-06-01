#include "Date.h"
#include <iostream>
#include <string>

int daysInYear(int year)
{
    if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400)))
    {
        return 366;
    }
    return 365;
}

bool isLeapYear(int year)
{
    return daysInYear(year) == 366;
}

int daysInMonth(int year, int month)
{
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (isLeapYear(year))
    {
        days[1] = 29;
    }
    return days[month - 1];
}

Date::Date(int d, int m, int y)
{
    setDate(d, m, y);
}

Date::Date(const Date& date)
{
    setDate(date._day, date._month, date._year);
}

int Date::getDay() const
{
    return _day;
}

int Date::getMonth() const
{
    return _month;
}

int Date::getYear() const
{
    return _year;
}

int get_number_from_stringdate(std::string& str)
{
    int position_point = str.find('.');
    if (position_point != -1)
    {
        std::string tmp_substr = str.substr(0, position_point);
        str.erase(0, position_point + 1);
        return str_to_val<int>(tmp_substr);
    }
    return 0;
}

void Date::setDay(int day)
{
    this->_day = day;
}

void Date::setMonth(int month)
{
    this->_month = month;
}

void Date::setYear(int year)
{
    this->_year = year;
}

void Date::setDate(int day, int month, int year)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

std::ostream& operator<< (std::ostream& out, const Date& date)
{
    out << date._day << '.' << date._month << '.' << date._year << std::endl;
    return out;
}

bool correct_date(int day, int month, int year)
{
    return (year > 1900 && year < 2100) && (month >= 1 && month <= 12) && (day > 0 && day <= daysInMonth(year, month));
}

std::istream& operator>> (std::istream& in, Date& date)
{
    std::string tmp_date;
    getline(in, tmp_date);
    tmp_date = take_field(tmp_date);
    int day, month, year;
    day = get_number_from_stringdate(tmp_date);
    month = get_number_from_stringdate(tmp_date);
    year = str_to_val<int>(tmp_date);
    if (!correct_date(day, month, year))
    {
        in.setstate(std::ios::failbit);
    }
    date.setDate(day, month, year);
    return in;
}

void input_date(Date& date)
{
    std::string tmp_date;
    std::getline(std::cin, tmp_date);
    int day, month, year;
    day = get_number_from_stringdate(tmp_date);
    month = get_number_from_stringdate(tmp_date);
    year = str_to_val<int>(tmp_date);
    if (!correct_date(day, month, year))
    {
        std::cout << "Некорректное значение даты! Повторите ввод: ";
        input_date(date);
    }
    else
    {
        date.setDate(day, month, year);
    }
}

bool operator== (const Date& d1, const Date& d2)
{
    return ((d1._day == d2._day) && (d1._month == d2._month) && (d1._year == d2._year));
}

bool operator!= (const Date& d1, const Date& d2)
{
    return !(d1 == d2);
}

bool operator< (const Date& d1, const Date& d2)
{
    if (d1._year < d2._year)
        return true;
    if (d1._year > d2._year)
        return false;
    if (d1._month < d2._month)
        return true;
    if (d1._month > d2._month)
        return false;
    return d1._day < d2._day;
}

bool operator> (const Date& d1, const Date& d2)
{
    return (!(d1 < d2) && !(d1 == d2));
}

bool operator<= (const Date& d1, const Date& d2)
{
    return ((d1 < d2) || (d1 == d2));
}

bool operator>= (const Date& d1, const Date& d2)
{
    return ((d1 > d2) || (d1 == d2));
}