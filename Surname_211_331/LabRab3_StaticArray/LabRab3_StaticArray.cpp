// LabRab3_StaticArray.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void print_mas(int *temp_mas)
{
    for (unsigned int i = 0; i < 10; i++)
        std::cout << temp_mas[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int mas[10] = { 1,2,3,4,5,6,7,8,9,10 };
    for (unsigned int i = 0; i < 10; i++)
        std::cout << mas[i] << " ";
    std::cout << std::endl;

    mas[2] = 123;

    for (unsigned int i = 0; i < 10; i++)
        std::cout << mas[i] << " ";
    std::cout << std::endl;

    int number_int = 12;
    double number_double = 123.456;
    int* ptr_number_int = &number_int;
    double* ptr_number_double = &number_double;
    *ptr_number_int = 65432;
    std::cout << number_int << " " << ptr_number_int << " " << *ptr_number_int << std::endl;
    std::cout << number_double << " " << ptr_number_double << " "
        << *ptr_number_double << std::endl;

    for (unsigned int i = 0; i < 10; i++)
        std::cout << mas[i]<<" "<<*(mas+i)<<"\t"<< &mas[i] <<" "<< mas+i<< "\n ";
    std::cout << std::endl;

    int mas1[10] = { 1,2,3,4,5 };
    int mas2[10] = { 0,9,8,7,8,6,5,4,3 };

    print_mas(mas);
    print_mas(mas1);
    print_mas(mas2);


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
