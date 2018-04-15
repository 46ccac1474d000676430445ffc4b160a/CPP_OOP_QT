#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <ostream>
#include <istream>

class IntVector
{
    int *m_dataRef;     //указатель на массив
    int m_length;       //длина массива
    int m_error;        //код ошибки
    static int count;   //количество созданных объектов типа IntVector

public:
    IntVector();                    //Конструктор без параметров
    IntVector(int n);               //Конструктор с параметрами, n – длина массива
    IntVector(const IntVector &v);   //Конструктор копирования
    ~IntVector();                   //Деструктор

    int size();
    int get_error();
    static int get_count();

    int min();
    int max();
    double average();
    int median();
    double dispersion();
    double rms();
    void fill();
    void sort();

    IntVector  operator-();

    IntVector operator+(const IntVector &)const;
    IntVector operator-(const IntVector &)const;
    IntVector operator*(const IntVector &)const;
    IntVector operator/(const IntVector &)const;

    IntVector operator+(int a)const;
    IntVector operator-(int a)const;
    IntVector operator*(int a)const;
    IntVector operator/(int a)const;

    IntVector &operator++();
    IntVector operator++(int);

    IntVector &operator--();
    IntVector operator--(int);

    int &operator[](int index);

    void *operator new(size_t size);
    void operator delete (void* addr);

    IntVector &operator=(const IntVector &);
    int operator==(const IntVector &)const;
    int operator!=(const IntVector &)const;
    int operator>(const IntVector &)const;
    int operator>=(const IntVector &)const;
    int operator<(const IntVector &)const;
    int operator<=(const IntVector &)const;

    friend IntVector operator+(int a, const IntVector &);
    friend IntVector operator-(int a, const IntVector &);
    friend IntVector operator*(int a, const IntVector &);
    friend IntVector operator/(int a, const IntVector &);
    friend std::ostream&  operator<<(std::ostream&, const IntVector &);
    friend std::istream&  operator>>(std::istream&, IntVector &);

};

#endif // INTVECTOR_H
