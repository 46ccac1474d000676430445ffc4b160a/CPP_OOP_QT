#ifndef TIMECLASS_H
#define TIMECLASS_H

#include <ctime>
#include <cstdlib>
#include <cstdio>

#ifdef __MINGW32
#include <windows.h>
#endif


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
    int get_hour() const;
    int get_min() const;
    int get_sec() const;

    TimeClass& set_hour(int);
    TimeClass& set_min(int);
    TimeClass& set_sec(int);

    TimeClass addSeconds(int) const;

    TimeClass diffTime(const TimeClass& t);	        //разность между текущим и объектом a.
#ifdef __MINGW32
    void showTime(int x = 0, int y = 0, int textc = 15, int bgc = 0); //отображения времени в точке
#endif                                                    // с координатами x и y: 09:15:45
    TimeClass& inc();                              //функция инкремента (увеличение на 1 сек)

    //функции сравнения
    int equals(const TimeClass&)const;	//равенство двух объектов Time
    int more(const TimeClass&)const; 	//сравнение двух объектов Time на больше
    int less(const TimeClass&)const; 	//сравнение двух объектов Time на меньше

};

#endif // TIMECLASS_H
