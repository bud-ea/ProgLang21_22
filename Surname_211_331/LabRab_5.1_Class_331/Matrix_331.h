#pragma once
class Matrix_331
{
	/*
		1	2	3
		2	4	5	
	*/
private: //все внутри доступно только внутри класса
	int row, col;
	int* elem;
protected:
	// доступно внутри класса и наследникам
public:
	//доступно всем
	Matrix_331();//конструктор поумолчанию
	Matrix_331(int row_temp,int col_temp,int* arr);
	Matrix_331(const Matrix_331& temp);
	~Matrix_331();//деструктор

	void set_row(int temp);
	int get_elem(int i,int j) const;

	Matrix_331 mult(const Matrix_331& mat_right);
	Matrix_331 mult(const int* arr_mat_right,int arr_size);
	void print();
};

