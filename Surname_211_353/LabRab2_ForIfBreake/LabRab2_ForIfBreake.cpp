// LabRab2_ForIfBreake.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
void task1()
{
}

void task2()
{
}

void task3()
{
}

int main()
{
	int choice = 0;
	std::cout << "Your choice?\n1. task 1.\n2.task 2.\n2.task 2\n2.task 2\n2.task 2";

	std::cin >> choice;
	switch (choice)
	{
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	case 3:
		task3();
		break;
	default:
		break;
	}
    return 0;
}

