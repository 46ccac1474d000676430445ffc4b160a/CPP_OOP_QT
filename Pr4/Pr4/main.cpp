#include <conio.h>

#include "TimeClass.h"

using namespace std;

int main()
{
    TimeClass t;

    while (!kbhit())
    {
        t.showTime(12, 4, 12, 15);
        Sleep(1000);
        t.inc();
    }

    return 0;
}
