#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>


//date.h
class Date{
protected:
    long days;  //количество дней относительно 01.01.1970

public:
    static const char monthes[12];

    static long to_days(int d, int m, int y);
    static void from_days(long days, int &y,int &m,int &d);

    Date();	//Конструктор без параметров, создает объект
            // используя параметры системной даты
            // (год, месяц и день месяца).
    Date(int y, int m, int d);	//Конструктор с параметрами
    ~Date();			        //Деструктор

    int get_year();
    int get_month();
    int get_day();

    void set_year(int year);
    void set_month(int month);
    void set_day(int day);

    long diffDate( const Date & d);   	//возвращает количество дней между текущим
                                        //объектом и d.

    int eguals(const Date &)const; 	//равенство двух объектов Date
    int more(const Date &)const; 	//сравнение двух объектов Date на больше
    int less(const Date &)const; 	//сравнение двух объектов Date на меньше

    void show (int type); 	//type: 1–15.12.2016; 2–15 December 2016; 3–12.15.2016

    friend std::ostream& operator << (std::ostream& o, const Date &d);

};

#endif // DATE_H
