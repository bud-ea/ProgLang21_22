#pragma once
#include <iostream>
class Matr3Diag
{
private:
	int n;
	double* elem;
public:
	Matr3Diag();
	Matr3Diag(const Matr3Diag& temp);
	~Matr3Diag();//деструктор

	double get_elem(int i, int j) const;
	Matr3Diag sum(const Matr3Diag& temp);
	void print() const;
	void input(int size);

	/*Перегрузка операторов
	*	- как метод класса 
	*			меняется объект класса +=, -+, ++, --
	*	- как дружественная функция
	*			необходим доступ к private членам класса
	*	- вне класса
	*/
	void operator+=(const Matr3Diag& temp);

	friend std::ostream& operator<<(std::ostream& out, const Matr3Diag& temp);
};

