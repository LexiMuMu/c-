

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;



struct CallCentre
{
	char cmpyName[20];
	double waitingTime[200];
	int size;
	double mean;
	double standardDev;
};


bool openFile(ifstream &fin);
void readData(CallCentre result[200], ifstream &fin, int &count);
void calMean(CallCentre result[200], int i);
void calStandardDev(CallCentre result[200], int i);
int calMinSDev(CallCentre result[200], int &count);
int calMaxSDev(CallCentre result[200], int &count);


int main()
{
	CallCentre result[200];
	ifstream fin;
	int count = 0, min, max;

	// openFile(fin);

	if (openFile(fin))
	{
		readData(result, fin, count);
		for (int i = 0; i < count; i++)
		{
			calMean(result, i);
			calStandardDev(result, i);
		}
		min = calMinSDev(result, count);
		max = calMaxSDev(result, count);

		cout << setfill(' ') << setw(24) << "Company Name" << setw(24);
		cout << "Mean" << setw(24) << "Standard Deviation" << endl;

		for (int i = 0; i < count; i++)
		{
			cout << setw(24) << result[i].cmpyName;
			cout << setw(24) << result[i].mean;
			cout << setw(24) << result[i].standardDev << endl;
		}
		cout << "The best performing belongs to " << result[min].cmpyName << ". ";
		cout << "It's standard deviation is " << result[min].standardDev << ". " << endl;

		cout << "The worst performing belongs to " << result[max].cmpyName << ". ";
		cout << "It's standard deviation is " << result[max].standardDev << ". " << endl;
	}
	else 
		cout << "Could not open the file." << endl; 

	fin.close();
	return 0;
}



bool openFile(ifstream &fin)
{
	char filename[50];
	cout << "Please enter a filename that you want to open." << endl;
	cin.getline (filename, 50);
	fin.open (filename, ios::in);
	return 1;
}



void readData(CallCentre result[200], ifstream &fin, int &count)
{
	fin.getline(result[0].cmpyName, 20, '\t');
	int i = 0, j;
	while (strcmp (result[i].cmpyName, "\0") != 0)
	{
		for (j = 0; fin.good(); j++)
		{
			fin >> result[i].waitingTime[j];
			if (result[i].waitingTime[j] > 128)
			{
				cout << "One of your data is bigger than 128." << endl;
			}
		}
		result[i].size = j - 1;
		fin.clear();
		i++;
		fin.getline(result[i].cmpyName, 20, '\t');
	}
	count = i;
}

void calMean(CallCentre result[200], int i)
{
	double sum = 0;
	for (int j =0; j < result[i].size; j++)
	{
		sum += result[i].waitingTime[j];
	}
	result[i].mean = sum / result[i].size;
}


void calStandardDev(CallCentre result[200], int i)
{
	double var;
	double varpow;
	double varsum = 0;
	double vardev;

	for (int j = 0; j < result[i].size; j++)
		{
			var = result[i].waitingTime[j] - result[i].mean;
			varpow = pow (var, 2);
			varsum += varpow;
		}
	vardev = varsum / result[i].size;
	result[i].standardDev = sqrt(vardev);
		
}


int calMinSDev(CallCentre result[200], int &count)
{
	int i, min = 0;
	for (i = 0; i < count; i++)
	{
		if (result[min].standardDev > result[i].standardDev)
			min = i;
	}
	return min;
}

int calMaxSDev(CallCentre result[200], int &count)
{
	int i, max = 0;
	for (i = 0; i < count; i++)
	{
		if (result[max].standardDev < result[i].standardDev)
			max = i;
	}
	return max;
}
