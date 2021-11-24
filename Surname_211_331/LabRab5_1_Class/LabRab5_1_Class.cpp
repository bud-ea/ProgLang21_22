// LabRab5_1_Class.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Matrix.h"

class Warrior
{
private:
    //доступ только внутри класса
    int uron, zdorovie;
    std::string pict;
    int* ekipirovka;
public:
    //доступ есть везде
    int x, y;
    bool set_uron(int temp);
    //конструктор - для создания члена класса
    //конструкторов может быть несколько
    Warrior();//по-умолчанию
    Warrior(int init_uron, int init_zdor);//инициальзтрующий
    Warrior(Warrior& temp); //копирующий

    ~Warrior();//деструктор
protected:
    //доступ у наследников, извне доступа нет
};

bool Warrior::set_uron(int temp)
{
    this->uron = temp;
    return true;
}

Warrior::Warrior()
{
    this->uron = 0;
    this->zdorovie = 100;
    this->pict = "";
    this->ekipirovka = nullptr;
    this->x = 0;
    this->y=0;
}

Warrior::Warrior(int init_uron, int init_zdor)
{
    this->uron = init_uron;
    this->zdorovie = init_zdor;
    this->pict = "";
    this->ekipirovka = nullptr;
    this->x = 0;
    this->y = 0;
}

Warrior::Warrior(Warrior& temp)
{
    this->uron = temp.uron;
    this->zdorovie = temp.zdorovie;
    this->pict = temp.pict;

    this->ekipirovka = new int[int(sizeof(temp.ekipirovka))/int(sizeof(int))];
    for (int i = 0; i < int(sizeof(temp.ekipirovka)) / int(sizeof(int)); i++)
    {
        this->ekipirovka[i] = temp.ekipirovka[i];
    }
    this->x = temp.x;
    this->y = temp.y;
}

Warrior::~Warrior() 
{
    if(this->ekipirovka!=nullptr)
        delete[] this->ekipirovka;
}

struct Luchnik
{
    int dalnost;
    Warrior war;
};

struct Mechnik
{
    int radius;
    Warrior war;
};

void goto_Luchnik(Luchnik& temp)
{
    temp.war.x += 20;
    temp.war.y += 30;
}


int main()
{
//    Luchnik army_luch[10];
  //  army_luch[1].x = 100;
    Matrix MatrA(3,4);
    for (int i = 0; i < 12; i++)
        MatrA.elem[i] = i;
    Matrix MatrB(MatrA.mult_number(2));
    std::cout << "Hello World!\n"
        << "MatrB.elem[5] = " << MatrB.elem[5];

    std::cout << "\nHello World!\n"
        << "MatrA.mult_number(-1).elem[5] = ";
    std::cout << MatrA.mult_number(-1).elem[5];
    std::cout << "\nMatrA.elem[5] = " << MatrA.elem[5]<<std::endl;

    MatrA.mult_number_this(-1);
    std::cout << "Hello World!\n"
        << "\nMatrA.elem[5] = " << MatrA.elem[5] << std::endl;

    Matrix MatrC(4, 2);
    for (int i = 0; i < 8; i++)
        MatrC.elem[i] = i;

    std::cout << "\nMatrA = \n";
    MatrA.print();
    std::cout << "\nMatrC = \n";
    MatrC.print();
    std::cout << "\nMatrA*MatrC = \n";
    (MatrA.mult_matrix(MatrC)).print();




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
