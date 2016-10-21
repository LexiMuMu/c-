/*
	Driver program for DNA task
*/

#include <iostream>
#include <fstream>
using namespace std;

#include "dna.h"
#include "freq.h"

int main()
{
	const int FMAX = 30;
	char fileName[FMAX];
	ifstream ifs;
	ofstream ofs;
	
	cout << "\nEnter filename to read: ";
	cin >> fileName;
		
	ifs.open(fileName);
	
	if(ifs.good())
	{
		reverse_complement(ifs);
		ifs.close();
	}
	else
	{
		cerr << "File can not be opened for reading - exiting. " << endl;
		return 1;
	}
	
	cout << "Enter filename to write: ";
	cin >> fileName;

	ofs.open(fileName);
	
	if(ofs.good())
	{
		save(ofs);
		cout << " File Written." << endl;
	}
	else
	{
		cerr << " File can not be opened for writing - exiting. " << endl;
		return 1;
	}

	ofs.close();

	freq_comp();
	
	return 0;
}
