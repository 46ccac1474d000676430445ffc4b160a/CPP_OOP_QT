#include "TimeClass.h"

TimeClass::TimeClass()
{
    time_t t;
    tm *t_m;
    time(&t);
    t_m=localtime(&t);
    seconds = t_m->tm_hour * 3600 + t_m->tm_min * 60 + t_m->tm_sec;
}

TimeClass::TimeClass(int h, int m, int s) :
    seconds( (h%24)*3600 + (m%1440)*60 + (s%86400) )
{
}

TimeClass::~TimeClass()
{
}

int TimeClass::get_hour() const
{
    return seconds / 3600;
}

int TimeClass::get_min() const
{
    return seconds % 3600 / 60;
}

int TimeClass::get_sec() const
{
    return seconds  % 60;
}

TimeClass& TimeClass::set_hour(int h)
{
    seconds = (seconds % 3600) + (h%24)*3600;
    return *this;
}

TimeClass& TimeClass::set_min(int m)
{
    seconds = (seconds / 3600 * 3600) + ((m%1440) * 60) + (seconds % 3600 % 60);
    return *this;
}

TimeClass& TimeClass::set_sec(int s)
{
    seconds = (seconds / 3600 * 3600) + (seconds % 3600 / 60 * 60) + (s%86400);
    return *this;
}

TimeClass TimeClass::addSeconds(int sec) const
{
    TimeClass time = *this;
    time.seconds = (time.seconds + sec) % 86400;
    return time;
}

TimeClass TimeClass::diffTime(const TimeClass& t)
{
    return TimeClass(0, 0, abs(seconds - t.seconds) );
}

#ifdef __MINGW32
void TimeClass::showTime(int x, int y, int textc, int bgc)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bgc<<4) | textc));

    COORD scrn;
    HANDLE hOutPut = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = x;
    scrn.Y = y;
    SetConsoleCursorPosition(hOutPut, scrn);

    printf("%02d:%02d:%02d", get_hour(), get_min(), get_sec());
}
#endif

TimeClass& TimeClass::inc()
{
    seconds = (seconds + 1) % 86400;
    return *this;
}

int TimeClass::equals(const TimeClass& t) const
{
    return !(seconds - t.seconds);
}

int TimeClass::more(const TimeClass& t) const
{
    return seconds > t.seconds;
}

int TimeClass::less(const TimeClass& t) const
{
    return seconds < t.seconds;
}
