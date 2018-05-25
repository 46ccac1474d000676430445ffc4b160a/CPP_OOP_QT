#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define homework

#ifndef homework

double divide(double a, double b)
{
   if (b==0) throw (b);
   else return a/b;
}

void get_message(char *message, char sym)
{
    char *m = message;
    while(*m++);
    m--;
    *m++=sym;
    *m='\0';
}

 // функция проверки наличия символа в строке и возбуждение исключительной ситуации
int no_symbol(const char *str, char symbol)
{
    for (size_t i=0; i<strlen(str); i++)
        if(str[i] == symbol)
        {
            char *message = new char[80];
            strcpy(message, "string hasn't consists symbol -");
            get_message(message, symbol);
            throw  message;
        }
    return 1;
}

 //Пример обработки исключительных ситуаций в функции main()
int main()
{
    try
    {
        divide(2, 5);
        //divide(2, 0);
        no_symbol("Hello my friend",'f');
        no_symbol("September is good time",'t');
    }
    catch(char *message)
    {
        printf("%s\n", message);
        delete [] message;
    }
    catch(double b)
    {
        printf("divide by %g\n",b);
    }
    return 1;
}

#endif


#ifdef homework

#include "intvector.h"

int main()
{
    srand(time(0));
    IntVector vec(20);
    vec.fill(-30, 30);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl << endl;

    vec.sort();

    try
    {
        for (int i = 0; i < vec.size() + 2; i++)
        {

            cout << vec[i] << " ";
        }
    }
    catch (range_error e)
    {
        cout << endl << e.what() << endl;
    }
    cout << endl << endl;

    return 0;
}

#endif
