/************************************************************
*      Filename: sort.cpp                                   *
*      Login: lm890                                         *
*      lab No: week5 lab4                                   *
*      File Description: sort array by divide them          *
*      Date Last Modified: 31/3/2015                        *
************************************************************/
#include <cmath>

void sort(int x[], int n, int & ncomp)
{
	int d = 0, tmp = 0, a = 1, swap = 0, swaptmp = 0;
	
	while(d < n)
	{
		a++;
		d = pow(2, a) - 1;
	}
	d = pow(2, a - 1) - 1;

	for(d = pow(2, a) - 1; d > 0; d = d / 2)
	{
		do
		{
			swaptmp = swap;
			for(int j = 0; j <= n - 1 - d ; j++)
			{
				ncomp++;
				if(x[j] > x[j+d])
				{
					tmp = x[j];
					x[j] = x[j + d];
					x[j + d] = tmp;	
					swap++;
				}
			}
		}while(swaptmp != swap);
	}
}

