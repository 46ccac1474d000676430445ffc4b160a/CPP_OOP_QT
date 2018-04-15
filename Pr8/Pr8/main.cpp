#include <iostream>
#include <cstdlib>
#include "intvector.h"

using namespace std;

int main()
{
    IntVector vec(20);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << (vec[i] = rand()%100) << " ";
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
