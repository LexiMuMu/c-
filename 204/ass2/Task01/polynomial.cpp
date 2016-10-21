/********************************************************************************
* Filename: polynomial.cpp                                         			   		
* Name & Student No.: Yanhong Ben, 4845675															
* ASS No: 2																		
* File Description: implementation file of task 1 polynomial handling										
* Date Last Modified: 27/09/2015                                				
*********************************************************************************/

#include <iostream>
#include "polynomial.h"
using namespace std;


//default constructor
Polynomial::Polynomial()
{
	length = 0;
	coeff = NULL;
}

//destructor
Polynomial::~Polynomial()
{
	delete [] coeff;
}

//copy constructor
Polynomial::Polynomial(const Polynomial &p)
{
	length = p.length;
	coeff = new double[length];
	for (int i=0; i<length; i++)
		coeff[i] = p.coeff[i];
}

//initialize the array
Polynomial::Polynomial(double* newCoeff, int newLength)
{
	length = newLength;
	coeff = new double[newLength];
	for(int i=0; i<newLength; i++)
		coeff[i] = newCoeff[i];
}

//overloading = to do the deep copy
void Polynomial::operator=(const Polynomial &p)
{
	if (p.length > length)
	{
		delete [] coeff;
		coeff = new double[p.length];
	}
	length = p.length;
	for (int i=0; i<length; i++)
		coeff[i] = p.coeff[i];
}

Polynomial Polynomial::operator+(const Polynomial &p)
{
	int bigLength;
	Polynomial result;

	//find the longer length
	if (p.length >= length)
		bigLength = p.length;
	else
		bigLength = length;

	result.coeff = new double[bigLength];
	for (int i=0; i<bigLength; i++)
		result.coeff[i] = coeff[i] + p.coeff[i];

	//deal with when value of the highest index is 0 after operation
	//causing wrong length
	while (result.coeff[bigLength-1] == 0 && bigLength != 0)
		bigLength--;
	result.length = bigLength;

	return result;
}

Polynomial Polynomial::operator-(const Polynomial &p)
{
	int bigLength;
	Polynomial result;
	//find the longer length
	if (p.length >= length)
		bigLength = p.length;
	else
		bigLength = length;

	result.coeff = new double[bigLength];
	for (int i=0; i<bigLength; i++)
		result.coeff[i] = coeff[i] - p.coeff[i];

	//deal with when value of the highest index is 0 after operation
	//causing wrong length
	while (result.coeff[bigLength-1] == 0 && bigLength != 0)
		bigLength--;
	result.length = bigLength;

	return result;
}

Polynomial Polynomial::operator*(const Polynomial &p)
{
	Polynomial result;
	int newLength = p.length + length - 1;
	result.coeff = new double[newLength];

	//initialize result array elements all to 0
	for (int i=0; i<newLength; i++)
		result.coeff[i] = 0;

	for (int i=0; i<length; i++)
	{
		for (int j=0; j<p.length; j++)
			result.coeff[i+j] += coeff[i] * p.coeff[j];
	}

	while (result.coeff[newLength-1] == 0 && newLength != 0)
		newLength--;
	result.length = newLength;

	return result;
}

Polynomial Polynomial::operator/(const Polynomial &p2)
{
	Polynomial result;
	if (length < p2.length)
		result.length = 0; //check if p1 degree is greater than p2, otherwise result is 0.
	else
	{
		Polynomial temp = *this; //copy to temp to avoid change to the original data
		result.length = temp.length - p2.length + 1;
		result.coeff = new double[result.length];

		for (int i=0; i<result.length; i++)
			result.coeff[i] = 0;
		//initialize the result array to 0

		int index = result.length - 1;
		double ttemp = 0.0;

		while(temp.length >= p2.length)
		{
			result.coeff[index] = temp.coeff[temp.length-1] / p2.coeff[p2.length-1];

			double middle = result.coeff[index];

			for (int j=p2.length-1; j>=0; j--)
			{
				ttemp = p2.coeff[j] * middle;
				temp.coeff[j+index] = temp.coeff[j+index] - ttemp;
			}
			index--;
			temp.length--;
		}
	}
	return result;
}

Polynomial Polynomial::operator%(const Polynomial &p)
{
		Polynomial temp = *this; 
		//copy to temp to avoid change to the original data

		int index = temp.length - p.length;
		double ttemp = 0.0;
		double middle = 0.0;

		while(temp.length >= p.length)
		{
			middle  = temp.coeff[temp.length-1] / p.coeff[p.length-1];

			for (int j=p.length-1; j>=0; j--)
			{
				ttemp = p.coeff[j] * middle;
				temp.coeff[j+index] = temp.coeff[j+index] - ttemp;
			}
			index--;
			temp.length--;
		}
	return temp;
}


//out of class function implementation
//implement insertion operator
istream& operator>>(istream & in, Polynomial & p)
{
	int newLength;
	in >> newLength;
	//if length is bigger than original one, delete old and create with longer length
	if (newLength > p.length)
	{
		//make sure array is not empty
		if (p.coeff != NULL)
			delete [] p.coeff;
		p.coeff = new double[newLength];
	}
	p.length = newLength;
	for (int i=0; i<p.length; i++)
		in >> p.coeff[i];
	return in;
}

//implement extraction operator
ostream& operator<<(ostream &out, Polynomial &p)
{
	int lowest = 0;
	for (int i = 0; i < p.length; i++)
	{
		if (p.coeff[lowest] == 0)
			lowest++;
	}
	//find out the lowest degree

	if (p.length == 0)
		out << 0;
	//deal with length equals to 0, print out 0

	for (int i=lowest; i<p.length; i++)
	{
		if (i > 0)
		{
			if (p.coeff[i] > 0 && p.coeff[i] != 0 && i != lowest)
				out << '+';
		}
		//handling + operator

		//deal with coefficient is not equal to 0, if equals 0 nothing to print out
		if (p.coeff[i] != 0)
		{
			//handling when degree is not 0
			if (i != 0)
			{
				//if coefficient is not 1, print coefficient. otherwise no printing x
				if (p.coeff[i] != 1 || p.coeff[i] != 1.0)
				{
					if (p.coeff[i] != -1 || p.coeff[i] != -1.0)
						out << p.coeff[i];
					else
						out << '-';
				}
				out << 'x';
				if (i != 1)
					out << '^' << i;
			}
			//handling when degree is 0, print no x
			else
				out << p.coeff[i];
		}

	}
	return out;
}



