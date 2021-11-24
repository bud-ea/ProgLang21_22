// LabRab_5.1_Class_331.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include"Matrix_331.h"
#include <iostream>

double func1(int x)
{
    return x;
}

double func1(double x)
{
    return x;
}

int func1(int x,int y)
{
    return x+y;
}

/*int func1(int x)
{
    return x;
}
*/


struct Student
{
    std::string fio;
    std::string date_of_birth;
    int group_number;
    int* score;
};

void init_Student(Student& temp)
{
    temp.fio = "qwerty";
    temp.date_of_birth = "1234";
    temp.group_number = 331;
    temp.score = new int[3];
    for (int i = 0; i < 3; i++)
        temp.score[i] = 3 + (i + 1) % 2;
}

int main()
{
    //создать бд с полями ФИО, дата рождения, группа, успеваемость
    /*способ решения 1: создать по массиву на каждый столбец.
    std::string fio[100];
    std::string date_of_birth[100];
    .....
    Плохо: приводит к ошибкам, нужно внимательно следить за индексами.
    */
    /*Способ 2 - создать свой собственный тип данных
    * создается посредством struct, которая задается перед main

    Плохо: не чистится память автоматически, 
    объект постоянно нужно передавать в структуру,
    если перед инициализацией объекта нужно что-либо задать, то мы не можем.
    */
    /*Способ 3 - использование классов*/
    Student ivanov;
    Student petrov;
    Student group331[27]; //таблица из 27 строк
    init_Student(ivanov);
    std::cout << "ivanov.fio = "<< ivanov.fio;

    delete[] ivanov.score;

    std::cout << "\nHello World!\n";

    int mas[6] = { 1, 3, 5, 7,9,2 };
    Matrix_331 MatrA(2, 3, mas);
    std::cout << "\nMatrA.get_elem(0,0) = "
        <<MatrA.get_elem(0, 1);
    Matrix_331 MatrB(3, 2, mas);
    std::cout << "MatrA = \n";
    MatrA.print();
    std::cout << "MatrB = \n";
    MatrB.print();
    std::cout << "MatrA * MatrB = \n";
    MatrA.mult(MatrB).print();

    std::cout << "MatrB * mas = \n";
    MatrB.mult(mas,6).print();
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
