/*
	Contains implementation of routines to identify patterns - 4 wide
*/

#include <iostream>
#include <fstream>
using namespace std;

// variables are defined elsewhere.

extern int numChar;			
extern const int MAX;
extern char DNAstrand[];					

// routine to identify patterns.

void freq_comp()
{
	const int MAXSET = 256;
	char set[MAXSET][5];
	int count = 0;
	
	for (int i = 0; i + 4 < numChar; i++)
	{
		char token[5];
		token[0] = DNAstrand[i];
		token[1] = DNAstrand[i+1];
		token[2] = DNAstrand[i+2];			
		token[3] = DNAstrand[i+3];
		token[4] = '\0';
		
		cout << token << endl;
		
	}
}
