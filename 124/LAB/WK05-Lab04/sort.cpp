/********************************************************************************
* Filename: sort.cpp                                         			   		*
* Name: Yanhong Ben																*
* Time: Mon 8:30-10:30 17.106													*                                          	  			    *
* Lab No: 4																		*
* File Description: implement a function to sorting data for a driver program	*	                                                            *
* Date Last Modified: 31/03/2015                                				*
*********************************************************************************/
#include <cmath>
#include <iostream>
using namespace std;

void sort (int array[], int n, int& ncomp)
{
	int distance = 0, temp, m = 0, swap;
	ncomp = 0; 

	while ((pow(2, m) - 1) < n && (pow(2, m+1) - 1) < n)
	{
		m++;
	}
	distance = pow(2, m) - 1; 

	while (distance > 0)
	{
		do
		{
			swap = 0;
			for (int j = 0; j < n - 1 - distance; j++)
			{
				ncomp++;
				if (array[j] > array[j+distance])
				{
					temp = array[j];
					array[j] = array[j+distance];
					array[j+distance] = temp;
					swap++;
				}
			}
		}while (swap != 0);

		distance = distance / 2;
	}

}


