#include "Matr3Diag.h"
#include<iostream>

Matr3Diag::Matr3Diag()
{
	this->size = 0;
	this->elem = nullptr;
}

Matr3Diag::Matr3Diag(const Matr3Diag& matr)
{
	this->size = matr.size;
	this->elem = new double[3*this->size];
	for (int i = 0; i < 3 * this->size; i++)
		this->elem[i] = matr.elem[i];
}

Matr3Diag::~Matr3Diag()
{
	if (this->elem != nullptr)
		delete[]this->elem;
}

void Matr3Diag::print() const
{
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++) {
			std::cout << this->get_elem(i, j) << "  ";
		}
		std::cout << std::endl;
	}
}

double Matr3Diag::get_elem(int i, int j) const
{
	/*
			a_n+i	i==j
	a[i,j] =a_i	    i==j-1
			a_2n+i	i==j+1
			0	else
	*/
	if (i == j) return this->elem[this->size + i];
	else if (i == j-1) return this->elem[i];
	else if (i == j+1) return this->elem[2*this->size + i];
	else return 0.0;
}

int Matr3Diag::get_size() const
{
	return this->size;
}

void Matr3Diag::input(int n)
{
	if (this->elem != nullptr)
		delete[] this->elem;
	this->elem = new double[3 * n];
	this->size = n;
	for (int i = 0; i < 3 * n; i++)
		this->elem[i] = i + 1;
	this->elem[n - 1] = 0;
	this->elem[2*n] = 0;
}

void Matr3Diag::operator+=(const Matr3Diag& temp)
{
	if (this->size == temp.size)
	{
		for (int i = 0; i < 3 * this->size; i++)
			this->elem[i] += temp.elem[i];
	}
}

std::ostream& operator<<(std::ostream& out, 
	const Matr3Diag& temp)
{
	for (int i = 0; i < temp.size; i++)
	{
		for (int j = 0; j < temp.size; j++) {
			out << temp.get_elem(i, j) << "  ";
		}
		out << std::endl;
	}
	return out;
}

Matr3Diag operator+(const Matr3Diag& matrA, const Matr3Diag& matrB)
{
	Matr3Diag res(matrA);
	if (matrA.get_size() != matrB.get_size())
	{
		return res;
	}	
	res+=matrB;
	return res;
}
