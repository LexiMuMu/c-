/*******************************************************
*      Filename: BigInteger.cpp                        *
*      Login: lm890                                    *
*      lab No: week 4 lab 3                            *
*      File Description: BigInteger functions          *
*      Date Last Modified: August 20th,2015            *
********************************************************/

#include <math.h>
#include <iostream>
#include "BigInteger-lm.h"
using namespace std;

int main()
{
	char number[50];
	char shift[50];
	int length = 0;

	//get the number from user
	cout << "Enter a BigInteger: ";
	cin.getline(number, 50, '\n');

	//intialize with char array
	//shift the array to intialize
	while(number[length] != '\0')
		length++;
	for(int i = 0; i < length; i++)
		shift[length - 1 - i] = number[i];
	shift[length] = '\0';
	BigInteger cinNum(shift);
	
	cout << "The BigInteger you enter: \n";
	cinNum.print(cout);
		
	//initialize with long long int
	BigInteger tmp(923456789012345);
	cout << "The BigInteger initialize inside:\n";
	tmp.print(cout);

	// add the BigInteger and initialize with copy constructor
	BigInteger add(tmp.add(cinNum));
	cout << "The result of adding them together:\n";
	add.print(cout);
}
