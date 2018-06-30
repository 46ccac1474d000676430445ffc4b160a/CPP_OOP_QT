#include <iostream>
#include <cstdlib>
#include <ctime>

#include "section.hpp"
#include "train.hpp"

using namespace std;

void task9()
{
    cout << "������� 9" << endl << endl;

    Section A, B;

    cout << "������� ������ A (4 ��������)" << endl;
    cin >> A;
    cout << "������� ������ B (4 ��������)" << endl;
    cin >> B;

    cout << endl;

    int result = 0;
    string notice;

    if (A.rightAnswers() + B.rightAnswers() > 5) notice += "������ ��� 5.";

    if (A.rightAnswers() > 2)
    {
        result += A.summOf(3);
        if (B.rightAnswers() < 2) notice += "������������ �� B";

        result += B.summOf(2);
    }
    else
    {
        result += A.summOf(2);
        if (B.rightAnswers() < 3) notice += "������������ �� A";

        result += B.summOf(3);
    }

    cout << "������ A: " << A << endl
         << "������ B: " << B << endl
         << "���������: " << result << endl
         << "����������: " << notice << endl;
}

void task19()
{
    cout << "������� 19" << endl << endl;

    Train trains[25];

    for (int i = 0; i < 25; i++)
    {
        trains[i].setNumber( 2485+i );
        trains[i].setDirection("����������-�-������");

        TimeClass arrival(rand()%24, rand()%60, 0);

        trains[i].setArrival(arrival);
        trains[i].setDeparture(arrival.addSeconds(1800));
    }

    unsigned hour, min;

    while(true)
    {
        cout << "������� ����� [��� ������] << ";
        cin >> hour >> min;

        cout << "������ �� �������:" << endl;

        for (int i = 0; i < 25; i++)
        {
            if (trains[i].isOnStation(hour, min))
                cout << trains[i] << endl;
        }

        cout << endl << "��������� �����? y/n ... ";
        char ex;
        cin >> ex;
        if (ex == 'n') break;
    }

    cout << endl;
}

#define TASK9
//#define TASK19

int main()
{
    std::setlocale(LC_ALL, "rus");
    srand(time(0));

#ifdef TASK9
    task9();
#endif

#ifdef TASK19
    task19();
#endif

    return 0;
}

// 10, 15, 0, 0   20, 8, 17, 0
// 10, 9, 7, 20   0, 0, 0, 10
// 5, 6, 10, 0    19, 5, 3, 14
