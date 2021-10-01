// LabRab2_ForIfBreake.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
void task1()
{
}

void task2()
{
	int n = 0;
	std::cout << "Input n:";
	std::cin >> n;
	//c_n^k = c_n^{k-1} * (n-(k-1))/k
	int C_n_k = 1;
	for (int k = 1; k <= n; k++)
	{
		std::cout << "C_n^" << k - 1 << " = " << C_n_k << std::endl;
		C_n_k = C_n_k * (n - (k-1)) / (k);
	}
	std::cout << "C_n^" << n << " = " << C_n_k << std::endl;
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

