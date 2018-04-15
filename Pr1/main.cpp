#include <iostream>

using namespace std;

#include <cstdlib>
#include <ctime>

#include "student.h"

int main()
{
    srand(time(0));

    const int N = 10;

    Student *db = new Student[N];

    for (int i = 0; i < N; i++)
    {
        db[i].set_surname("Idiot");
        db[i].set_group("DCP-1-17");
        db[i].set_year(2000);

        int marks[5];
        for (int i = 0; i < 5; i++) marks[i] = rand() % 4;

        db[i].set_marks(marks);
    }

    for (int i = 0; i < N; i++) cout << db[i] << endl;

    delete [] db;

    return 0;
}
