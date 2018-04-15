#include <iostream>
#include "Planet.h"

using namespace std;

int main()
{
    Planet pArr[3] = { Planet("a", 1.1, 1.1, "A"),  Planet("b", 2.2, 2.2, "B"), Planet("c", 3.3, 3.3, "C") };

    for (const Planet &p : pArr)
        cout << p << endl;

    return 0;
}
