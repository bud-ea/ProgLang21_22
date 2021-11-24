#pragma once
#ifndef Matrix_peremennaya
#define Matrix_peremennaya
class Matrix_353
{
	/*
	1	1	2
	3	2	3
	*/
private://�������� ������ �� ������ ������
	short row, col;
	int* elem;
protected://�������� ������ �� ������ ������ �
	//�� �������-�����������
public: //�������� ����
	Matrix_353();//����������� �� ���������
	Matrix_353(const Matrix_353& temp);//���������� �����������
	Matrix_353(short rows, short cols);
	Matrix_353(short rows, short cols, const int* arr);


	~Matrix_353();//����������

	int get_elem(short i,short j);
	Matrix_353 sum(const Matrix_353& temp);
	Matrix_353 sum(const int* arr, int size);

};



#endif // !Matrix_peremennaya


