#include "Matrix.h"

Matrix::Matrix()
{
}

Matrix::Matrix(int row, int col)
{
	size_col = col;
	size_row = row;
	elem = new double[col * row];
	for(int i=0;i< col * row;i++)
	{
		elem[i] = 0;
	}
}

Matrix::Matrix(int size)
{
	size_col = size;
	size_row = size;
	elem = new double[size * size];
	for (int i = 0; i < size * size; i++)
	{
		elem[i] = 0;
	}
}

Matrix::Matrix(const Matrix& temp)
{
	this->size_col = temp.size_col;
	this->size_row = temp.size_row;
	this->elem = new double[(temp.size_col) * (temp.size_row)];
	for (int i = 0; i < temp.size_col * temp.size_row; i++)
	{
		this->elem[i] = temp.elem[i];
	}
}

Matrix::~Matrix()
{
	if (elem != nullptr)
		delete[] elem;
}

Matrix Matrix::mult_number(int number)
{
	Matrix res(this->size_row, this->size_col);
	for (int i = 0; i < this->size_col * this->size_row; i++)
		res.elem[i] = this->elem[i] * number;
	// TODO: вставьте здесь оператор return
	return res;
}

void Matrix::mult_number_this(int number)
{
	for (int i = 0; i < this->size_col * this->size_row; i++)
		this->elem[i] = this->elem[i] * number;
	// TODO: вставьте здесь оператор return
}

/// <summary>
/// Метод для вычисления произведения матриц. 
/// В случае невозможности вычислить, метод возвращает текущую матрицу.
/// Сама матрица не меняется.
/// </summary>
/// <param name="temp"> матрица, на которую умножаем</param>
/// <returns></returns>
Matrix Matrix::mult_matrix(const Matrix& temp)
{
	/*
	Matr(this) * Matr (temp) = Matr(res)
	
	1 2 3      3 5     1*3+2*2+3*7   1*5+2*6+3*4
	4 5 6  *   2 6  =  4*3+5*2+6*7   4*5+5*6+6*4
	           7 4     
	*/
	if (this->size_col != temp.size_row) return *this;

	Matrix res(this->size_row, temp.size_col);

	for(int i=0;i<res.size_row;i++)
		for (int j = 0; j < res.size_col; j++)
		{
			res.elem[i * res.size_col + j] = 0;
			for (int k = 0; k < this->size_col; k++)
				res.elem[i * res.size_col + j] +=
				this->get_elem(i, k) * temp.get_elem(k,j);
		}	
	return res;
}

Matrix Matrix::mult_matrix(double* arr,int size)
{
	/*
	Matr(this) * Matr (temp) = Matr(res)

	1 2 3      3 5     1*3+2*2+3*7   1*5+2*6+3*4
	4 5 6  *   2 6  =  4*3+5*2+6*7   4*5+5*6+6*4
			   7 4
	*/

	int row = this->size_col;
	int col = size / row;
	if (!(size%row)) return *this;

	Matrix res(this->size_row, col);

	for (int i = 0; i < res.size_row; i++)
		for (int j = 0; j < res.size_col; j++)
		{
			res.elem[i * res.size_col + j] = 0;
			for (int k = 0; k < this->size_col; k++)
				res.elem[i * res.size_col + j] +=
				this->get_elem(i, k) * arr[k * col + j];
		}
	return res;
}

