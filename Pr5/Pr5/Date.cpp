#include "Date.h"

const char Date::monthes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() :
    days(std::time(nullptr) / 86400 + 1)
{
}

Date::Date(int y, int m, int d) :
    days(to_days(y, m, d))
{
}

Date::~Date()
{
}

long Date::to_days(int day, int month, int year)
{
    long int counter = 0;

    for (int i= 1970; i < year; i++)
        if (i%4==0 && (i%100!=0 || i%400==0)) counter += 366;
        else counter += 365;

    for (int i = 0; i < month-1; i++)
        counter += monthes[i];

    if ( (month > 2) && (year%4==0 && (year%100!=0 || year%400==0)) ) counter++;

    counter += day;

    return counter;
}

void Date::from_days(long days, int& year, int& month, int& day)
{
    year = 1970;

    while (days > 365)
    {
        if (year%4==0 && (year%100!=0 || year%400==0)) days -= 366;
        else days -= 365;
        year++;
    }

    for  (month = 1; days > monthes[month-1]; days -= monthes[month-1], month++);

    if ( month > 2 && (year%4==0 && (year%100!=0 || year%400==0)) ) days--;

    day = days;
}

int Date::get_year()
{
    int year = 1970, days = this->days;

    while (days > 365)
    {
        if (year%4==0 && (year%100!=0 || year%400==0)) days -= 366;
        else days -= 365;
        year++;
    }

    return year;
}

int Date::get_month()
{
    int year = 1970, days = this->days, month;

    while (days > 365)
    {
        if (year%4==0 && (year%100!=0 || year%400==0)) days -= 366;
        else days -= 365;
        year++;
    }

    for(month = 1; days > monthes[month-1]; days -= monthes[month-1], month++);

    return month;
}

int Date::get_day()
{
    int year = 1970, days = this->days, month;

    while (days > 365)
    {
        if (year%4==0 && (year%100!=0 || year%400==0)) days -= 366;
        else days -= 365;
        year++;
    }

    for(month = 1; days > monthes[month-1]; days -= monthes[month-1], month++);

    if ( month > 2 && (year%4==0 && (year%100!=0 || year%400==0)) ) days--;

    return days;
}

void Date::set_year(int year)
{
    days = to_days(get_day(), get_month(), year);
}

void Date::set_month(int month)
{
    days = to_days(get_day(), month, get_year());
}

void Date::set_day(int day)
{
    days = to_days(day, get_month(), get_year());
}

long Date::diffDate(const Date& d)
{
    return days - d.days;
}

int Date::eguals(const Date &d) const
{
    return !(days - d.days);
}

int Date::more(const Date &d) const
{
    return days > d.days;
}

int Date::less(const Date &d) const
{
    return days < d.days;
}

void Date::show(int type)   //type: 1–15.12.2016; 2–15 December 2016; 3–12.15.2016
{
    int year, month, day;
    Date::from_days(days, year, month, day);

    switch (type)
    {
        case 1:
        {
            std::cout << day << '.' << month << '.' << year;
        } break;

        case 2:
        {
            const char *monthes[] = {  "January", "February",
                                        "March", "April", "May",
                                        "June", "July", "August",
                                        "September", "October", "November",
                                        "December" };
            std::cout << day << ' ' << monthes[month-1] << ' ' << year;
        } break;

        case 3:
        {
            std::cout << month << '.' << day << '.' << year;
        } break;
    }
}

std::ostream& operator << (std::ostream &o, const Date &d)
{
    int year, month, day;
    Date::from_days(d.days, year, month, day);
    return o << day << '.' << month << '.' << year;
}

