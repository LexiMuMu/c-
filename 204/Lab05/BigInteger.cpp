/********************************************************************************
* Filename: BigInteger.cpp                                         			   		
* Name & Student No.: Yanhong Ben, 4845675															
* Lab No: 5																
* File Description: implementation file of Big Integer										
* Date Last Modified: 04/09/2015                                				
*********************************************************************************/

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

#include "BigInteger.h"


BigInteger::BigInteger()
{
	ptr = NULL;
	size = 0;
}

BigInteger::~BigInteger()
{
	if (ptr != NULL)
		delete [] ptr;
	ptr = NULL;
}

BigInteger::BigInteger(const char arr[])
{
	size = strlen(arr);
	ptr = new unsigned short[size];
	for (int i = 0; i < size; i++)
		ptr[size - i - 1] = static_cast<int>(arr[i]) - 48;//change char type to int
			
}

BigInteger::BigInteger(const BigInteger& org)
{
	//deep copy
	size = org.size;
	ptr = new unsigned short[size];
	for (int i = 0; i < size; i++)
		ptr[i] = org.ptr[i];
}

BigInteger BigInteger::operator=(const BigInteger &org)
{
	if (this == &org) //if the current object is the same as org
		return *this;
	if (ptr != NULL) //if the object already exists
		delete [] ptr;

	size = org.size;
	ptr = new unsigned short[size];

	for (int i = 0; i < size; i++)
		ptr[i] = org.ptr[i];
	return *this;
}

BigInteger BigInteger::operator+(const BigInteger &org)
{
	BigInteger des;
	if (org.size > size)
		des.size = org.size + 1;
	else
		des.size = size + 1;
	//find the size of the bigger int and made the 3rd dyanmic array's size 1 size bigger

	des.ptr = new unsigned short[des.size];

	//initilize 3rd short array to 1 size bigger than the bigger int and elements all set to 0
	//to prevent segmentation fault
	for (int i= 0; i < des.size; i++)
		des.ptr[i] = 0;

	//copy initialization big intger to 3rd array
	for (int i= 0; i < size; i++)
		des.ptr[i] = ptr[i];

	int t1 = 0, t2 = 0;
	for (int i = 0; i < des.size; i++)
	{
		if (i < org.size)
			t1 = des.ptr[i] + org.ptr[i] + t2;
		else
			t1 = des.ptr[i] + t2;
		t2 = t1 / 10;
		des.ptr[i] = t1 % 10;
	}
	if (des.ptr[des.size - 1] == 0)
		des.size --;
	//check if the last element in the array is 0 or not.
	return des;
}

BigInteger BigInteger::operator*(const BigInteger &org)
{
	int largeSize;
	largeSize = (size > org.size? size+1: org.size+1);

	BigInteger resultInt;
	resultInt.size = size + org.size;
	resultInt.ptr = new unsigned short[resultInt.size];

	for(int k = 0; k < resultInt.size; k++)//initialize resultInt to 0
		resultInt.ptr[k] = 0;

	int tempArr[40];
	for (int i = 0; i < size; i++)
	{
		for (int p = 0; p < largeSize; p++)//initialize tempArr to 0
			tempArr[p] = 0;

		int temp = 0, mod = 0;
		for (int j = 0; j < org.size; j++)
		{
			mod = (ptr[i] * org.ptr[j] + temp) % 10;
			temp = (ptr[i] * org.ptr[j] + temp) / 10;
			tempArr[j] = mod;
			if (j == org.size - 1)
				tempArr[j+1] = temp;//save every time multiplication result to a temporary array
		}

		int t1 = 0, t2 = 0;
		for (int j = 0; j < largeSize; j++)
		{
			t1 = resultInt.ptr[i+j] + tempArr[j] + t2;
			t2 = t1 / 10;
			resultInt.ptr[i+j] = t1 % 10;//add result to the new big integer
		}
	}
	if (resultInt.ptr[resultInt.size -1] == 0)
		resultInt.size--;
	return resultInt;
}


bool BigInteger::operator==(const BigInteger& org)
{
	if (org.size != size)
		return false;
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (org.ptr[i] != ptr[i])
				return false;
		}
		return true;
	}
}


//out class functions
ostream& operator<<(ostream& out, const BigInteger &org)
{
	for (int i = org.size - 1; i >= 0; i--)
		out << org.ptr[i];
	return out;
}

istream& operator>>(istream &in, BigInteger &org)
{
	string tempin;
	in >> tempin;
	BigInteger temp(tempin.c_str());
	org = temp;
	return in;
}


