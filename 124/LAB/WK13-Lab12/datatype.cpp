/*********************************************************************
 Filename: datatype.cpp
 Name: Yanhong Ben, 4845675
 Time: Mon 8:30-10:30 17.106
 Lab No: 12
 File Description: implement three fundamental functions
 Date Last Modified: 02/06/2015
**********************************************************************/

#include <iostream>
using namespace std;

#include "datatype.h"

int cmp(const T& a, const T& b)
{
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else 
		return 0;
}

void copy(T& to, const T& from)
{
	to = from;
}

void print(const T& a)
{
	cout << a << " " ;
}

