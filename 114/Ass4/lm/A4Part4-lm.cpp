/*********************************************************************
*      Filename: A4Part4.cpp                                         *
*      Login: lm890                                                  *
*      lab No: Assignment 4                                          *
*      File Description: Recursion                                   *
*      Date Last Modified: 02/11/2014                                *
**********************************************************************/
#include <iostream>
using namespace std;

int sum(int, int);

int main()
{
	int i = 0, j = 0, result = 0;
	cout << "Input a number:";
	cin >> i;	
	cout << "Input another number:";
	cin >> j;

	//check if i is bigger than 0
	while(i < 0)
	{
		cout << "The first number cannot be negative!"
			 << endl;
		cout << "Input a number:";
		cin >> i;	
		cout << "Input another number:";
		cin >> j;
	}
	result = sum(i, j);
	cout << "The sum is " << result << endl;
}

int sum(int i, int j)
{
	if(i == 0)
		return j;
	else
		return sum(i - 1, j + 1);
}
