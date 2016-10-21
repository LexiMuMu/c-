/*
    Selection sort with extra code demonstrating swaps.
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

int comp = 0;

int main()
{
	const int n = 100;

	int dataset[n], k = 0 ;

	cout << "Please input unsorted numbers." << endl;
	

	while (!cin.eof())
	{
		cin >> dataset[k];
		k++;
	}


	int j = 0;
	int smallest = 0; 	
	
	for (int i = 0; i < k-1; i++)	
	{
        	for (int q = 0; q < k-1; q++)
        	{
 	           	cout << dataset[q] << " ";
        	}
        	cout << endl;
        
        	smallest = i;	
        	for (j=i+1; j<k-1; j++)	
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

