#include "Complex.h"

Complex::Complex()  :
    Real(0), Imaginary(0)
{
}

Complex::Complex(double real, double imaginary) :
    Real(real), Imaginary(imaginary)
{
}

inline double Complex::real()
{
    return Real;
}

inline double Complex::imaginary()
{
    return Imaginary;
}

inline Complex& Complex::setReal(double real)
{
    Real = real;
    return *this;
}

inline Complex& Complex::setImaginary(double imaginary)
{
    Imaginary = imaginary;
    return *this;
}

Complex Complex::sum(const Complex& x)
{
    Real += x.Real;
    Imaginary += x.Imaginary;
    return *this;
}

Complex Complex::sub(const Complex& x)
{
    Real -= x.Real;
    Imaginary -= x.Imaginary;
    return *this;
}

Complex Complex::mul(const Complex& x)
{
    Real = Real*x.Real - Imaginary*x.Imaginary;
    Imaginary = Real*x.Imaginary + Imaginary*x.Real;
    return *this;
}

Complex Complex::div(const Complex& x)
{
    Real = (Real*x.Real + Imaginary*x.Imaginary) / (x.Real*x.Real + x.Imaginary*x.Imaginary);
    Imaginary = (Real*x.Imaginary - Imaginary*x.Real) / (x.Real*x.Real + x.Imaginary*x.Imaginary);
    return *this;
}

bool Complex::equals(const Complex& x)
{
    return Real == x.Real && Imaginary == x.Imaginary;
}

void Complex::show(int new_line_before, int new_line_after)
{
    while(new_line_before--) putchar('\n');
    printf("%.2lf+%.2lfi", Real, Imaginary);
    while (new_line_after--) putchar('\n');
}

std::ostream &operator << (std::ostream &o, const Complex &x)
{
    return o << x.Real << '+' << x.Imaginary << 'i';
}

