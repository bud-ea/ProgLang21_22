// LabRab_5.1_Class_352.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Matrix_352.h"

struct Warrior
{
    short vooruzhenie;
    unsigned short zdorovie;
    short x, y;
    int* ekipirovka;
};

struct Luchnik
{
    Warrior war;
    int dalnost_strel;
};

struct Mechnik
{
    Warrior war;
    int dopolnitelnyy_uron;
};
/*
void change_x(Warrior& temp)
{  
    temp.x += 100;
    Luchnik www;
    www.dalnost_strel = 0;
    delete[] www.war.ekipirovka;
}
*/
int main()
{
 /*   Luchnik luch;
    change_x(luch.war);
    luch.war.x;
    luch.dalnost_strel;
    std::cout << "Hello World!\n";
    delete[]luch.war.ekipirovka;

    */
    Matrix_352 matrA;
    Matrix_352 matrB(3,5);
    Matrix_352 matrC(matrB);

    std::cout << "matrB(3,5) = \n";
    matrB.print();
    std::cout << "matrC(matrB); matrC.sum(1) =  \n";
    (matrC.sum(1)).print();
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
