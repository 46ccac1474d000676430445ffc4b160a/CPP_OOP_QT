#include <iostream>
#include "mystring.h"

using namespace std;

int main()
{
    String s1 = "abcd", s2 = "abcd";

    cout << (s2 != s1) << endl;

    return 0;
}
