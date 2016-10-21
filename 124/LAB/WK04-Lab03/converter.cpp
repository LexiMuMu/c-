/**********************************************
*  Program to prepare stock data for graphing *
**********************************************/

#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 1024;

int main(int argc, char** argv)
{
	char title[MAX];
	char xaxis[MAX];
	char yaxis[MAX];
	ifstream fin;
	ofstream fout;
	int counter = 0;
	float value = 0;
	char tag[128];

	if (argc != 3)
	{
		cerr << "Invalid Usage. " << endl;
		return 0;
	}

	fin.open(argv[1]);
	fout.open(argv[2]);
	if (!fin.good() || !fout.good())
	{
		cerr << "Files to be converted could not be opened" << endl;
		return 0;
	}
			
	fin.getline(title, MAX - 1, '\n');
	fin.getline(xaxis, MAX - 1, '\n');
	fin.getline(yaxis, MAX - 1, '\n');

	cout << "set xtic rotate 90" << endl;
	cout << "set xtics(";

	fin >> tag;
	while (!fin.eof())
	{
		fin >> value;
		if (counter > 0)
			cout << ", ";
		cout << "\"" << tag << "\" " << counter + 1;
		fout << counter + 1 << " " << value << endl;
		counter++;
		fin >> tag;
	}

	cout << ")" << endl;
	cout << "set title \"" << title << "\"" << endl;
	cout << "set xlabel \"" << xaxis << "\"; set ylabel \"" <<yaxis << "\";" << endl;		
	cout << "plot \"" << argv[2] << "\" with boxes" << endl;
	cout << "set term postscript" << endl;
	cout << "set out \"output.ps\"" << endl;
	cout << "replot" << endl;

	fin.close();
	fin.close();

	return 0;
}
