#pragma once
class Matrix_331
{
	/*
		1	2	3
		2	4	5	
	*/
private: //��� ������ �������� ������ ������ ������
	int row, col;
	int* elem;
protected:
	// �������� ������ ������ � �����������
public:
	//�������� ����
	Matrix_331();//����������� �����������
	Matrix_331(int row_temp,int col_temp,int* arr);
	Matrix_331(const Matrix_331& temp);
	~Matrix_331();//����������

	void set_row(int temp);
	int get_elem(int i,int j) const;

	Matrix_331 mult(const Matrix_331& mat_right);
	Matrix_331 mult(const int* arr_mat_right,int arr_size);
	void print();
};

