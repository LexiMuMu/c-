/*
    Selection sort with extra code demonstrating swaps.
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int comp = 0;

int main()
{
	const int n = 10;
	int dataset[n];

	srand(time(NULL));
	for (int k = 0; k< n; k++)
	{	
		dataset[k] = rand() % 100;
	}

	int j = 0;
	int smallest = 0; 	
	
	for (int i = 0; i < n; i++)	
	{
        	for (int q = 0; q < n; q++)
        	{
 	           	cout << dataset[q] << " ";
        	}
        	cout << endl;
        
        	smallest = i;	
        	for (j=i+1; j<=n; j++)	
		{		
            		if (dataset[smallest] > dataset[j])				
 	        	   	smallest = j;
		}

	        if (smallest != i)		
        	{	
            		int temp = dataset[i];		
	            	dataset[i] = dataset[smallest];	
            		dataset[smallest] = temp;		
        	}	
    	}

	return 0;
}

