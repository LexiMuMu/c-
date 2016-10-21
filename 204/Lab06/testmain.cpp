/********************************************************************************
* Filename: testmain.cpp                                         			   		
* Name & Student No.: Yanhong Ben, 4845675															
* Lab No: 6															
* File Description: main drive file of publication										
* Date Last Modified: 06/09/2015                                				
*********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

#include "publication.h"

int main()
{
	string auth[3] = {"Jore Smith", "James Bond"};
	Book book("Object Oriented Programming Using C++", 2009, "Course Technology", "978-1-4239-0257-7", auth);

	Journal journal("ARS Combinatoric", 2015, "Charles Babbage Research Centre", "0381-7032", "S. A. Vanstone", 3);

	cout << endl;

	Publication *p1 = &book;
	cout << "A book:\n";
	static_cast<Book*>(p1)->print(cout);

	cout << endl;

	Publication *p2 = &journal;
	cout << "A journal:\n";
	static_cast<Journal*>(p2)->print(cout);

	cout << endl;

	return 0;
}

