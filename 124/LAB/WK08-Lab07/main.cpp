/*
	Word reader program based on a simple linked list
*/

#include <iostream>
#include <fstream>
#include "linkedList.h"
using namespace std;

int main()
{
	word* list;
	char buffer[MAX];
	char textfile[MAX];
	ifstream fin;

	cout << "Enter Text file to open: ";
	cin >> textfile;
	
	fin.open(textfile, ios::in);
	if (!fin.good())
	{
		cerr << "Can not open " << textfile 
			<< "  Exiting" << endl;
		return 1;
	}

	initialise(list);
	while(fin>>buffer)	//read into buffer and !fin.fail()
	{
		addnode(buffer, list);
	}
	printnodes(list);
	freelist(list);
	return 0;
}
