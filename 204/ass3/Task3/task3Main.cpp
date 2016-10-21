/********************************************************************************
 * Filename: task3Main.cpp
 * Name & Student No.: Yanhong Ben, 4845675
 * ASS No: 3
 * File Description: main drive file of task 3 STL container
 *********************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

#include "website.h"
#include "webmanagement.h"

int main(int argc, char* argv[])
{
	Website listWebsite;
	WebManagement webManagement;
	char* filename = argv[1];
	
	webManagement.loadWebsite(filename);
	webManagement.run();

	return 0;
}

