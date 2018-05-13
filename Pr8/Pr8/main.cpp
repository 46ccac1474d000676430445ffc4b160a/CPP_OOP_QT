#include <iostream>
#include <cstdlib>
#include "intvector.h"

using namespace std;

int main()
{
    srand(9876);
    IntVector vec(20);
    vec.fill(-30, 30);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl << endl;

    vec.sort();

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl << endl;

    return 0;
}
