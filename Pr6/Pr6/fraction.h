#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cstdio>

//fraction.h
class Fraction
{
protected:
    int ch;		            //числитель неправильной дроби
    int zn;		            //знаменатель
    Fraction& shorten();    //функция сокращения дроби

public:
    Fraction();		                        //Конструктор без параметров
    Fraction(int cel, int ch, int zn = 1);  //Конструктор с параметрами
    Fraction(const Fraction &);             //Конструктор копирования
    ~Fraction();		                    //Деструктор

    Fraction &operator = (const Fraction &);
    friend bool operator == (const Fraction &, const Fraction &);

    //функции доступа
    int get_cel();	//вернуть значение целой части дроби
    int get_ch();	//вернуть значение числителя
    int get_zn();	//вернуть значение знаменателя

    Fraction & set_cel(int cl);	    //установить новое значение целой части дроби
    Fraction & set_chisl(int ch);	//установить новое значение числителя
    Fraction & set_znam(int zn);	// установить новое значение знаменателя

    //дополнительные функции
    Fraction sum(const Fraction &)const; 	//сумма текущей дроби с числом а
    Fraction sub(const Fraction &)const;	//разность  текущей дроби и числа а
    Fraction mul(const Fraction &)const; 	//произведение текущей дроби с числом а
    Fraction div(const Fraction &)const;	//деления текущей дроби на число a

    //функции сравнения
    int more(const Fraction  &)const; 	//сравнение текущей дроби с a на больше
    int less(const Fraction  &)const;	//сравнение текущей дроби с a на меньше
    int equals(const Fraction &)const;	//сравнение текущей дроби с a на равенство

    void show(int new_line_before = 0, int new_line_after = 1);  //показать дробь в формате: 3 5/8;

    Fraction operator-();
    Fraction operator+(const Fraction  &)const;
    Fraction operator-(const Fraction &)const;
    Fraction operator*(const Fraction &)const;
    Fraction operator/(const Fraction &)const;

    Fraction operator+( int);
    Fraction operator-(int);
    Fraction operator*(int);
    Fraction operator/(int);
    Fraction operator%(int);

    Fraction &operator++();
    Fraction operator++(int);

    Fraction &operator--();
    Fraction operator--(int);

    int operator>(const Fraction &);
    int operator<(const Fraction &);
    int operator>=(const Fraction &);
    int operator<=(const Fraction &);
    int operator==(const Fraction &);

    operator double();

    friend Fraction operator+(int, const Fraction &);
    friend Fraction operator-(int, const Fraction &);
    friend Fraction operator*(int, const Fraction &);
    friend Fraction operator/(int, const Fraction &);

    friend std::istream& operator>>(std::istream &, Fraction &);
    friend std::ostream& operator << (std::ostream &, const Fraction &);
};

#endif // FRACTION_H
