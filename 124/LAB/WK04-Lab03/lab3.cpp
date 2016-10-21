/********************************************************************************
* Filename: lab3.cpp                                         			   		*
* Name: Yanhong Ben																*
* Time: Mon 8:30-10:30 17.106													*                                          	  			    *
* Lab No: 3																		*
* File Description: sorting data   												*	                                                            *
* Date Last Modified: 23/03/2015                                				*
*********************************************************************************/


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int SIZE = 100;

struct Stock
{
	char stockTag[5];
	int stockCost;
	long int stockVolume;
};


void displayMenu(char &input);
void openFile(ifstream &fin);
void readData(ifstream &fin, Stock stocksort[SIZE], int &count);
void selecionSort(int &count, Stock stocksort[SIZE]);
void insertionSort(Stock stocksort[SIZE], int &count);
void saveFile(ofstream &fout, int &count, Stock stocksort[SIZE], char &input);


int main()
{
	Stock stocksort[SIZE];

	int count = 0;

	ifstream fin;
	ofstream fout;

	openFile(fin);
	readData(fin, stocksort, count);

	char input;	


	bool flag = true;

	while (flag == 1)
	{
		displayMenu(input);
		switch (input)
		{
			case ('C'):
					selecionSort(count, stocksort);
					saveFile(fout,count,stocksort,input);
					flag = 0;
					cout << "File saved." << endl;
					break;
			case ('V'):
					insertionSort(stocksort, count);
					saveFile(fout,count,stocksort,input);
					flag = 0;
					cout << "File saved." << endl;
				break;
			case ('Q'):
					flag = 0;
					cout << "Thank you and goodbye." << endl;
				break;
			default:
					flag = 1;
		}
	}


	fout.close();
	fin.close();
	return 0;
}

void openFile(ifstream &fin)
{
	fin.open("stockdata.txt");
	if (!fin.good())
	{
		cout << "Could not open the file." << endl; 
	}
}

void readData(ifstream &fin, Stock stocksort[SIZE], int &count)
{
	fin >> stocksort[count].stockTag;
	while (!fin.eof())
	{
		fin >> stocksort[count].stockCost;
		fin >> stocksort[count].stockVolume;
		count++;
		fin >> stocksort[count].stockTag;
	}
}

void displayMenu(char &input)
{
	cout << "Main Meun:" << endl;
	cout << "c: sort data by Cost" << endl;
	cout << "v: sort data by trade Volume" << endl;
	cout << "q: Quit" << endl;
	cout << "Enter Choice:" << endl;
	cin >> input;
	input = toupper(input);
}

void selecionSort(int &count, Stock stocksort[SIZE])
{
	int biggest, costemp = 0;
	char nametemp[5];
	long int volumetemp = 0;
	for (int i = 0; i < count-2; i++)
	{
		biggest = i; 
		for (int j = i+1; j < count-1; j++)
		{
			if (stocksort[biggest].stockCost < stocksort[j].stockCost)
				biggest = j;
		}
		if(biggest != i)
		{
			costemp = stocksort[i].stockCost;
			strcpy(nametemp, stocksort[i].stockTag);
			volumetemp = stocksort[i].stockVolume;

			stocksort[i].stockCost = stocksort[biggest].stockCost;
			strcpy(stocksort[i].stockTag, stocksort[biggest].stockTag);
			stocksort[i].stockVolume = stocksort[biggest].stockVolume;

			stocksort[biggest].stockCost = costemp;
			strcpy(stocksort[biggest].stockTag, nametemp);
			stocksort[biggest].stockVolume = volumetemp;
		}
	}
}


void insertionSort(Stock stocksort[SIZE], int &count)
{
	int p = 0, item = 0;
	int costemp = 0;
	char nametemp[5];
	for (int i = 1; i < count-1; i++)
	{
		item = stocksort[i].stockVolume;
		strcpy(nametemp, stocksort[i].stockTag);
		costemp = stocksort[i].stockCost;

		p = i - 1;
		while (p >= 0 && item > stocksort[p].stockVolume)
		{
			stocksort[p+1].stockVolume = stocksort[p].stockVolume;
			strcpy(stocksort[p+1].stockTag, stocksort[p].stockTag);
			stocksort[p+1].stockCost = stocksort[p].stockCost;

			p--;
		}
		stocksort[p+1].stockVolume = item;
		strcpy(stocksort[p+1].stockTag, nametemp);
		stocksort[p+1].stockCost = costemp;
	}

}


void saveFile(ofstream &fout, int &count, Stock stocksort[SIZE], char &input)
{
	fout.open("data.txt");
	if (fout.good())
	{
		switch (input)
		{
			case ('C'):
				fout << "Corporate Stock Cost - NASDAQ" << endl;
				fout << "Stock Tag" << endl;
				fout << "Cost" << endl;
				for (int k = 0; k < count - 1; k++)
				{
					fout << stocksort[k].stockTag << "	"
					<< stocksort[k].stockCost << "	" << endl;
				}
			break;
			case ('V'):
				fout << "Corporate Stock Trade Volume - NASDAQ" << endl;
				fout << "Stock Tag" << endl;
				fout << "Volume" << endl;
				for (int k = 0; k < count - 1; k++)
				{
					fout << stocksort[k].stockTag << "	"
					<< stocksort[k].stockVolume << "	" << endl;
				}
			break;
		}
	}
	else
	{
		cerr << " File can not be opened for writing - exiting. " << endl;
	}
}



