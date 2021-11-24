#include "Matr3Diag.h"

Matr3Diag::Matr3Diag()
{
	n = 0;
	elem = nullptr;
}

Matr3Diag::Matr3Diag(const Matr3Diag& temp)
{
	this->n = temp.n;
	this -> elem = new double[3 * this->n];
	for (int i = 0; i < 3 * this->n; i++)
		this->elem[i] = temp.elem[i];
}

Matr3Diag::~Matr3Diag()
{
	if (this->elem != nullptr)
		delete[]this->elem;
}

double Matr3Diag::get_elem(int i, int j) const
{
	/*
					 a[n + i]	i == j
		elem[i, j] = a[2n + i]	i == j + 1
					 a[i]	i + 1 == j
					 0	else
	*/
	if (i == j) 
		return this->elem[this->n + i];
	else if (i == j+1)
		return this->elem[2*this->n + i];
	else if (i == j-1)
		return this->elem[i];
	else
		return 0.0;
}

Matr3Diag Matr3Diag::sum(const Matr3Diag& temp)
{
	if (this->n != temp.n)
		return *this;
	Matr3Diag res(temp);
	for (int i = 0; i < 3*this->n; i++)
		res.elem[i] += this->elem[i];
	return res;
}

void Matr3Diag::print() const
{
	for (int i = 0; i < this->n; i++)
	{
		for (int j = 0; j < this->n; j++)
			std::cout << this->get_elem(i, j) << "\t";
		std::cout << std::endl;
	}
}

void Matr3Diag::input(int size)
{
	this->n = size;
	if(this->elem != nullptr)
		delete[]this->elem;
	this->elem = new double[3 * this->n];
	for (int i = 0; i < 3 * this->n; i++)
		this->elem[i] = i+1;
	this->elem[this->n - 1] = 0;
	this->elem[2*this->n] = 0;
}

void Matr3Diag::operator+=(const Matr3Diag& temp)
{
	//*this = this->sum(temp);
	if (this->n == temp.n)
	{
		for (int i = 0; i < 3*this->n; i++)
			this->elem[i] += temp.elem[i];
	}
}

std::ostream& operator<<(std::ostream& out, const Matr3Diag& temp)
{
	for (int i = 0; i < temp.n; i++)
	{
		for (int j = 0; j < temp.n; j++)
			out << temp.get_elem(i, j) << "\t";
		out << std::endl;
	}
	return out;
}
