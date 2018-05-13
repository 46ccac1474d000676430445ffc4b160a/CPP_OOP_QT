#include <iostream>

#include "Date.h"

using namespace std;

int main()
{
    Date d(4, 9, 2020);
    d.show(2);
    cout << endl << endl;
    Date().show(2);
    return 0;
}
