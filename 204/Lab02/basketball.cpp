/********************************************************************************
* Filename: competition.cpp                                        			   		
* Name & Student No.: Yanhong Ben, 4845675															
* Lab No: 2																		
* File Description: main drive file of basetball competitions										
* Date Last Modified: 14/08/2015                                				
*********************************************************************************/


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "competition.h"

int main()
{
	Result res;
	string filename;
	cout << "Input a basketball competition results' file name: ";
	getline(cin, filename);
	res.loadRecord(filename);
	res.sortRecord();
	res.printRecord();
	return 0;
}
