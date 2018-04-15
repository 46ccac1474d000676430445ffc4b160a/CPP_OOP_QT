#include "intvector.h"

int IntVector::count = 0;

IntVector::IntVector() :
    m_length(0),
    m_dataRef(nullptr)
{
    count++;
}

IntVector::IntVector(int n) :
    m_length(n),
    m_dataRef(new int[n])
{
    count++;
}

IntVector::IntVector(const IntVector &v) :
    m_length(v.m_length),
    m_dataRef(new int[v.m_length])
{
    for (int i = 0; i < m_length; i++)
    {
        m_dataRef[i] = v.m_dataRef[i];
    }
}

IntVector::~IntVector()
{
    if (m_dataRef != nullptr) delete [] m_dataRef;
}

int IntVector::size()
{
    return m_length;
}

int IntVector::get_error()
{
    return m_error;
}

int IntVector::get_count()
{
    return count;
}

int IntVector::min()
{
    if (m_dataRef != nullptr)
    {
        int m = 0;
        for (int i = 1; i < m_length; i++)
            if (m_dataRef[i] < m_dataRef[m])
                m = i;
        return m_dataRef[m];
    }
    return 0;
}

int IntVector::max()
{
    if (m_dataRef != nullptr)
    {
        int m = 0;
        for (int i = 1; i < m_length; i++)
            if (m_dataRef[i] > m_dataRef[m])
                m = i;
        return m_dataRef[m];
    }
    return 0;
}

double IntVector::average()
{
    double a = 0.;
    if (m_dataRef != nullptr)
    {
        for (int i = 0; i < m_length; i++)
            a += m_dataRef[i];
    }
    return a;
}

int IntVector::median()
{

}

double IntVector::dispersion()
{

}

double IntVector::rms()
{

}

void IntVector::fill()
{

}

void IntVector::sort()
{
    for (int i = 1; i < m_length; i++)
        for (int j = i; j > 0 && m_dataRef[j-1] > m_dataRef[j]; j--)
        {
            int t = m_dataRef[j-1];
            m_dataRef[j-1] = m_dataRef[j];
            m_dataRef[j] = t;
        }
}

IntVector IntVector::operator-()
{

}

IntVector IntVector::operator+(const IntVector &) const
{

}

IntVector IntVector::operator-(const IntVector &) const
{

}

IntVector IntVector::operator*(const IntVector &) const
{

}

IntVector IntVector::operator/(const IntVector &) const
{

}

IntVector IntVector::operator+(int a) const
{

}

IntVector IntVector::operator-(int a) const
{

}

IntVector IntVector::operator*(int a) const
{

}

IntVector IntVector::operator/(int a) const
{

}

IntVector &IntVector::operator++()
{

}

IntVector IntVector::operator++(int)
{

}

IntVector &IntVector::operator--()
{

}

IntVector IntVector::operator--(int)
{

}

int &IntVector::operator[](int index)
{
    if (index > m_length-1 || index < 0) throw std::out_of_range("In IntVector &IntVector::operator[](int index) out of range");
    return *(m_dataRef+index);
}

void *IntVector::operator new(size_t size)
{

}

void IntVector::operator delete(void *addr)
{

}

IntVector &IntVector::operator=(const IntVector &)
{

}

int IntVector::operator==(const IntVector &) const
{

}

int IntVector::operator!=(const IntVector &) const
{

}

int IntVector::operator>(const IntVector &) const
{

}

int IntVector::operator>=(const IntVector &) const
{

}

int IntVector::operator<(const IntVector &) const
{

}

int IntVector::operator<=(const IntVector &) const
{

}
