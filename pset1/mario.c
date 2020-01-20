#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height; /*объявление переменной height (высота пирамиды)*/
    string sSpace = " ";
    do              /*начало цикла do-while, где фиксируется ввод значение height до тех пор, пока height больше нуля и меньше 23*/
        {       /*начало цикла*/
        printf ("Height: "); /*вывод на экран "Height: "*/
        height = get_int (); /*присваивание переменной height значения, введенного пользователем*/
        }       /*конец цикла*/
    while (height < 0 || height > 23); /*значение пользовательского ввода должно быть больше нуля и меньше 23*/
            for (int i = 0; i < height; i++) /*задаем высоту пирамиды*/
            {   /*начало цикла for i*/
            for (int j = 0; j < height-i-1; j++) /*задаем количество пробелов*/
            {   /*начало цикла for j*/
            printf ("%s", sSpace); /*вывод на экран пробелов*/
            }   /*конец цикла for j*/
            for (int k = 0; k < i + 1; k++) /*задаем количество решеток*/
            {   /*начало цикла for k*/
            printf ("#"); /*вывод на экран решеток*/
            }   /*конец цикла for k*/
            printf ("%s", sSpace);
            printf ("%s", sSpace);
            for (int k = 0; k < i + 1; k++) /*задаем количество решеток*/
            {   /*начало цикла for k*/
            printf ("#"); /*вывод на экран решеток*/
            }   /*конец цикла for k*/
            printf ("\n");
            }   /*конец цикла for i*/
}