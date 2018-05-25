#include "intvector.h"

int IntVector::count = 0;

IntVector::IntVector() :
    m_size(0),
    m_dataRef(nullptr)
{
    count++;
}

IntVector::IntVector(int n) :
    m_size(n),
    m_dataRef(new int[n])
{
    count++;
}

IntVector::IntVector(const IntVector &v) :
    m_size(v.size()),
    m_dataRef(new int[v.size()])
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
        throw std::length_error("in 'IntVector IntVector::operator+(const IntVector &vec) const' length error");
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
        throw std::length_error("in 'IntVector IntVector::operator+(const IntVector &vec) const' length error");
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
        throw std::length_error("in 'IntVector IntVector::operator+(const IntVector &vec) const' length error");
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
        throw std::length_error("in 'IntVector IntVector::operator+(const IntVector &vec) const' length error");
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
        throw std::range_error("in 'inline int &IntVector::operator[](int index) const' out of range");
    }
    else return *(m_dataRef+index);
}

void *IntVector::operator new(size_t size)
{
    return malloc(size*sizeof(IntVector));
}

void IntVector::operator delete(void *addr)
{
    free(addr);
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

bool IntVector::operator==(const IntVector &vec) const
{
    if (size() != vec.size()) return false;

    for (int i = 0; i < size(); i++)
    {
        if (m_dataRef[i] != vec[i]) return false;
    }

    return true;
}

bool IntVector::operator!=(const IntVector &vec) const
{
    if (size() != vec.size()) return true;

    for (int i = 0; i < size(); i++)
    {
        if (m_dataRef[i] != vec[i]) return true;
    }

    return false;
}

bool IntVector::operator>(const IntVector &vec) const
{
    for (int i = 0; i < size(); i++)
    {
        if (m_dataRef[i] > vec.m_dataRef[i]) return true;
    }
    return false;
}

bool IntVector::operator>=(const IntVector &vec) const
{
    for (int i = 0; i < size(); i++)
    {
        if (m_dataRef[i] >= vec.m_dataRef[i]) return true;
    }
    return false;
}

bool IntVector::operator<(const IntVector &vec) const
{
    for (int i = 0; i < size(); i++)
    {
        if (m_dataRef[i] < vec.m_dataRef[i]) return true;
    }
    return false;
}

bool IntVector::operator<=(const IntVector &vec) const
{
    for (int i = 0; i < size(); i++)
    {
        if (m_dataRef[i] <= vec.m_dataRef[i]) return true;
    }
    return false;
}

IntVector operator+(int a, const IntVector &v)
{
    IntVector t(v);
    for (int i = 0; i < t.size(); i++)
    {
        t[i] += a;
    }
    return t;
}

IntVector operator-(int a, const IntVector &v)
{
    IntVector t(v);
    for (int i = 0; i < t.size(); i++)
    {
        t[i] -= a;
    }
    return t;
}

IntVector operator*(int a, const IntVector &v)
{
    IntVector t(v);
    for (int i = 0; i < t.size(); i++)
    {
        t[i] *= a;
    }
    return t;
}

IntVector operator/(int a, const IntVector &v)
{
    IntVector t(v);
    for (int i = 0; i < t.size(); i++)
    {
        t[i] /= a;
    }
    return t;
}
