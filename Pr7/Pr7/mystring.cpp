#include "mystring.h"

void String::resize(int n)
{
    char *ref = new char[n];
    if (m_charRef != nullptr)
    {
        strcpy(ref, m_charRef);
        delete [] m_charRef;
    }
    m_charRef = ref;
    if (m_lenght > n) m_lenght = n;
}

String::String() :
    m_lenght(0),
    m_charRef(nullptr)
{
}

String::String(const char *s) :
    m_lenght(strlen(s)),
    m_charRef(new char[m_lenght+1])
{
    strcpy(m_charRef, s);
}

String::String(int n) :
    m_lenght(0),
    m_charRef(new char[n]{0})
{
}

String::String(const String &s) :
    m_lenght(s.m_lenght),
    m_charRef(new char[m_lenght+1])
{
    strcpy(m_charRef, s.m_charRef);
}

String::~String()
{
    if (m_charRef != nullptr) delete [] m_charRef;
}

const char *String::get_str() const
{
    return m_charRef;
}

void String::get_str(char *s) const
{
    strcpy(s, m_charRef);
}

int String::size() const
{
    return m_lenght;
}

void String::clear()
{
    m_lenght = 0;
    if (m_charRef != nullptr)
    {
        delete [] m_charRef;
        m_charRef = nullptr;
    }
}

String String::operator+(const String &s) const
{
    String tempStr;

    int tsize = m_lenght + s.m_lenght;

    if (tsize)
    {
        char *ref = new char[tsize + 1];
        if (m_charRef != nullptr) strcpy(ref, m_charRef);
        char *tref = ref + m_lenght;
        if (s.m_charRef != nullptr) strcpy(tref, s.m_charRef);

        tempStr.m_charRef = ref;
        tempStr.m_lenght = tsize;
    }

    return tempStr;
}

String &String::operator=(const String &s)
{
    if (s.m_lenght)
    {
        m_lenght = s.m_lenght;

        if (m_charRef != nullptr) delete [] m_charRef;
        m_charRef = new char[m_lenght+1];

        strcpy(m_charRef, s.m_charRef);
    }
    else
    {
        m_lenght = 0;
        if (m_charRef != nullptr)
        {
            delete [] m_charRef;
            m_charRef = nullptr;
        }
    }

    return *this;
}

String &String::operator+=(const String &s)
{
    int tsize = m_lenght + s.m_lenght;

    if (tsize)
    {
        char *ref = new char[tsize + 1];
        if (m_charRef != nullptr) strcpy(ref, m_charRef);
        char *tref = ref + m_lenght;
        if (s.m_charRef != nullptr) strcpy(tref, s.m_charRef);

        m_charRef = ref;
        m_lenght = tsize;
    }

    return *this;
}

char &String::operator[](int index)
{
    if (index > m_lenght-1)
    {
        throw std::out_of_range("In char &String::operator[](int index) out of range");
    }
    return *(m_charRef+index);
}

int String::operator==(const String &s) const
{
    if (m_lenght != s.m_lenght) return 0;

    return !strcmp(m_charRef, s.m_charRef);
}

int String::operator!=(const String &s) const
{
    if (m_lenght != s.m_lenght) return 1;

    return strcmp(m_charRef, s.m_charRef);
}

int String::operator>(const String &s) const
{
    return strcmp(m_charRef, s.m_charRef) < 0;
}

int String::operator>=(const String &s) const
{
    return strcmp(m_charRef, s.m_charRef) <= 0;
}

int String::operator<(const String &s) const
{
    return strcmp(m_charRef, s.m_charRef) > 0;
}

int String::operator<=(const String &s) const
{
    return strcmp(m_charRef, s.m_charRef) >= 0;
}

std::ostream &operator<<(std::ostream &o, const String &s)
{
    if (s.m_charRef != nullptr) return o << s.m_charRef;
    return o;
}

std::istream &operator>>(std::istream &i, String &s)
{
    int rsize = 8;
    s.clear();
    s.resize(rsize);
    int written = 0;
    int ch = i.get();
    while(ch != ' ' && ch != '\n')
    {
        if (written == rsize-1) s.resize(rsize <<= 1);
        *(s.m_charRef+written) = ch;
        *(s.m_charRef+written+1) = 0;
        s.m_lenght++;
        written++;
        ch = i.get();
    }

    return i;
}


