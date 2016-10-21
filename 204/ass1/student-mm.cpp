/*******************************************************
*      Filename: student.cpp                           *
*      Login: lm890                                    *
*      lab No: assignment 1                            *
*      File Description: student functions             *
*      Date Last Modified: August 27th,2015            *
********************************************************/

#include <iostream>
#include <cstring>
#include <iomanip>
#include "student.h"
using namespace std;

Student::Student()
{
	num = 0;
}

Student::~Student()
{
	delete [] name;
}

int Student::getMark(int i)
{
	return mark[i];
}

char* Student::getName()
{
	return name;
}

void Student::setMark(int * tmp)
{
	for(int i = 0; i < 4; i++)
	{
		mark[i] = tmp[i];
		if(mark[i] != -1)
			num++;
	}
}

void Student::setName(char* tmp)
{
	name = new char[50];
	strcpy(name, tmp);
}

void Student::print()
{
	float total = 0;
	cout << setw(20) << left << name;
	for(int i = 0; i < 4; i++)
	{
		if(mark[i] == -1)
			cout << setw(7) << ' ';
		else
		{
			cout << setw(7) << mark[i];
			total += mark[i];
		}
	}
	cout << setw(7) << noshowpoint << total;
	cout << setw(10) << setprecision(4) 
		 << showpoint << total / num;
	cout << endl;
}
