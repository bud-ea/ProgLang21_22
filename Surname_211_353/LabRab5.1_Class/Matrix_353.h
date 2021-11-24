#pragma once
#ifndef Matrix_peremennaya
#define Matrix_peremennaya
class Matrix_353
{
	/*
	1	1	2
	3	2	3
	*/
private://доступно только из самого класса
	short row, col;
	int* elem;
protected://доступно только из самого класса и
	//из классов-наследников
public: //доступно всем
	Matrix_353();//конструктор по умолчанию
	Matrix_353(const Matrix_353& temp);//копирующий конструктор
	Matrix_353(short rows, short cols);
	Matrix_353(short rows, short cols, const int* arr);


	~Matrix_353();//деструктор

	int get_elem(short i,short j);
	Matrix_353 sum(const Matrix_353& temp);
	Matrix_353 sum(const int* arr, int size);

};



#endif // !Matrix_peremennaya


