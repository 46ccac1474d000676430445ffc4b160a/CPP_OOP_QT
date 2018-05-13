#include "intvector.h"

int IntVector::count = 0;

IntVector::IntVector() :
    m_size(0),
    m_dataRef(nullptr),
    m_error(0)
{
    count++;
}

IntVector::IntVector(int n) :
    m_size(n),
    m_dataRef(new int[n]),
    m_error(0)
{
    count++;
}

IntVector::IntVector(const IntVector &v) :
    m_size(v.size()),
    m_dataRef(new int[v.size()]),
    m_error(0)
{
    for (int i = 0; i < size(); i++)
    {
        m_dataRef[i] = v.m_dataRef[i];
    }
}

IntVector::~IntVector()
{
    if (m_dataRef != nullptr) delete [] m_dataRef;
}

inline int IntVector::size() const
{
    return m_size;
}

int IntVector::get_error() const
{
    return m_error;
}

int IntVector::get_count()
{
    return count;
}

int IntVector::min() const
{
    if (m_dataRef != nullptr)
    {
        int m = 0;
        for (int i = 1; i < size(); i++)
            if (m_dataRef[i] < m_dataRef[m])
                m = i;
        return m_dataRef[m];
    }
    return 0;
}

int IntVector::max() const
{
    if (m_dataRef != nullptr)
    {
        int m = 0;
        for (int i = 1; i < size(); i++)
            if (m_dataRef[i] > m_dataRef[m])
                m = i;
        return m_dataRef[m];
    }
    return 0;
}

double IntVector::average() const
{
    double a = 0.;
    if (m_dataRef != nullptr)
    {
        for (int i = 0; i < size(); i++)
            a += m_dataRef[i];
    }
    return a;
}

int IntVector::median() const
{
    IntVector t(*this);
    t.sort();
    return t[t.size()/2];
}

double IntVector::dispersion() const
{

}

double IntVector::rms()
{

}

void IntVector::fill(int from, int to)
{
    for (int i = 0; i < size(); i++)
    {
        m_dataRef[i] = from + (rand()%(to-from+1));
    }
}

void IntVector::sort()
{
    for (int i = 1; i < size(); i++)
        for (int j = i; j > 0 && m_dataRef[j-1] > m_dataRef[j]; j--)
        {
            int t = m_dataRef[j-1];
            m_dataRef[j-1] = m_dataRef[j];
            m_dataRef[j] = t;
        }
}

IntVector IntVector::operator-()
{
    IntVector t(*this);
    for (int i = 0; i < t.size(); i++)
    {
        t.m_dataRef[i] = -t.m_dataRef[i];
    }
}

IntVector IntVector::operator+(const IntVector &vec) const
{
    if (vec.size() == size())
    {
        IntVector t(*this);
        for (int i = 0; i < t.size(); i++)
        {
            t[i] += vec[i];
        }
        return t;
    }
    else
    {
        IntVector t;
        t.m_error = 4;
        return t;
    }
}

IntVector IntVector::operator-(const IntVector &vec) const
{
    if (vec.size() == size())
    {
        IntVector t(*this);
        for (int i = 0; i < t.size(); i++)
        {
            t[i] -= vec[i];
        }
        return t;
    }
    else
    {
        IntVector t;
        t.m_error = 4;
        return t;
    }
}

IntVector IntVector::operator*(const IntVector &vec) const
{
    if (vec.size() == size())
    {
        IntVector t(*this);
        for (int i = 0; i < t.size(); i++)
        {
            t[i] *= vec[i];
        }
        return t;
    }
    else
    {
        IntVector t;
        t.m_error = 4;
        return t;
    }
}

IntVector IntVector::operator/(const IntVector &vec) const
{
    if (vec.size() == size())
    {
        IntVector t(*this);
        for (int i = 0; i < t.size(); i++)
        {
            t[i] /= vec[i];
        }
        return t;
    }
    else
    {
        IntVector t;
        t.m_error = 4;
        return t;
    }
}

IntVector IntVector::operator+(int a) const
{
    IntVector t(*this);
    for (int i = 0; i < t.size(); i++)
    {
        t[i] += a;
    }
    return t;
}

IntVector IntVector::operator-(int a) const
{
    IntVector t(*this);
    for (int i = 0; i < t.size(); i++)
    {
        t[i] -= a;
    }
    return t;
}

IntVector IntVector::operator*(int a) const
{
    IntVector t(*this);
    for (int i = 0; i < t.size(); i++)
    {
        t[i] *= a;
    }
    return t;
}

IntVector IntVector::operator/(int a) const
{
    IntVector t(*this);
    for (int i = 0; i < t.size(); i++)
    {
        t[i] /= a;
    }
    return *this;
}

IntVector &IntVector::operator++()
{
    for (int i = 0; i < size(); i++)
    {
        m_dataRef[i]++;
    }
    return *this;
}

IntVector IntVector::operator++(int)
{
    IntVector t(*this);

    for (int i = 0; i < t.size(); i++)
    {
        m_dataRef[i]++;
    }

    return t;
}

IntVector &IntVector::operator--()
{
    for (int i = 0; i < size(); i++)
    {
        m_dataRef[i]--;
    }
    return *this;
}

IntVector IntVector::operator--(int)
{
    IntVector t(*this);

    for (int i = 0; i < t.size(); i++)
    {
        m_dataRef[i]--;
    }

    return t;
}

inline int &IntVector::operator[](int index) const
{
    if (index > size()-1 || index < 0)
    {
        m_error = 1;
    }
    else return *(m_dataRef+index);
}

void *IntVector::operator new(size_t size)
{

}

void IntVector::operator delete(void *addr)
{

}

IntVector &IntVector::operator=(const IntVector &vec)
{
    delete [] m_dataRef;
    m_dataRef = nullptr;

    m_size = size();

    if (vec.size() > 0)
    {
        m_dataRef = new int[vec.size()];
        for (int i = 0; i < vec.size(); i++)
        {
            m_dataRef[i] = vec[i];
        }
    }

    return *this;
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
