// LabRab4.2_String_File.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <cstring> // strcat(), strlen(), strcmp()
#include <string> // для c++ класса string
#include <fstream> // для работы с файлами через fstream, ifstream, ofstream
#include <bitset> // для двоичного формата записи в cout

// СТРОКИ И ФАЙЛЫ

// строки старого C-типа представляют из себя всего лишь массив символов с нулевым окончанием:
// в типе char на самом деле хранится знаковое целое число. Можно складывать, делить, умножать char
// чтобы придать симвльный смысл данным, хранимым в char, нужна таблица соответствия
// чисел с символами - кодовая таблица (ASCII, ANSI, UNICODE)

// ФУНКЦИИ ДЛЯ РАБОТЫ С C-СТРОКАМИ

// вывод на печать printf(char[], , , ) или printf(*char, , , ) - print formatted

// с помощью printf можно не просто печатать готовую строку
// но и подставлять в неё другие переменные, попутно преобразовывая их
// в символьный вид и применяя форматирование
// форматирование printf("базовая %s строка %f", параметр1, параметр2)

// позиции, куда будут подствляться параметры, обозначаются в базовой строке
// символом "%"

// значение сивмолов форматирования берётся из таблицы справки к функции http://www.cplusplus.com/reference/cstdio/printf/
// значение некоторых из них
// %f - параметр подставляется на место %f, оформленное в виде числа с плавающей точкой
// %s - параметр подставляется на место %s как строка
// %d - параметр подставляется на место %d как целое число
// %e - параметр подставляется на место %e как число в экспоненциальном виде

// В стандартной библиотеке C++ массив символов инкапсулирован в класс std::string
// в который также собраны самые часто используемые методы обработки
// и для которого перегружены операторы + (конкатенация), ввод, вывод и т.д.
// ещё одно отличие от строк C - длина строки теперь задаётся отдельным числом,
// а не нулевым окончанием


