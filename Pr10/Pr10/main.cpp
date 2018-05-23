#include <iostream>
#include <cstdlib>
#include "intvector.h"
#include <cstring>

using namespace std;

double divide(double a, double b)
{
   if (b==0) throw (b);
         else return a/b;
}

void get_message(char *message, char sym)
{
    while(*message++);
    message--;
    *message++=sym;
    *message='\0';
}

// функция проверки наличия символа в строке и возбуждение исключительной ситуации
int no_symbol(char *str, char symbol)
{
    for (int i=0;i<strlen(str); i++)
        if(str[i] == symbol)
        {
            char message[80]= "string hasn't consists symbol -";
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
    catch(char *message){ printf("%s\n", message);}
    catch(double b){ printf("divide by %g\n",b); }
    return 1;
}


//int main()
//{
//    srand(9876);
//    IntVector vec(20);
//    vec.fill(-30, 30);

//    for (int i = 0; i < vec.size(); i++)
//    {
//        cout << vec[i] << " ";
//    }
//    cout << endl << endl;

//    vec.sort();

//    for (int i = 0; i < vec.size(); i++)
//    {
//        cout << vec[i] << " ";
//    }
//    cout << endl << endl;

//    return 0;
//}
