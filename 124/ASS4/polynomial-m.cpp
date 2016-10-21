/************************************************************
*      Filename: polynomial.cpp                             *
*      Login: lm890                                         *
*      lab No: Assignment 4                                 *
*      File Description:   *
*      Date Last Modified: 20/5/2015                        *
************************************************************/
#include <iostream>
#include "polynomial.h"
using namespace std;
// private:
// 	int degree;
// 	double* coefficient;

poly::poly()
{
	degree = -1;
	coefficient = NULL;
}

//the initialization constructor.
poly::poly(double tmp[], int size)
{
	degree = size;
	coefficient = new double [size];
	for(int i = 0; i < size; i++)
		coefficient[i] = tmp[i];
}

poly::poly(const poly& copy)
{
	degree = copy.degree;
	coefficient = new double [degree];
	for(int i = 0; i < degree; i++)
		coefficient[i] = copy.coefficient[i];
}

void poly::print()
{	
	if(coefficient == NULL)
	{
		cout << endl;
		return;
	}
	if(degree == 1)
		cout << coefficient[0] << endl;
	else if(degree == 2)
	{
		cout << coefficient[0] << 'x';
		if(coefficient[1] > 0)
			cout << '+' << coefficient << endl;
		else if(coefficient[1] < 0)
			cout << coefficient << endl;
	}
	else
	{
		if(coefficient[0] != 0 && coefficient[0] != 1 )
			cout << coefficient[0] << "x^" << degree - 1;
		else if(coefficient[0] == 1)
			cout << "x^" << degree - 1;

		for(int i = 1; i < degree - 2; i++)
		{		
			if (coefficient[i] == 1)
				cout << "+x^" << degree - i - 1;
			else if(coefficient[i] > 1)
				cout << '+' << coefficient[i] << "x^" << degree - i - 1;
			else if(coefficient[i] < -1)
				cout << coefficient[i] << "x^" << degree - i - 1;
			else if(coefficient[i] == -1)
				cout << "-x^" << degree - i;
		}
		if (coefficient[degree - 2] == 1)
			cout << "+x";
		else if(coefficient[degree - 2] > 1)
			cout << '+' << coefficient[degree - 2] << 'x';
		else if(coefficient[degree - 2] < -1)
			cout << coefficient[degree - 2] << 'x';
		else if(coefficient[degree - 2] == -1)
			cout << "-x";

		
		if(coefficient[degree - 1] > 0)
			cout << '+' << coefficient[degree - 1];
		else if(coefficient[degree - 1] < 0)
			cout << coefficient[degree - 1];
		cout << endl;
	}

}

void poly::input()
{
	int tmp;
	cout << "Degree:";
	cin >> tmp;
	if(tmp > degree)
	{
		delete [] coefficient;
		coefficient = new double [tmp];
		degree = tmp;
	}
	else 
	{
		for(int i = tmp; i < degree; i++)
			coefficient[i] = 0;
		degree = tmp;
	}
	cout << "Coefficients:";
	for(int i = 0; i < degree; i++)
	{
		cin >> coefficient[i];
	}
}
// 	poly(poly &);
poly::~poly()
{
	delete [] coefficient;
}

void poly::operator =(const poly& a)
{	
	if(a.degree > degree)
	{
		degree = a.degree;
		delete [] coefficient;
		coefficient = new double [degree];
		for(int i = 0; i < degree; i++)
			coefficient[i] = a.coefficient[i];
	}
	else
	{
		for(int i = a.degree; i < degree; i++)
			coefficient[i] = 0;
		for(int i = 0; i < degree; i++)
			coefficient[i] = a.coefficient[i];
	}
}

poly poly::add(const poly &a)
{
	int tmp, size;
	poly tmpPoly;
	if(a.degree > degree)
	{
		size = a.degree;
		tmp = degree;
	}
	else 
	{
		tmp = a.degree;
		size = degree;
	}
	tmpPoly.coefficient = new double [size];
	for(int i = size - 1; i >= size - tmp; i--)
		tmpPoly.coefficient[i] = a.coefficient[i] + coefficient[i];
	if(a.degree > degree)
	{
		for(int i = 0; i < size - tmp; i++)
			tmpPoly.coefficient[i] = a.coefficient[i];
	}
	else
	{
		for(int i = 0; i < size - tmp; i++)
			tmpPoly.coefficient[i] = coefficient[i];
	}
	tmpPoly.degree = size;
	return tmpPoly;
}

poly poly::sub(const poly &a)
{
	int tmp, size;
	poly tmpPoly;
	if(a.degree > degree)
	{
		size = a.degree;
		tmp = degree;
	}
	else 
	{
		tmp = a.degree;
		size = degree;
	}
	tmpPoly.coefficient = new double [size];
	for(int i = size - 1; i >= size - tmp; i--)
		tmpPoly.coefficient[i] = coefficient[i] - a.coefficient[i];
	if(a.degree > degree)
	{
		for(int i = 0; i < size - tmp; i++)
			tmpPoly.coefficient[i] = 0 - a.coefficient[i];
	}
	else
	{
		for(int i = 0; i < size - tmp; i++)
			tmpPoly.coefficient[i] = coefficient[i];
	}
	tmpPoly.degree = size;
	return tmpPoly;
}
