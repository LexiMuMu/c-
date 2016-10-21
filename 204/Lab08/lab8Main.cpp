/********************************************************************************
 * Filename: lab8Main.cpp
 * Name & Student No.: Yanhong Ben, 4845675
 * Lab No: 8
 * File Description: main drive file of a linked list
 * Date Last Modified: 24/09/2015
 *********************************************************************************/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "stock.h"
#include "MyList.h"

using namespace std;
using namespace MyProject;


int main(int argc,char *argv[])
{
	srand (time(NULL));
	//insert some random integers into a linked list and print out all the doubles
	MyList<int> intList;
	for (int i=0; i<10; i++)
	{
		int temp = rand() % 100 + 1;
		intList.insert(temp);
	}
	cout << endl;
	cout << "list_i=";
	intList.print(cout);
	cout << endl << endl;


	//insert some random doubles into a linked list and print out all the doubles
	MyList<double> doubleList;
	for (int i=0; i<10; i++)
	{
		double temp = (double)rand() / (double)RAND_MAX;
		doubleList.insert(temp);
	}
	cout << "list_d=";
	doubleList.print(cout);
	cout << endl << endl;


	//open stock data file
	ifstream fin;
	fin.open(argv[1]);

	if (!fin.good())
	{
		cout << "Filename wrong." << endl;
		return 0;
	}

	//read data to stock instance array
	char tempChar[5];
	int tempCost;
	int tempVol;

	//insert random stock instance to the list.
	MyList<Stock> stockList;
	fin.getline(tempChar, 5, '\t');
	while (fin.good())
	{
		Stock tempStock;
		tempStock.setTag(tempChar);
		fin >> tempCost;
		tempStock.setCost(tempCost);
		fin >> tempVol;
		tempStock.setVol(tempVol);
		stockList.insert(tempStock);
		if(fin.peek() == '\t')
			fin.get();
		fin.ignore();
		fin.getline(tempChar, 5, '\t');
	}
	fin.close();

	cout << "list_s=";
	cout << endl;
	stockList.print(cout);
	cout << endl;


	return 0;
}

