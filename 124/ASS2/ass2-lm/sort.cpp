/************************************************************
*      Filename: sort.cpp                                   *
*      Login: lm890                                         *
*      lab No: assignment 2                                 *
*      File Description: Qßivot quick sort function         *
*      Date Last Modified: 24/4/2015                        *
************************************************************/


#include "sort.h"
#include <iostream>
using namespace std;

void swapPivot(T array[], const int size, int &ncomp, int &nswap);
void dualPivotQuicksort(T array[], int left, int right, int &ncomp, int& nswap);
void swap(T &a, T &b, int &nswap);

//initialize compare and swap count 
//call function quick sort
void dpqsort(T array[], const int size, int &ncomp, int &nswap)
{
	ncomp = 0, nswap = 0;
	swapPivot(array, size, ncomp, nswap);
	dualPivotQuicksort(array, 0, size-1, ncomp, nswap);
}

//function for swap the second smallest to first and
//second largest to last
void swapPivot(T array[], const int size, int &ncomp, int &nswap)
{
	int quarter = size / 4, i = 0;
	T tmp[5];
	for(int j = 0; j < size - quarter; j += quarter)
	{
		tmp[i++] = array[j];
	}
	tmp[4] = array[size-1];
	dualPivotQuicksort(tmp, 0, 4, ncomp, nswap);
	nswap = 0;
	i = 0;
	for(int j = 0; j < size - quarter; j += quarter)
	{
		if(array[j] == tmp[1])
			swap(array[0], array[j], nswap);
		if(array[j] == tmp[3])
			swap(array[size-1], array[j], nswap);
	}
}

//function of quick sort and count the time of swap and compare
void dualPivotQuicksort(T array[], int left, int right, int &ncomp, int& nswap)
{
	//base case: 
	//dataset only need to be sort when there more than one variable
	if(right - left < 1)
		return;

	//swap left with right if left is bigger than right
	ncomp++;
	if(array[left] > array[right])
	{
		swap(array[left], array[right], nswap);
	}
	int l = left + 1, g = right - 1; 
	//k from l to g
	for(int k = l; k <= g; k++)
	{
		ncomp++;
		if(array[k] < array[left])
		{
			swap(array[k], array[l], nswap);
			l++;
		}
		else if(array[k] > array[right])
		{
			
			while(array[g] > array[right] && k < g)
			{
				ncomp++;
				g--;
			}
			swap(array[k], array[g], nswap);
			g--;
			ncomp++;
			if(array[k] < array[left])
			{
				swap(array[k], array[l], nswap);
				l++;
			}
		}
	}

	l--;
	g++;
	swap(array[left], array[l], nswap);
	swap(array[right], array[g], nswap);

	//divide the dataset to three part and sort
	dualPivotQuicksort(array, left, l - 1, ncomp, nswap);
	dualPivotQuicksort(array, l + 1, g - 1, ncomp, nswap);
	dualPivotQuicksort(array, g + 1, right, ncomp, nswap);
}

//swap a and b
void swap(T &a, T &b, int &nswap)
{
	//if a is equal to b, don't need to swap
	if(a == b)
		return;
	//swap
	T temp = a;
	a = b;
	b = temp;
	//count swap
	nswap++;
	
}
