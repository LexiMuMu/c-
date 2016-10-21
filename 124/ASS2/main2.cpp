/************************************************************
*      Filename: main2.cpp                                  *
*      Login: lm890                                         *
*      lab No: assignment 2                                 *
*      File Description: Do pivot quick sort with data read *
*      from a file.                                         *
*      Date Last Modified: 24/4/2015                        *
************************************************************/

#include <iostream>
#include "movement.h"
#include "sort.h"
using namespace std;

const int MAX = 11000;
const char inputfile[] = "movement.txt";
const char outputfile[] = "sorted_movement.txt";

int main()
{
	T array[MAX];

	int size;
	if((size = readfile(array, MAX, inputfile)) == 0)
	{
		cerr << "Error: failed to read file: " << inputfile << endl;	
		return -1;
	}

	int ncomp, nswap;
	//call quick sort function on a dataset from a file
	dpqsort(array, size, ncomp, nswap);
	cout << "Sorted " << size << " records in " 
		<< ncomp << " comparisons and "
		<< nswap << " swaps." << endl;

	//write sorted data into a file
	if(writefile(array, size, outputfile) == 0)
	{
		cerr << "Error: failed to write file: " << outputfile << endl;	
		return -1;
	}

}

