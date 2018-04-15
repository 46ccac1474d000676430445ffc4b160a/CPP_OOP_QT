#ifndef STUDENT_H
#define STUDENT_H

#include <cstdio>
#include <iostream>

class Student
{

//элементы–данные
private:
    char surname[20];  //фамилия
    char group[10];     //группа
    int birth_year;     //год рождения
    int marks[5];       //успеваемость по 5 предметам

//элементы-функции
public:
    Student();  //Конструктор без параметров
    Student(const char *surname, const char *group, int birth_year, const int *marks); //Конструктор с параметрами
    ~Student(); //Деструктор

//функции доступа
    void get_surname(char *name); 	//получить значение из поля surname в name
    const char *get_surname();	    //вернуть значение из поля surname

    void get_group(char *gr);		//получить значение из поля group в gr
    const char *get_group();		//вернуть значение из поля group

    int get_year();				    //вернуть значение из поля year
    void get_marks( int *mr);		//получить значение поля marks в mr
    int get_mark(int n); 			//вернуть оценку n из в массива оценок

    void set_surname(const char *sn); 	//установить  значение sn поле surname
    void set_group(const char *gr);	    //установить значение gr в поле group
    void set_year(int b_y);		        //установить значение b_y в поле birth_year
    void set_marks(const int *mrs);	    //установить значение из mrs в marks

//другие функции
    double aver_marks();    //вернуть значение средней оценки из массива marks
    void show(int new_line_before = 0, int new_line_after = 1);		    //вывести на печать информацию об отдельном объекте

    friend std::ostream &operator << (std::ostream &os, const Student &s);

};

#endif // STUDENT_H
