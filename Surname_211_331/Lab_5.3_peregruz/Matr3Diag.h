#pragma once
#include <iostream>
class Matr3Diag
{
private:
	int size;
	double* elem;
public:
	Matr3Diag();
	Matr3Diag(const Matr3Diag& matr);
	~Matr3Diag();

	void print() const;
	double get_elem(int i, int j) const;
	int get_size() const;
	void input(int n);

	/*
	Перегрузка операторов
		- внутри класса (в ходе работы объект класса меняется,
		                  +=, -=, унарный -, ...)
		- в качестве дружественной функции (необходим доступ 
		                  к приватным члена класса)
		- вне класса
	*/

	void operator+= (const Matr3Diag& temp);//метод класса
	friend std::ostream& operator<<(
		std::ostream& out, const Matr3Diag& temp);
};

Matr3Diag operator+(const Matr3Diag& matrA, const Matr3Diag& matrB);

