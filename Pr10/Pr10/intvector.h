#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <ostream>
#include <istream>
#include <cstdlib>
#include <stdexcept>

class IntVector
{
    int m_size;       //длина массива
    int *m_dataRef;     //указатель на массив
    static int count;   //количество созданных объектов типа IntVector

public:
    IntVector();                    //Конструктор без параметров
    IntVector(int n);               //Конструктор с параметрами, n – длина массива
    IntVector(const IntVector &v);   //Конструктор копирования
    ~IntVector();                   //Деструктор

    int size() const;
    static int get_count();

    int min() const;
    int max() const;
    double average() const;
    int median() const;
    double dispersion() const;
    double rms();
    void fill(int from, int to);
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

    int &operator[](int index) const;

    void *operator new(size_t size);
    void operator delete (void* addr);

    IntVector &operator=(const IntVector &);
    bool operator==(const IntVector &)const;
    bool operator!=(const IntVector &)const;
    bool operator>(const IntVector &)const;
    bool operator>=(const IntVector &)const;
    bool operator<(const IntVector &)const;
    bool operator<=(const IntVector &)const;

    friend IntVector operator+(int a, const IntVector &);
    friend IntVector operator-(int a, const IntVector &);
    friend IntVector operator*(int a, const IntVector &);
    friend IntVector operator/(int a, const IntVector &);
    friend std::ostream&  operator<<(std::ostream&, const IntVector &);
    friend std::istream&  operator>>(std::istream&, IntVector &);

};

#endif // INTVECTOR_H
