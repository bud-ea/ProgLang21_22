#include "Matrix_352.h"
#include <iostream>

Matrix_352::Matrix_352()
{
	this->col = this->row = 0;
	this->elem = nullptr;
}

Matrix_352::Matrix_352(int size_row, int size_col)
{
	this->col = size_col;
	this->row = size_row;
	this->elem = new int[this->col*this->row];
	for (int i = 0; i < this->col * this->row; i++)
		this->elem[i] = i;
}

Matrix_352::Matrix_352(const Matrix_352& temp)
{
	this->col = temp.col;
	this->row = temp.row;
	this->elem = new int[this->col * this->row];
	for (int i = 0; i < this->col * this->row; i++)
		this->elem[i] = temp.elem[i];
}

Matrix_352::~Matrix_352()
{
	if( this->elem != nullptr)
		delete[] this->elem;
}

int Matrix_352::get_elem(int i, int j)
{
	return this->elem[i*col+j];
}

void Matrix_352::print()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			std::cout << this->get_elem(i, j) << "\t";
		std::cout << std::endl;
	}
}

Matrix_352 Matrix_352::sum(int number)
{
	Matrix_352 res(*this);
	for (int i = 0; i < res.col * res.row; i++)
		res.elem[i] += number;
	return res;
}
