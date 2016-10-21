/************************************************************
*      Filename: main.cpp                                   *
*      Login: lm890                                         *
*      lab No: Assignment 4                                 *
*      File Description:   *
*      Date Last Modified: 20/5/2015                        *
************************************************************/

#include <iostream>
#include "polynomial.h"
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	poly test;
	test.print();
	srand(time(0));
	double tmp[4] = {5,-1.2,10,0};
	poly init(tmp, 4);
	init.print();
	poly copy(init);
	copy.print();
	// copy.input();
	// copy.print();
	test = init;
	test.print();
	poly add(test.add(init));
	add.print();
	poly sub(test.sub(add));
	sub.print();
}