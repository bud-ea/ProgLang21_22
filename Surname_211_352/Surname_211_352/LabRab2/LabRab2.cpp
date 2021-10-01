// LabRab2.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>

void task_triangle()
{
	std::cout << "task_tr";
}

void task_Cnk()
{
	std::cout << "task_Cnk";
}
void task_average()
{
	std::cout << "task_av";
}

int main()
{
	int choice;
    
	while (true)
	{
		std::cout << "Menu: \n1. Triangle\n2. Cnk\n3. Average\n Input choice:";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			task_triangle();
			break;
		case 2:
			task_Cnk();
			break;
		case 3:
			task_average();//после последнего case break не несет смысловой нагрузки, но писать нужно
			break;
		default:
			return 0;
		}


	}
    
	return 0;
}

