// LabRab3.2_DynamicArray.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
void input_mas(int *& temp_mas, int& size)
{
    std::cin >> size;
    //Выделение памяти
    if (temp_mas != nullptr)
        delete[] temp_mas;

    temp_mas = new int[size];

    for (unsigned int i = 0; i < size; i++)
        std::cin >> temp_mas[i];
}

void print_mas(int* temp_mas,int size)
{
    for (unsigned int i = 0; i < size; i++)
        std::cout << temp_mas[i] << " ";
    std::cout << std::endl;
}

bool sort0(int large, int small) //сумма цифр на четных местах 
{
    return large > small;
}

// по возрастанию последней цифры;при равных последних цифрах, по убыванию чисел
bool sort1(int large, int small) 
{
    return large > small;
}

void bubble_sort(int* temp_mas, int size, bool type_of_sort) 
{
 for (int i=0;i<size;i++)
     for (int j = 0; j < i; j++)
     {
         if (
             //f(x) = x' &f(0) V x & f(1)
             !type_of_sort&& sort0(temp_mas[j],temp_mas[j + 1]) || 
             type_of_sort&& sort1(temp_mas[j], temp_mas[j + 1]))
         {
             int b = temp_mas[j];
             temp_mas[j] = temp_mas[j + 1];
             temp_mas[j + 1] = b;
         }
     }
}


int main()
{
    int* mas = nullptr;
    int size_of_mas = 0;
    input_mas(mas, size_of_mas);
    
    print_mas(mas, size_of_mas);

    input_mas(mas, size_of_mas);


    bubble_sort(mas, size_of_mas, 0);
    print_mas(mas, size_of_mas);


    //освобождение памяти
    delete[] mas;
    return 0;
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
