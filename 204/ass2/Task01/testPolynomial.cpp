/********************************************************************************
* Filename: testPolynomial.cpp                                         			   		
* Name & Student No.: Yanhong Ben, 4845675															
* ASS No: 2																		
* File Description: main drive file of task 1 polynomial handling										
* Date Last Modified: 27/09/2015                                				
*********************************************************************************/

#include <iostream>
#include <fstream>
#include "polynomial.h"

using namespace std;

int main()
{
	cout << "Input polynomial 1: ";
	Polynomial p1;
	cin >> p1;
	cout << "p1(x) = " << p1 << endl;
	cout << endl;

	cout << "Input polynomial 2: ";
	Polynomial p2;
	cin >> p2;
	cout << "p2(x) = " << p2 << endl;
	cout << endl;

	cout << "Copy p2 to p3, p3(x) = ";
	Polynomial p3;
	p3 = p2;
	cout << p3 << endl;

	cout << "p3(x)=p1(x) + p2(x) = ";
	p3 = p1 + p2;
	cout << p3 << endl;
	cout << endl;

	cout << "p3(x)=p1(x) - p2(x) = ";
	p3 = p1 - p2;
	cout << p3 << endl;
	cout << endl;

	cout << "p3(x)=p2(x) - p1(x) = ";
	p3 = p2 - p1;
	cout << p3 << endl;
	cout << endl;

	cout << "p3(x)=p1(x) * p2(x) = ";
	p3 = p1 * p2;
	cout << p3 << endl;
	cout << endl;

	cout << "p3(x)=p2(x) / p1(x) = ";
	p3 = p2 / p1;
	cout << p3 << endl;
	cout << endl;

	cout << "p3(x)=p1(x) / p2(x) = ";
	p3 = p1 / p2;
	cout << p3 << endl;
	cout << endl;

	cout << "p3(x)=p1(x) % p2(x) = ";
	p3 = p1 % p2;
	cout << p3 << endl;
	cout << endl;

	cout << "p3(x)=p2(x) % p1(x) = ";
	p3 = p2 % p1;
	cout << p3 << endl;
	cout << endl;

	return 0;
}


