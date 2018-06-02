#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <stdexcept>
#include <ostream>

template <class T>
class Array
{
    int m_size;
    T *m_dataRef;
    static int count;

public:
    Array();
    Array(int n);
    Array(const Array &);
    ~Array();

    int size() const;
    static int get_count();

    T min() const;
    T max() const;
    T average() const;
    T median() const;
    void fill(T from, T to);
    void sort();

    Array operator-();

    Array operator+(const Array &) const;
    Array operator-(const Array &) const;
    Array operator*(const Array &) const;
    Array operator/(const Array &) const;

    Array operator+(int a) const;
    Array operator-(int a) const;
    Array operator*(int a) const;
    Array operator/(int a) const;

    Array &operator++();
    Array operator++(int) const;

    Array &operator--();
    Array operator--(int) const;

    T &operator[](int index);

    void *operator new(size_t size);
    void operator delete (void* addr);

    Array &operator=(const Array &);
    int operator==(const Array &) const;
    int operator!=(const  Array &) const;
    int operator>(const Array &) const;
    int operator>=(const Array &) const;
    int operator<(const Array &) const;
    int operator<=(const Array &) const;

    template <typename Tt>
    friend Array<Tt> operator+(Tt a, const Array<Tt> &);
    template <typename Tt>
    friend Array<Tt> operator-(Tt a, const Array<Tt> &);
    template <typename Tt>
    friend Array<Tt> operator*(Tt a, const Array<Tt> &);
    template <typename Tt>
    friend Array<Tt> operator/(Tt a, const Array<Tt> &);

    template <typename Tt>
    friend std::ostream &operator<<(std::ostream &o, const Array<Tt> &a);

};

template <typename Tt>
std::ostream &operator<<(std::ostream &o, const Array<Tt> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        o << a.m_dataRef[i] << " ";
    }
    return o;
}

template<class T>
int Array<T>::count = 0;

template<class T>
Array<T>::Array() :
    m_size(0),
    m_dataRef(nullptr)
{
    Array<T>::count++;
}

template<class T>
Array<T>::Array(int n) :
    m_size(n),
    m_dataRef(new T[n])
{
    count++;
}

template<class T>
Array<T>::Array(const Array &a) :
    m_size(a.size()),
    m_dataRef(new T[a.size()])
{
    count++;
    for (int i = 0; i < size(); i++)
    {
        m_dataRef[i] = a.m_dataRef[i];
    }
}

template<class T>
Array<T>::~Array()
{
    delete [] m_dataRef;
    count--;
}

template<class T>
inline int Array<T>::size() const
{
    return m_size;
}

template<class T>
inline int Array<T>::get_count()
{
    return count;
}

template<class T>
T Array<T>::min() const
{
    if (m_dataRef != nullptr)
    {
        int m = 0;
        for (int i = 1; i < size(); i++)
            if (m_dataRef[i] > m_dataRef[m])
                m = i;

        return m_dataRef[m];
    }

    return T();
}

template<class T>
T Array<T>::max() const
{
    if (m_dataRef != nullptr)
    {
        int m = 0;
        for (int i = 1; i < size(); i++)
            if (m_dataRef[i] < m_dataRef[m])
                m = i;

        return m_dataRef[m];
    }

    return T();
}

template<class T>
T Array<T>::average() const
{
    if (m_dataRef != nullptr)
    {
        T a = m_dataRef[0];
        for (int i = 1; i < size(); i++)
            a += m_dataRef[i];
        return a / size();
    }

    return T();
}

template<class T>
T Array<T>::median() const
{
    if (m_dataRef != nullptr)
    {
        Array<T> t(*this);
        t.sort();
        return t[t.size()/2];
    }

    return T();
}

template<class T>
void Array<T>::fill(T from, T to)
{
    for (int i = 0; i < size(); i++)
    {
        m_dataRef[i] = from + (rand()%int(to-from+1));
    }
}

template<>
void Array<double>::fill(double from, double to)
{
    for (int i = 0; i < size(); i++)
    {
        m_dataRef[i] = from + (rand() % int( (to-from+1)*100.) ) / 100.;
    }
}

template<class T>
void Array<T>::sort()
{
    for (int i = 1; i < size(); i++)
        for (int j = i; j > 0 && m_dataRef[j-1] > m_dataRef[j]; j--)
        {
            T t = m_dataRef[j-1];
            m_dataRef[j-1] = m_dataRef[j];
            m_dataRef[j] = t;
        }
}

template<class T>
Array<T> Array<T>::operator-()
{
    Array<T> t(*this);
    for (int i = 0; i < t.size(); i++)
    {
        t.m_dataRef[i] = -t.m_dataRef[i];
    }
    return t;
}

template<class T>
Array<T> Array<T>::operator+(const Array &a) const
{
    if (a.size() == size())
    {
        Array<T> t(*this);
        for (int i = 0; i < t.size(); i++)
        {
            t[i] += a[i];
        }
        return t;
    }
    else
    {
        throw std::length_error("in 'Array Array<T>::operator+(const Array &a) const' length error");
    }
}

template<class T>
Array<T> Array<T>::operator-(const Array &a) const
{
    if (a.size() == size())
    {
        Array<T> t(*this);
        for (int i = 0; i < t.size(); i++)
        {
            t[i] -= a[i];
        }
        return t;
    }
    else
    {
        throw std::length_error("in 'Array Array<T>::operator+(const Array &a) const' length error");
    }
}

