#ifndef TIMECLASS_H
#define TIMECLASS_H

#include <ctime>
#include <windows.h>
#include <cstdio>

class TimeClass
{
private:
    long int seconds;			//количество секунд относительно начала суток

public:
    TimeClass();	//Конструктор без параметров, создает объект
                    // используя параметры системного времени
                    //(часы, минуты и секунды).
    TimeClass(int h, int m, int s);  //Конструктор с параметрами
    ~TimeClass();			        //Деструктор

    //Функции доступа
    int get_hour();
    int get_min();
    int get_sec();

    TimeClass& set_hour(int);
    TimeClass& set_min(int);
    TimeClass& set_sec(int);

    TimeClass diffTime(const TimeClass& t);	        //разность между текущим и объектом a.
    void showTime(int x = 0, int y = 0, int textc = 15, int bgc = 0); //отображения времени в точке
                                                    // с координатами x и y: 09:15:45
    TimeClass& inc();                              //функция инкремента (увеличение на 1 сек)

    //функции сравнения
    int equals(const TimeClass&)const;	//равенство двух объектов Time
    int more(const TimeClass&)const; 	//сравнение двух объектов Time на больше
    int less(const TimeClass&)const; 	//сравнение двух объектов Time на меньше

};

#endif // TIMECLASS_H
