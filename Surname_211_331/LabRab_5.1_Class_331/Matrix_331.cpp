#include "Matrix_331.h"
#include<iostream>

Matrix_331::Matrix_331()
{
	row = 0;
	col = 0;
	elem = nullptr;
}

Matrix_331::Matrix_331(int row_temp, int col_temp, int* arr)
{
	this->row = row_temp;
	this->col = col_temp;
	this->elem = new int[row * col];
	//нужна защита от дурака размер массива arr 
	//не обязан совпадать с row * col
	//либо проверить совпадение, 
	//либо допусловие в for
	for (int i = 0; i < row * col; i++)
		this->elem[i] = arr[i];
}

Matrix_331::Matrix_331(const Matrix_331& temp)
{
	this->row = temp.row;
	this->col = temp.col;
	this->elem = new int[row * col];
	for (int i = 0; i < row * col; i++)
		this->elem[i] = temp.elem[i];
}

Matrix_331::~Matrix_331()
{
	if (this->elem != nullptr)
		delete[]this->elem;
}

void Matrix_331::set_row(int temp)
{
	int* temp_arr = this->elem;
	this->elem = new int(temp * this->col);
	for (int i = 0; i < temp * this->col, i < this->row * this->col; i++)
		this->elem[i] = temp_arr[i];
	delete[] temp_arr;
	this->row = temp;
}

int Matrix_331::get_elem(int i, int j) const 
{
	return this->elem[i*col+j];
	/*
										j
	0			1			2			3	...		(col-1)
	col		col+1		col+ 2		col+ 3	...		(2col-1)
i	2col	2col+1		2col+2		2col+3	...		(3col-1)
	........................................................
(row-1)col (row-1)col+1 (row-1)col+2 (row-1)col+3...row*col-1
	
	*/


}

Matrix_331 Matrix_331::mult(const Matrix_331& mat_right)
{
	if (this->col != mat_right.row) return *this;

	int* res;
	int res_col = mat_right.col;
	int res_row = this->row;
	res = new int[res_row * res_col];
	for(int i=0;i<res_row;i++)
		for (int j = 0; j < res_col; j++)
		{
			res[i * res_col + j] = 0;
			for (int k = 0; k < this->col; k++)
				res[i * res_col + j] += 
				this->get_elem(i, k) * mat_right.get_elem(k, j);
		}
	return Matrix_331(res_row,res_col,res);
}

Matrix_331 Matrix_331::mult(const int* arr_mat_right, int arr_size)
{
	/*
		 ___col_____		 _______
		|			|		|		|
  row	|			|	*   |	arr	|
		|			|		|		|
		 ___________		 _______
							arr_row*arr_col = arr_size 
							arr_row = this->col
	*/


	//std::cout << sizeof(arr_mat_right) / sizeof(int);
	int* res;
	int res_row = this->row;
	int res_col = arr_size/this->col;
	
	if (arr_size%this->col != 0) return *this;

	res = new int[res_row * res_col];
	for (int i = 0; i < res_row; i++)
		for (int j = 0; j < res_col; j++)
		{
			res[i * res_col + j] = 0;
			for (int k = 0; k < this->col; k++)
				res[i * res_col + j] +=
				this->get_elem(i, k) * arr_mat_right[k*res_col+j];
		}
	Matrix_331 result_mat(res_row, res_col, res);
	return result_mat;
}

void Matrix_331::print()
{
	
		int k = 0;
		std::cout << "Matrix: " << std::endl;
		for (int i = 0; i < row; i++) {
			for (int i = 0; i < col; i++) {
				std::cout << elem[k] << " ";
				k++;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
}
