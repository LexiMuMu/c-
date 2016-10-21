#include <iostream>
#include <fstream>
using namespace std;

#include "dna.h"

int numChar = 0;		// store count of bytes
const int MAX = 3000;		// maximum width of array
char DNAstrand[MAX];		// store strand

void reverse_complement(ifstream& fin)
{
	int i, j = 0, temp = 0;
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
	numChar = i-2;

	i = 0, j = numChar;
	while (j > i)
	{
		temp = DNAstrand[i];
		DNAstrand[i++] = DNAstrand[j];
		DNAstrand[j--] = temp;
	}

	for (int k=0; k<=numChar; k++)
	{
		cout << DNAstrand[k];
	}
	numChar = numChar + 1;
	cout << endl;
}


void save(ofstream& fout)
{
	for(int k=0;k<numChar;k++)
		fout.put(DNAstrand[k]);
}
