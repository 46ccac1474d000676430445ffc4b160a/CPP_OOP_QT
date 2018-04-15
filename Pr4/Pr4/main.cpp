#include <conio.h>

#include "TimeClass.h"

using namespace std;

int main()
{
    TimeClass t;

    while (!kbhit())
    {
        t.showTime(0, 0, 3);
        Sleep(1000);
        t.inc();
    }

    return 0;
}
