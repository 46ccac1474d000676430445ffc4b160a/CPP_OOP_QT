#include <iostream>
#include <ctime>

#include "array.hpp"

using namespace std;

template <typename T>
T sum(T val1, T val2, T val3)
{
    return val1 + val2 + val3;
}


int main()
{
    srand(time(0));

#define out(val) cout << #val << " = " << val << endl
    out(sum<double>(30.3, 27.8f, 10));
    out(sum<int>(30.3, 27.8f, 10));
    out(sum<char>(30.3, 27.8f, 10));
#undef out
//    cout << int('C') << endl;
    cout << endl;

    Array<int> arr1(20);
    Array<double> arr2(20);

    arr1.fill(-30, 30);
    arr2.fill(-30., 30.);

    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl << endl;

    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl << endl;

    arr1.sort();
    arr2.sort();

    cout << endl;

    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl << endl;

    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl << endl;

    return 0;
}
