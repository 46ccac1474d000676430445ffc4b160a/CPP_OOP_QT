#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cstdio>


class Complex
{

protected:
    double Real;
    double Imaginary;

public:
    Complex();
    Complex(double real, double imaginary);

    double real();
    double imaginary();

    Complex &setReal(double real);
    Complex &setImaginary(double imaginary);

    Complex sum(const Complex &x);
    Complex sub(const Complex &x);
    Complex mul(const Complex &x);
    Complex div(const Complex &x);

    bool equals(const Complex &x);

    void show(int new_line_before = 0, int new_line_after = 1);

    friend std::ostream &operator << (std::ostream &o, const Complex &x);

};

#endif // COMPLEX_H
