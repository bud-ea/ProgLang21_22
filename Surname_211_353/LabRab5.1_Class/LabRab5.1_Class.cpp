﻿// LabRab5.1_Class.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

/*задача описать всех героев некоторой стратегии, их способности,
* внешний вид, и т.д.
* описать все действия, которые с ними можно делать.
*/
///герой - 
///тип вооружения - short
///здоровье - unsigned short
///положение - x,y - short
///экипировка - int*


/*Способ 1
int main()
{
    short vooruzhenie_luch[10], vooruzhenie_mech[10];
    unsigned short zdor_luch[10], zdor_mech[10];
    short x_luch[10], y_luch[10], x_mech[10], y_mech[10];

    /// Проблема: легко запутаться с индексацией
    
    /// Если хотим добавить 1 лучника, 
    /// то придется вносить исправления во все массивы,
    /// которые характеризовать лучника (пока 4 штуки)
    
    std::cout << "Hello World!\n";
}
*/

/*Способ 2
struct Luchnik
{
    short vooruzhenie;
    unsigned short zdorovie;
    short x, y;
    short dalnost_strel;
    int* ekipirovka;
};

struct Mechnik
{
    short vooruzhenie;
    unsigned short zdorovie;
    short x, y;
    short dopolnitelnyy_uron;
    int* ekipirovka;
};

int main() 
{
    Luchnik army_Luch[10];
    Mechnik army_Mech[10];
    // Для добавления лучника 
    // нужно увеличить размер всего одного массива
    
    //Доступ к метаданным
    army_Luch[2].x = 10;
    army_Luch[7].y = 90;

    //Проблема 1. При создании персонажа все метаданные пустые,
    // выделяется только память под метаданные, более того,
    //память под метаданные-динамический массив выделяться не будут.

    //Проблема 2.
    //после работы со структурой место, которое было выделено под
    //динамический массив нужно очищать вручную!!!
    for (int i = 0; i < 10; i++)
    {
        delete[] army_Luch[i].ekipirovka;
        //delete[] army_Mech[i].ekipirovka;
    }
    return 0;
}
*/

/*Cпособ 3 - использовать классы*/
#include "Matrix_353.h"

//Две функции перегружают друг друга, если 
//они имеют одинаковое назвние и разный список аргументов

int func(int x,double y)
{
    return x;
}

double func(double x)
{
    return 2*x;
}

double func(double x,int y)
{
    return 2 * x;
}

int main()
{
    Matrix_353 matrA(4, 6);
    Matrix_353 matrB(matrA);
    std::cout << "matrA.get_elem(2,2) = " << matrA.get_elem(2, 2);
    std::cout << "\nmatrB.sum(matrA).get_elem(2, 2)= " 
        << matrB.sum(matrA).get_elem(2, 2);
    int mas[24] = { 1, 2, 3,4,5,6,7,8,9,0,1, 2, 3,4,5,6,7,8,9,0,1,2,3,4 };
    std::cout << "\nmatrB.sum(mas,24).get_elem(2, 2)= "
        << matrB.sum(mas,24).get_elem(2, 2);

    //matrA = Matrix_353(4,6,mas);
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
