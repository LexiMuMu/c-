/********************************************************************************
* Filename: pet.cpp                                         			   		
* Name & Student No.: Yanhong Ben, 4845675															
* Lab No: 1																		
* File Description: pet lost and found  										
* Date Last Modified: 06/08/2015                                				
*********************************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#include "pet.h"

int main()
{
	ifstream fin;
	char filename[50];
	cout << "Please enter a filename that you wanna to open." << endl;
	cin.getline(filename, 50);
	fin.open(filename, ios::in);
	if (!fin.good())
	{
		cout << "Could not open the file." << endl; 
		return 0;
	}
	fin.close();

	int count = countRecords(filename);
	cout << "Total record is " << count << "." << endl;

	Pet* sample = new Pet[count];
	loadRecords(filename, sample, count);
	printRecords(sample, count);
	delete [] sample;
}


int countRecords (char *filename)
{
	int count = 0;
	char record[500];
	ifstream fin;
	fin.open(filename);
	while (fin.good())
	{
		fin.getline(record, 500);
		if (strlen(record) != 0)
			count++;
	}
	fin.close();
	return count++;
}


void loadRecords(char *filename, Pet *sample, int count)
{
	ifstream fin;
	fin.open(filename);
	for (int i = 0; i < count; i++)
	{
		fin >> ws;
		fin.getline(sample[i].status, 10, ',');
		fin.getline(sample[i].type, 10, ',');
		fin.getline(sample[i].gender, 10, ',');
		fin.getline(sample[i].breed, 50, ',');
		fin >> sample[i].ageYear;
		fin >> sample[i].ageMonth;
		fin.ignore();
		fin.getline(sample[i].color, 20, ',');
		fin.getline(sample[i].chip, 20, ',');
		fin.getline(sample[i].location, 20, ',');
		fin >> sample[i].phone;
	}
	fin.close();
}


void printRecords(Pet *sample, int count)
{
	cout << "File contains below records: \n";
	for (int i = 0; i < count; i++)
	{
		cout << i+1 << endl;
		cout << "Status: " << sample[i].status << endl;
		cout << "Type: " << sample[i].type << endl;
		cout << "Gender: " << sample[i].gender << endl;
		cout << "Breed: " << sample[i].breed << endl;
		cout << "Year: " << sample[i].ageYear << endl;
		cout << "Month: " << sample[i].ageMonth << endl;
		cout << "Color: " << sample[i].color << endl;
		cout << "Chip: " << sample[i].chip << endl;
		cout << "Location: " << sample[i].location << endl;
		cout << "Phone#: " << sample[i].phone << endl;
		cout << endl;
	}
}


