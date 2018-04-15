#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cstdio>

//fraction.h
class Fraction
{

//protected:
    int ch;		            //числитель неправильной дроби
    int zn;		            //знаменатель
    Fraction& shorten();    //функция сокращения дроби

public:
    Fraction();		                        //Конструктор без параметров
    Fraction(int cel, int ch, int zn = 1);  //Конструктор с параметрами
    Fraction(const Fraction &x);            //Конструктор копирования
    ~Fraction();		                    //Деструктор

    Fraction &operator = (const Fraction &x);
    friend bool operator == (const Fraction &x, const Fraction &y);

    //функции доступа
    int get_cel();	//вернуть значение целой части дроби
    int get_ch();	//вернуть значение числителя
    int get_zn();	//вернуть значение знаменателя

    Fraction & set_cel(int cl);	    //установить новое значение целой части дроби
    Fraction & set_chisl(int ch);	//установить новое значение числителя
    Fraction & set_znam(int zn);	// установить новое значение знаменателя

    //дополнительные функции
    Fraction sum(const Fraction &a)const; 	//сумма текущей дроби с числом а
    Fraction sub(const Fraction &a)const;	//разность  текущей дроби и числа а
    Fraction mul(const Fraction &a)const; 	//произведение текущей дроби с числом а
    Fraction div(const Fraction &a)const;	//деления текущей дроби на число a

    //функции сравнения
    int more(const Fraction  &a)const; 	//сравнение текущей дроби с a на больше
    int less(const Fraction  &a)const;	//сравнение текущей дроби с a на меньше
    int equals(const Fraction &a)const;	//сравнение текущей дроби с a на равенство

    void show(int new_line_before = 0, int new_line_after = 1);  //показать дробь в формате: 3 5/8;

    friend std::ostream& operator << (std::ostream &o, const Fraction &x);
};

#endif // FRACTION_H
