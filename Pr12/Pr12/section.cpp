#include "section.hpp"

Section::Section(int a1, int a2, int a3, int a4)
{
    m_answers[0] = a1 > 20 ? 20 : (a1 < 0 ? 0 : a1);
    m_answers[1] = a2 > 20 ? 20 : (a2 < 0 ? 0 : a2);
    m_answers[2] = a3 > 20 ? 20 : (a3 < 0 ? 0 : a3);
    m_answers[3] = a4 > 20 ? 20 : (a4 < 0 ? 0 : a4);
}

void Section::setAnswer(int n, int ans)
{
    if (n > 3 || n < 0) throw std::range_error("in \"int Section::setAnswer\" range error");
    m_answers[n] = ans;
}

int Section::answer(int n) const
{
    if (n > 3 || n < 0) throw std::range_error("in \"int Section::answer\" range error");
    return m_answers[n-1];
}

int Section::rightAnswers() const
{
    int n = 0;
    for (int i = 0; i < 4; i++)
        if (m_answers[i] > 0) n++;
    return n++;
}

int Section::summOf(int n) const
{
    if (n < 1) n = 1;
    if (n > 4) n = 4;

    int t = 0;

    for (int i = 0; i < 4; i++)
    {
        if (m_answers[i] > 0)
        {
            t += m_answers[i];
            n--;
        }
        if (!n) break;
    }

    return t;
}

std::istream &operator>>(std::istream &i, Section &s)
{
    return i >> s.m_answers[0]
             >> s.m_answers[1]
             >> s.m_answers[2]
             >> s.m_answers[3];
}

std::ostream &operator<<(std::ostream &o, const Section &s)
{
    return o << "["
             << s.m_answers[0] << ", "
             << s.m_answers[1] << ", "
             << s.m_answers[2] << ", "
             << s.m_answers[3] << "]";
}
