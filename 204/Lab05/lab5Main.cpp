/********************************************************************************
* Filename: lab5Main.cpp                                         			   		
* Name & Student No.: Yanhong Ben, 4845675															
* Lab No: 5																
* File Description: main drive file of Big Integer										
* Date Last Modified: 04/09/2015                                				
*********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

#include "BigInteger.h"

int main()
{
	BigInteger bi1;
	cout << "Input a big integer for bi1: ";
	cin >> bi1;
	cout << endl;

	BigInteger bi2;
	cout << "Input a big integer for bi2: ";
	cin >> bi2;
	cout << endl;

	BigInteger bi3("1234567890");
	cout << "Initial bi3 = " << bi3 << endl;

	bi3 = bi1 + bi2;
	cout << "bi3 = bi1 + bi2 = " << bi3 << endl;

	bi3 = bi1 * bi2;
	cout << "bi3 = bi1 * bi2 = " << bi3 << endl;

	if(bi1 == bi2)
		cout << "bi1 is equal to bi2" << endl;
	else
		cout << "bi1 is not equal to bi2" << endl;

	bi3 = bi2;
	cout << "bi3 = bi2 = " << bi3 << endl;

	if(bi3 == bi2)
		cout << "bi3 is equal to bi2" << endl;
	else
		cout << "bi3 is not equal to bi2" << endl;

	return 0;
}

