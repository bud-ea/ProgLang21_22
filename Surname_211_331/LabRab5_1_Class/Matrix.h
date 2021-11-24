#pragma once
#include <iostream>
class Matrix
{
	//свойства класса
//private:
public://исправить!!!!!!!!!!!!!!!!!
	int size_col, size_row;
	double* elem;
//методы
public:
	Matrix();
	Matrix(int row, int col);
	Matrix(int size);
	Matrix(const Matrix& temp);
	~Matrix();

	void mult_number_this(int number);
	Matrix mult_number(int number); //умножение на число
	Matrix mult_matrix(const Matrix& temp); //умножение на матрицу temp
	Matrix mult_matrix(double* arr, int size);
											
											//!!!!!
	double get_elem(int i, int j) const { return elem[i * size_col + j];}
	void print() {
		int k = 0;
		std::cout << "Matrix: " << std::endl;
		for (int i = 0; i < size_row; i++) {
			for (int i = 0; i < size_col; i++) {
				std::cout << elem[k] << " ";
				k++;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

};