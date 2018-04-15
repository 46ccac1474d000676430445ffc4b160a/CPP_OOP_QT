#ifndef MYSTRING_H
#define MYSTRING_H

#include <ostream>
#include <istream>

#include <cstring>

#include <iostream>

class String
{
private:
    int m_lenght;    //длина строки
    char *m_charRef;    //указатель на строку

    void resize(int n);

public:
    String();                   //Конструктор по умолчанию
    String(const char *s);  	//Конструктор с параметрами,  str - строка
    String(int n);              //Конструктор с параметрами, n-длина строки
    String(const String &s);  //Конструктор копирования
    ~String();                  //Деструктор

    //методы доступа
    const char *get_str() const;
    void get_str(char *s) const;
    int size() const;
    void clear();

    //функции-операторы над объектами типа String
    String operator+(const String &) const;
    String &operator=(const String &);
    String &operator+=(const String &);

    char &operator[](int);

    int operator==(const String &) const;
    int operator!=(const String &) const;
    int operator>(const String &) const;
    int operator>=(const String &) const;
    int operator<(const String &) const;
    int operator<=(const String &) const;

    //дружественные функции
    friend std::ostream &operator<<(std::ostream &, const String &);
    friend std::istream &operator>>(std::istream &, String &);

};


#endif // MYSTRING_H
