/*******************************************************
*      Filename: BigInteger.cpp                        *
*      Login: lm890                                    *
*      lab No: week 4 lab 3                            *
*      File Description: BigInteger functions          *
*      Date Last Modified: August 20th,2015            *
********************************************************/

#include <iostream>
#include <math.h>
#include "BigInteger-lm.h"
using namespace std;

BigInteger::BigInteger()
{
	num = NULL;
	size = 0;
}

BigInteger::BigInteger(const BigInteger& copy)
{
	size = copy.size;
	num = new short int[size];
	for(int i = 0; i < size; i++)
		num[i] = copy.num[i];
}

BigInteger::BigInteger(long long int big)
{
	int arraySize = 0;

	//find out how many digits are there
	long long int tmp = big;
	while(tmp > 10)
	{
		arraySize++;
		tmp /= 10;
	}
	size = arraySize + 1;

	//assign the BigInterger
	num = new short int[size];
	for(int i = 0; i < size; i++)
	{
		num[i] = big % 10;
		big /= 10;
	}
}

BigInteger::BigInteger(char big[])
{
	int arraySize = 0;

	//find out the size
	while(big[arraySize] != '\0')
		arraySize++;

	//initialize the BigInteger
	num = new short int[arraySize];
	size = arraySize;
	for(int i = 0; i < arraySize; i++)
		num[i] = static_cast<int>(big[i]) - 48;
}

BigInteger::~BigInteger()
{
	delete [] num;
}

void BigInteger::print(ostream& out)
{
	if(size == 0)
	{
		out << 0 << endl;
		return;
	}

	for(int i = size - 1; i >= 0; i--)
		out << num[i];
	out << endl;
}

BigInteger BigInteger::add(const BigInteger& another)
{
	int arraySize = 0;
	int loop = 0;
	short int * bigger;
	short int * smaller;

	//determine the size of the result
	//determine the number of digits that needed to be add
	if(another. size > size)
	{
		arraySize = another.size + 1;
		bigger = another.num;
		loop = size;
		smaller = num;
	}
	else
	{
		arraySize = size + 1;
		bigger = num;
		loop = another.size;
		smaller = another.num;
	}

	//store the result
	short int * tmp = new short int[arraySize];
	//to initialize the BigInteger
	char * big = new char[arraySize + 1];
	
	//in case the result is bigger than 9
	int more = 0;
	//start adding
	for(int i = 0; i < loop; i++)
	{
		tmp[i] = bigger[i] + smaller[i] + more;
		more = 0;
		if(tmp[i] > 9)
		{
			tmp[i] = tmp[i] % 10;
			more = 1;
		}
	}

	for(int i = loop; i < arraySize - 1; i++)
	{
		tmp[i] = bigger[i] + more;
		more = 0;
		if(tmp[i] > 9)
		{
			tmp[i] = tmp[i] % 10;
			more = 1;
		}
	}

	//generate the char array
	for(int i = 0; i < arraySize; i++)
		big[i] = static_cast<char>(tmp[i] + 48);

	if(more == 1)
	{
		big[arraySize - 1] = '1';
		big[arraySize] = '\0';
	}
	else
		big[arraySize - 1] = '\0';

	//intialize a BigInteger to return
	BigInteger result(big);

	delete [] big;
	delete [] tmp;

	return result;

}
