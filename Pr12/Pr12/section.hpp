#ifndef SECTION_HPP
#define SECTION_HPP

#include <stdexcept>
#include <ostream>
#include <istream>

class Section
{
    int m_answers[4];

public:
    Section(int a1 = 0, int a2 = 0, int a3 = 0, int a4 = 0);

    void setAnswer(int n, int ans);

    int answer(int n) const;
    int rightAnswers() const;
    int summOf(int n = 4) const;

    friend std::ostream &operator<<(std::ostream &o, const Section &s);
    friend std::istream &operator>>(std::istream &i, Section &s);
};

#endif // SECTION_HPP
