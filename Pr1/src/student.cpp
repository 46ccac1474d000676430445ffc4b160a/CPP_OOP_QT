#include "student.h"

Student::Student()
{
}

Student::Student(const char *surname, const char *group, int birth_year, const int *marks)
{
    for (int i = 0; i < 20 && surname[i]; i++) this->surname[i] = surname[i];
    for (int i = 0; i < 10 && group[i]; i++) this->group[i] = group[i];
    this->birth_year = birth_year;
    if (marks == nullptr) for (int i = 0; i < 5; i++) this->marks[i] = 0;
    else for (int i = 0; i < 5; i++) this->marks[i] = marks[i];
}

Student::~Student()
{
}

void Student::get_surname(char *name)
{
    for (int i = 0; i < 20 && surname[i]; i++) name[i] = surname[i];
}

const char *Student::get_surname()
{
    return surname;
}

void Student::get_group(char *gr)
{
    for (int i = 0; i < 10 && group[i]; i++) gr[i] = group[i];
}

const char *Student::get_group()
{
    return group;
}

int Student::get_year()
{
    return birth_year;
}

void Student::get_marks(int *mr)
{
    for (int i = 0; i < 5; i++) mr[i] = marks[i];
}

int Student::get_mark(int n)
{
    return marks[n];
}

void Student::set_surname(const char *sn)
{
    for (int i = 0; i < 20 && sn[i]; i++) surname[i] = sn[i];
}

void Student::set_group(const char *gr)
{
    for (int i = 0; i < 20 && gr[i]; i++) group[i] = gr[i];
}

void Student::set_year(int b_y)
{
    birth_year = b_y;
}

void Student::set_marks(const int *mrs)
{
    for (int i = 0; i < 5; i++) marks[i] = mrs[i];
}

double Student::aver_marks()
{
    double res = 0.;
    for (int i = 0; i < 5; i++) res += marks[i];
    res /= 5.;
    return res;
}

void Student::show(int new_line_before, int new_line_after)
{
    while(new_line_before--) putchar('\n');
    printf("%-20s  %-10s  %-4d  marks=[%d %d %d %d %d]", surname, group, birth_year, *marks, marks[1], marks[2], marks[3], marks[4]);
    while(new_line_after--) putchar('\n');
}

std::ostream& operator << (std::ostream &os, const Student &s)
{
    return os
    << s.surname << "  "
    << s.group << "  "
    << s.birth_year
    << "  marks=["
    << s.marks[0] << " "
    << s.marks[1] << " "
    << s.marks[2] << " "
    << s.marks[3] << " "
    << s.marks[4] << "]";
}

