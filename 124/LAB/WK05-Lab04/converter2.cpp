/****************************************
*  Program to prepare data for graphing *
****************************************/

#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 1024;

int main(int argc, char** argv)
{
	char title[MAX];
	char xaxis[MAX];
	char yaxis[MAX];
	ifstream ifs;
	ofstream ofs;
	int counter = 0;
	float value = 0;
	char tag[128];

	if (argc != 3)
	{
		cerr << "Invalid Usage. " << endl;
		return 0;
	}

	ifs.open(argv[1]);
	ofs.open(argv[2]);
	if (!ifs.good() || !ofs.good())
	{
		cerr << "Files to be converted could not be opened" << endl;
		return 0;
	}
			
	ifs.getline(title, MAX - 1, '\n');
	ifs.getline(xaxis, MAX - 1, '\n');
	ifs.getline(yaxis, MAX - 1, '\n');

	cout << "set xtic rotate 90" << endl;
	cout << "set xtics(";

	ifs >> tag;
	while (!ifs.eof())
	{
		if (tag[0] == '_') tag[0] = ' ';
		ifs >> value;
		if (counter > 0)
			cout << ", ";
		cout << "\"" << tag << "\" " << counter + 1;
		ofs << counter + 1 << " " << value << endl;
		counter++;
		ifs >> tag;
	}

	cout << ")" << endl;
	cout << "set title \"" << title << "\"" << endl;
	cout << "set xlabel \"" << xaxis << "\"; set ylabel \"" <<yaxis << "\";" << endl;		
	cout << "plot \"" << argv[2] << "\" with lines" << endl;
	cout << "set term postscript eps enhanced" << endl;
	cout << "set out \"output.ps\"" << endl;
	cout << "replot" << endl;

	ofs.close();
	ifs.close();

	return 0;
}