/*#define ANSI_COLOR_RED     "\33[0:31m\\]"
#define ANSI_COLOR_RESET   "\33[0m\\]"*/
using namespace std;
int main()
{
	char cstr1[] = "C-style string1";
	char cstr2[] = { 'C', '-', 's','t','y','l','e',' ','s','t','r','i','n','g','2','\0' };
	char cstr3[] = { '\67', '\45', '\115','t','y','l','e',' ','s','t','r','i','n','g','3','\0' };

	std::string cppstr1 = "C++ - style string 1";
	std::string cppstr2 = "";

	printf(cstr1);

	// в фукнцию передаётся массив char (а имя массива является УКАЗАТЕЛЕМ на самый первый элемент массива),
	// либо указатель *char
	printf("\n\n");

	printf("Parameter1 = %f, parameter2 = %d\n\n", 1.5, 100);

	//char nl = '\n';

	printf("Insert double: %f,\n"
		"insert long long: %d,\n" // целое число
		"insert string: %s,\n"
		"insert exponential: %e,\n" // мантисса - дробное число между >=1 и <2, умножаемое на 10^экспонента
		"insert double %f with pricision: %10.2f\n" // 10.2 - 10 пустых мест до запятой и 2 знака после
		"*ERROR insert long long as double: %10.2f\n" // ОШИБКА неверное приведение типов
		"*ERROR insert double as int: %010d\n", // ОШИБКА неверное приведение типов
		1000.15,
		132456789,
		"stirng =)",
		1123456.1123456,
		1.1123456,
		1.1123456,
		(long long)10000,
		10.5);

	// далее идут примеры работы со строками в C и эквивалентные примеры из C++
	// сравнение
	int i = strcmp(cstr1, cstr2);
	printf_s("Result of strcmp(%s, %s) = %d\n", cstr1, cstr2, i);
	cout << "Instead of strcmp() use (cppstr1 == cppstr2) = "
		<< (cppstr1 == cppstr2) << endl << endl; // для сравнения строк перегружен логический оператор "=="

	// длина строки
	int lngth = strlen(cstr1);
	printf_s("Result of strlen(%s) = %d\n", cstr1, lngth);
	cout << "Instead of strlen() use std::string.length():\t"
		<< cppstr1.length() << endl << endl; // для определения длины - метод length() класса string

	// копирование из одной строки в другую
	char cstr4[255];
	strcpy_s(cstr4, 255, cstr2); // требуется использование более сложного безопасного аналога strcpy_s()
	printf_s("Result of strcpy(%s, %s)\n", cstr4, cstr2);
	cppstr2 = cppstr1; // для копирования перегружен оператор "="
	cout << "Instead of strcpy() use operator =:\t"
		<< cppstr2 << endl << endl;

	// объединение строк
	strcat_s(cstr4, 255, cstr1);
	cout << "Result of strcat(cstr2, cstr1) = " << cstr4 << endl;
	cout << "Instead of strcat() use operator +:\t"
		<< (cppstr1 + cppstr2) << endl << endl; // для конкатенации прегружен "+"

	std::cout << "\nFind strlen(cstr1) - strlen(strstr(cstr1, \"sty\"))\t" << strlen(cstr1) - strlen(strstr(cstr1, "sty"));
	std::cout << "\n\ncppstr1 = " << cppstr1<<
		"\ncppstr1.find_first_of(\"str\")"<< cppstr1.find_first_of("str")<<endl<<endl;

	if (cppstr1.find("aaa") == std::string::npos)
	{
		cout << "cppstr1.at(25) = " << cppstr1.at(25);
		cout << "\ncppstr1[25] = " << cppstr1[25];
		cout << "\nCannot find \n\n";
	}


	std::string  example_string = "qwertyuio";
	example_string.find("ds");


	/*
	* написать набор функций для работы с файловой системой:
1.string file_format(const string file_path_full) 
	по введенному полному расположению файла получить расширение,
	file_path_full = 
	"C:\Users\bud-e\Lab 11 Strings and files\stdafx.cpp"
	вернуть подстроку, начиная с последнего вхождения точки и до конца file_path_full
	срр

2.string file_name(const string file_path_full) 
	по введенному полному расположению файла получить название, 
	file_path_full = "C:\Users\bud-e\Lab 11 Strings and files\stdafx.cpp"
	вернуть подстроку, начиная с последнего вхождения '\' и 
	до последнего вхождения точки в  file_path_full
	stdafx

3.string file_path (const string file_path_full) 
	по введенному полному расположению файла получить расположение,
	file_path_full = "C:\Users\bud-e\Lab 11 Strings and files\stdafx.cpp"
	вернуть подстроку с начала и до последнего вхождения '\' 
	C:\Users\bud-e\Lab 11 Strings and files

4.char file_disk (const string file_path_full) 
	по введенному полному расположению файла получить название диска,
	file_path_full = "C:\Users\bud-e\Lab 11 Strings and files\stdafx.cpp"
	вернуть начальный символ строки
	С

5.bool file_rename(string * file_path_full) 
	по введенному полному расположению файла и новому имени  переименовать файл, 
	file_path_full = "C:\Users\bud-e\Lab 11 Strings and files\stdafx.cpp"
	...
	cin>>new_name;
	file_path_full = "C:\Users\bud-e\Lab 11 Strings and files\" 
				+ new_name+ ".cpp";
	!!!!! В файловую систему не лезем  !!!!!

	file_path_full = "C:\Users\bud-e\Lab 11 Strings and files\stdafx_new_name.cpp"

6.bool file_copy(const string file_path_full) 
	по введенному полному расположению файла создать копию файла 
	(имя копии получается приписыванием  «_copy» к имени файла).
	
	ifstream fin; - поток чтения из файла источника file_path_full
	ofstream fout; - поток записи в файл-копию 
		Расположения(file_path_full)+"\"+
				Имя(file_path_full)+"_copy."+Расширение(file_path_full)

	Пока(не конец файла fin)
		fin>>temp;
		fout<<temp;

	fin.close();
	fout.close();
	*/

	// цикл работы с файлом заключается в
	//	0.1 Проверить, существует ли файл 
	// (в случае, если нужно открыть готовый)
	//	0.2 При работе в C++ - создать объект для работы с файлом
	//	1. Открытие файла
	//	2. Работа с файлом (чтение, запись, поиск)
	//	3. Закрытие файла

	// с ФС программа работает не напрямую, а через функции ОС:
	// функция_программы(чтение/запись/открытие) ->
	// функция ОС из системой dll (+доп. проверки, безопасность) ->
	// доступ к диску (барабан, головка, сектора)

	// работа с файлами на C аналогична работе со строками: указатель на файл + группа функций
	// более подробно - на самостоятельное изучение
	// https://www.tutorialspoint.com/cprogramming/c_file_io.htm

	// std::fstream - универсальный класс для ввода (чтения из файла) и для вывода (запись в файл)
	// std::ifstream - класс для ввода (чтения из файла)
	// std::ofstream - класс для вывода (запись в файл)
	// аналогично cout - потоку, предназначенному для вывода на консоль
	// fstream является потоком, предназначенным для ввода/вывода из/в файл

	//  fstream -> basic_fstream -> basic_iostream : public basic_istream, public basic_ostream

	fstream fs; // 0. Создание объекта при работе в C++

	// 1. Открытие файла
	fs.open("Some text file.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);
	//			0x01				0x02		0x10 = 16dec
	//		  0b0001			  0b0010			 0b10000

// fs.open("Some text file.txt", - при открытии файла необходимо указать имя файла
// а также режим открытия: с перезаписью или без, для чтения/для записи/ оба режима и т.д.
// std::fstream::in - добавлятеся режим вывода из файла
// std::fstream::out - добавляется режим записи в файл
// std::fstream::app - append добавляется режим с записью в конец файла
// std::fstream::trunc; - trunc = truncate - режим с перезаписью всего файла


// ВСПОМОГАТЕЛЬНЫЙ УЧЕБНЫЙ КОД: разбор, что такое режимы открытия и как шифруется информация в них
	auto fstream_mode = std::fstream::in | std::fstream::out | std::fstream::app;
	// чтобы не вникать в служебные типы стандартной библиотеки (что это там за mode) используется тип auto:
	// в зависимости от правой части выражения компилятор сам подбирает тип
	cout << "std::fstream::in | std::fstream::out | std::fstream::app = " 
		<< std::bitset<8>(fstream_mode) << endl;

	// 2. Собственно, работа с файлом. Вывод в файл
	fs << 1000.15 << endl
		<< 132456789 << endl
		<< "stirng =)" << endl
		<< 1123456.1123456 << endl
		<< 1.1123456 << endl
		<< (long long)10000 << endl
		<< 10.5 << endl;
	fs.close();

	return 0;
}
// выводы
/*
	- строки в C - просто массивы char
	- строки в C++ - классы, включающие все необходимые методы, хранилище для символов
	- char - арифметическое число. Соответствие между числами и, собственно, символами, задаётся
	кодовыми таблицами ASCII, ANSI, UNICODE
	- наиболее частые ошибки - несоответствие числа параметров printf и числа %,
	отсутствие нулевого окончания, попытки доступа к чужой памяти (неправильная работа
	с указателями и длинами)
*/
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
