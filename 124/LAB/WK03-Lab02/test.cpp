#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 3000;
char DNAstrand[MAX];

int main ()
{
	ifstream fin;

	
	fin.open("test.txt");
	int count;
	int i, j = 0, temp = 0, k;
	for (i = 0; fin.good(); i++)
	{
			fin >> DNAstrand[i];
			switch (DNAstrand[i])
			{
				case ('A'):
					DNAstrand[i] = 'T';
					break;
				case ('T'):
					DNAstrand[i] = 'A';
					break;
				case ('G'):
					DNAstrand[i] = 'C';
					break;
				case ('C'):
					DNAstrand[i] = 'G';
					break;
			}
	}
	count = i-2;

	i = 0, j = count;
	while (j > i)
	{
		temp = DNAstrand[i];
		DNAstrand[i++] = DNAstrand[j];
		DNAstrand[j--] = temp;
	}

	for (int k=0; k<=count; k++)
	{
		cout << DNAstrand[k];
	}

	cout << endl;

	fin.close();

	return 0;
}

