#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

struct CallCentre
{
	char cname[20];
	double waitingTime[128];
	int size;
	double mean;
	double standardDev;
};

int main()
{
	CallCentre result;
	ifstream fin;
	char filename[10];
	cout << "Please enter a filename that you want to open." << endl;
	cin.getline (filename, 50);
	fin.open (filename, ios::in);
	if (!fin.good())
	{
		cout << "Could not open the file." << endl; 
	}

//get company name
	fin.getline(result.cname, 20, '\t');


//get sum and average of waiting time
	int i;
	double sum;
	for (i = 0; fin.good(); i++)
	{
		fin >> result.waitingTime[i];
		sum += result.waitingTime[i];	
	}
	result.size = i;
	result.mean = sum/result.size;



//compute standard deviation
	double var;
	double varpow;
	double varsum;
	double vardev;
	for (int j = 0; j < result.size; j++)
	{
		var = result.waitingTime[j] - result.mean;
		varpow = pow (var, 2);
		varsum += varpow;
	}
	vardev = varsum / result.size;
	result.standardDev = sqrt(vardev);

//print
	cout << result.cname << " " << result.mean << " "; 
	cout << result.size << " " << result.standardDev << endl;


	return 0;
}





