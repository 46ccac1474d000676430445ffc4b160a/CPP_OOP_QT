#include "../include/fraction.h"

Fraction& Fraction::shorten()
{
    int a = abs(ch), b = zn;
    while (a && b)
        if (a >= b) a %= b;
        else b %= a;
    int bcd =  a | b;

    ch /= bcd;
    zn /= bcd;

    return *this;
}

Fraction::Fraction() :
    ch(0), zn(0)
{
}

Fraction::Fraction(const Fraction &x) :
    ch(x.ch), zn(x.zn)
{
}

Fraction& Fraction::operator=(const Fraction& x)
{
    if (&x != this)
    {
        ch = x.ch;
        zn = x.zn;
    }
    return *this;
}

bool operator == (const Fraction &x, const Fraction &y)
{
    return x.ch*y.zn == y.ch*x.zn;
}

Fraction::Fraction(int cel, int ch, int zn)
{
    zn = abs(zn);
    this->ch = cel*zn;
    this->ch += this->ch < 0 || ch < 0 ? -abs(ch) : abs(ch);
    this->zn = zn;
    this->shorten();
}

Fraction::~Fraction()
{
}


int Fraction::get_cel()
{
    return ch / zn;
}

int Fraction::get_ch()
{
    return ch % zn;
}

int Fraction::get_zn()
{
    return zn;
}


Fraction& Fraction::set_cel(int cl)
{
    ch = (ch % zn) + cl*zn;
    return *this;
}

Fraction& Fraction::set_chisl(int ch)
{
    this->ch = ch;
    return *this;
}

Fraction& Fraction::set_znam(int zn)
{
    this->zn = abs(zn);
    return *this;
}


Fraction Fraction::sum(const Fraction  &a)const
{
    Fraction t;
    t.shorten();
    return Fraction(0, ch*a.zn + a.ch*zn, zn*a.zn);
}

Fraction Fraction::sub(const Fraction  &a)const
{
    return Fraction(0, ch*a.zn - a.ch*zn, zn*a.zn);
}

Fraction Fraction::mul(const Fraction &a)const
{
    return Fraction(0, ch*a.ch, zn*a.zn);
}

Fraction Fraction::div(const Fraction &a)const
{
    return Fraction(0, ch*a.zn, zn*a.ch);
}


int Fraction::more(const Fraction  &a)const
{
    return ch*a.zn > a.ch*zn;
}

int Fraction::less(const Fraction  &a)const
{
    return ch*a.zn < a.ch*zn;
}

int Fraction::equals(const Fraction &a)const
{
    return ch*a.zn == a.ch*zn;
}


void Fraction::show(int new_line_before, int new_line_after)
{
    while(new_line_before--) putchar('\n');

    int ce = ch/zn, os = ch%zn;

    if (ce) printf("%d", ce);
    if (os) { if (ce) putchar(' '); printf("%d/%d", ce < 0 ? abs(os) : os, zn); }
    if (!(ce) && !ch) puts("null");

    while(new_line_after--) putchar('\n');
}

std::ostream& operator << (std::ostream &o, const Fraction &x)
{
    int ce = x.ch/x.zn, os = x.ch%x.zn;

    if (ce) o << ce;
    if (os) { if (ce) o << ' ';  o << (ce < 0 ? abs(os) : os) << '/' << x.zn; }
    if (!(ce) && !x.ch) o << "null";
    return o;
}
