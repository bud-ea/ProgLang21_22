#include "Matrix_353.h"
#include <iostream>
Matrix_353::Matrix_353()
{
	this->row = 0;
	this->col = 0;
	this->elem = nullptr;
}

Matrix_353::Matrix_353(const Matrix_353& temp)
{
	this->row = temp.row;
	this->col = temp.col;
	this->elem = new int[this->row * this->col];
	for (int i = 0; i < this->row * this->col; i++)
		this->elem[i] = temp.elem[i];
}

Matrix_353::Matrix_353(short rows, short cols)
{
	this->row = rows;
	this->col = cols;
	this->elem = new int[rows*cols];
	for (int i = 0; i < rows * cols; i++)
		this->elem[i] = i * 37 % 19;
}

Matrix_353::Matrix_353(short rows, short cols,const int* arr)
{
	this->row = rows;
	this->col = cols;
	this->elem = new int[rows * cols];
	for (int i = 0; i < rows * cols; i++)
		this->elem[i] = arr[i];
}

Matrix_353::~Matrix_353()
{	
	if(this->elem != nullptr)
		delete[]this->elem;
}

int Matrix_353::get_elem(short i, short j)
{
	if (i >= 0 && j >= 0 && i < this->row && j < this->col)
		return this->elem[i * this->col + j];
	else
	{
		std::cout << "\nIndex error in get_elem.\n";
		return 0;
	}
}

Matrix_353 Matrix_353::sum(const Matrix_353& temp)
{
	Matrix_353 res(temp);
	//если размеры совпадают
	for (int i = 0; i < this->row * this->col; i++)
		res.elem[i] = this->elem[i] + temp.elem[i];
	return res;
}

Matrix_353 Matrix_353::sum(const int* arr, int size)
{
	//if подходящий размер
	return this->sum(Matrix_353(this->row,this->col,arr));
}
