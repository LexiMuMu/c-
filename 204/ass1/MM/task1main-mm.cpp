/*******************************************************
*      Filename: task1main.cpp                         *
*      Login: lm890                                    *
*      lab No: assignment 1                            *
*      File Description: use the student class         *
*      Date Last Modified: August 27th,2015            *
********************************************************/

#include <iostream>
#include <fstream>
#include <ctype.h>
#include <math.h>
#include <cstring>
#include <iomanip>
#include "student.h"

using namespace std;

int main()
{
	char filename[20];
	int count = 0;
	char tmp[500];
	int tmpMark[4];
	Student * records;
	//get file name
	cout << "Input student information file name: ";
	cin.getline(filename, 20, '\n');

	ifstream in;
	in.open(filename);
	if(!in.good())
	{
		cout << "file missing!\n";
		return false;
	}

	//count the number of students
	do
	{
		in.getline(tmp, 500, '\n');
		if(strcmp(tmp, "") != 0)
			count++;
	}while(!in.eof());
	in.close();

	//allocate memory
	records = new Student[count];

	//load the informations into the dynamic memory
	int recNum = 0;
	char name[50];
	in.open(filename);
	do
	{	
		//read the name
		in.getline(tmp, 50, ' ');
		strcpy(name, tmp);
		//while the name is not ended
		while(!isdigit(in.peek()) && in.peek() != '-')
		{
			in.clear();
			in.getline(tmp, 50, ' ');
			strcat(name, " ");
			strcat(name, tmp);
		}	
		//read the marks
		for(int i = 0; i < 4; i++)
			in >> tmpMark[i];
		in.ignore();
		//input the informations
		records[recNum].setName(name);
		records[recNum].setMark(tmpMark);
		recNum++;
	}while(recNum < count);

	//print the records
	cout << "Name";
	cout << setw(20) << "mark_1";
	cout << setw(7) << "mark_2";
	cout << setw(7) << "mark_3";
	cout << setw(7) << "mark_4";
	cout << setw(7) << "Total";
	cout << setw(10) << "Average\n";
	cout << setw(61) << setfill('*') << '*' << endl;
	cout << setfill(' ');
	for(int i = 0; i < count; i++)
		records[i].print();
	cout << setw(61) << setfill('*') << '*' << endl;
	cout << setfill(' ');
		
	float score[4] = {0};
	int scount[4] = {0};
	float mean[4] = {0};
	float deviation[4] = {0};

	//count the number of students in each subject
	for(int i = 0; i < count; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			int tmp = records[i].getMark(j);
			if(tmp != -1)
			{
				score[j] += tmp;
				scount[j] ++;
			}
		}
	}
	
	//calculate average
	for(int j = 0; j < 4; j++)
		mean[j] = score[j] / scount[j];
	// calculate standard deviation
	for(int j = 0; j < 4; j++)
	{
		double add = 0;
		for(int i = 0; i < count; i++)
		{
			int tmp = records[i].getMark(j);
			if(tmp != -1)
			{
				add += (tmp - mean[j]) * (tmp - mean[j]);
			}
		}
		deviation[j] = sqrt(add / scount[j]);
	}

	cout << setw(20) << left << "Number of students";
	for(int j = 0; j < 4; j++)
		cout << setw(7) << scount[j];
	cout << endl;
	cout << setw(20) << left << "Mean";
	for(int j = 0; j < 4; j++)
		cout << setw(7) << mean[j];
	cout << endl;
	cout << setw(20) << left << "Standard Deviation";
	for(int j = 0; j < 4; j++)
		cout << setw(7) << deviation[j];
	cout << endl;

	delete [] records; 
	in.close();
}