template<class T>
Array<T> Array<T>::operator*(const Array &a) const
{
    if (a.size() == size())
    {
        Array<T> t(*this);
        for (int i = 0; i < t.size(); i++)
        {
            t[i] *= a[i];
        }
        return t;
    }
    else
    {
        throw std::length_error("in 'Array Array<T>::operator+(const Array &a) const' length error");
    }
}

template<class T>
Array<T> Array<T>::operator/(const Array &a) const
{
    if (a.size() == size())
    {
        Array<T> t(*this);
        for (int i = 0; i < t.size(); i++)
        {
            t[i] /= a[i];
        }
        return t;
    }
    else
    {
        throw std::length_error("in 'Array Array<T>::operator+(const Array &a) const' length error");
    }
}

template<class T>
Array<T> Array<T>::operator+(int a) const
{
    Array<T> t(*this);
    for (int i = 0; i < t.size(); i++)
    {
        t[i] += a;
    }
    return t;
}

template<class T>
Array<T> Array<T>::operator-(int a) const
{
    Array<T> t(*this);
    for (int i = 0; i < t.size(); i++)
    {
        t[i] -= a;
    }
    return t;
}

template<class T>
Array<T> Array<T>::operator*(int a) const
{
    Array<T> t(*this);
    for (int i = 0; i < t.size(); i++)
    {
        t[i] *= a;
    }
    return t;
}

template<class T>
Array<T> Array<T>::operator/(int a) const
{
    Array<T> t(*this);
    for (int i = 0; i < t.size(); i++)
    {
        t[i] /= a;
    }
    return t;
}

template<class T>
Array<T> &Array<T>::operator++()
{
    for (int i = 0; i < size(); i++)
    {
        m_dataRef[i]++;
    }
    return *this;
}

template<class T>
Array<T> Array<T>::operator++(int) const
{
    Array<T> t(*this);
    for (int i = 0; i < t.size(); i++)
    {
        t[i]++;
    }
    return t;
}

template<class T>
Array<T> &Array<T>::operator--()
{
    for (int i = 0; i < size(); i++)
    {
        m_dataRef[i]--;
    }
    return *this;
}

template<class T>
Array<T> Array<T>::operator--(int) const
{
    Array<T> t(*this);
    for (int i = 0; i < size(); i++)
    {
        t[i]--;
    }
    return t;
}

template<class T>
inline T &Array<T>::operator[](int index)
{
    if (index > size()-1 || index < 0)
        throw std::range_error("in 'inline Array &Array<T>::operator[](int index)' range error");

    return m_dataRef[index];
}

template<class T>
void *Array<T>::operator new(size_t size)
{
    T *t = malloc(size * sizeof(T));
    if (t == NULL) throw std::bad_alloc("in 'void *Array<T>::operator new(size_t size)' bad alloc");

    return t;
}

template<class T>
void Array<T>::operator delete(void *addr)
{
    free(addr);
}

template<class T>
Array<T> &Array<T>::operator=(const Array &a)
{
    delete [] m_dataRef;
    m_dataRef = nullptr;

    m_size = a.size();

    if (a.m_dataRef != nullptr)
    {
        m_dataRef = new T[size()];
        for (int i = 0; i < a.size(); i++)
        {
            m_dataRef[i] = a.m_dataRef[i];
        }
    }

    return *this;
}

template<class T>
int Array<T>::operator==(const Array &a) const
{
    if (size() != a.size()) return false;

    for (int i = 0; i < size(); i++)
    {
        if (m_dataRef[i] != a[i]) return false;
    }

    return true;
}

template<class T>
int Array<T>::operator!=(const Array &a) const
{
    if (size() != a.size()) return true;

    for (int i = 0; i < size(); i++)
    {
        if (m_dataRef[i] != a[i]) return true;
    }

    return false;
}

template<class T>
int Array<T>::operator>(const Array &a) const
{
    for (int i = 0; i < size(); i++)
    {
        if (m_dataRef[i] > a.m_dataRef[i]) return true;
    }
    return false;
}

template<class T>
int Array<T>::operator>=(const Array &a) const
{
    for (int i = 0; i < size(); i++)
    {
        if (m_dataRef[i] >= a.m_dataRef[i]) return true;
    }
    return false;
}

template<class T>
int Array<T>::operator<(const Array &a) const
{
    for (int i = 0; i < size(); i++)
    {
        if (m_dataRef[i] < a.m_dataRef[i]) return true;
    }
    return false;
}

template<class T>
int Array<T>::operator<=(const Array &a) const
{
    for (int i = 0; i < size(); i++)
    {
        if (m_dataRef[i] <= a.m_dataRef[i]) return true;
    }
    return false;
}

template<class Tt>
Array<Tt> operator+(int a, const Array<Tt> &)
{

}

template<class Tt>
Array<Tt> operator-(int a, const Array<Tt> &)
{

}

template<class Tt>
Array<Tt> operator*(int a, const Array<Tt> &)
{

}

template<class Tt>
Array<Tt> operator/(int a, const Array<Tt> &)
{

}

#endif // ARRAY_HPP
