/************************************************************
*      Filename: sort.h                                     *
*      Login: lm890                                         *
*      lab No: assignment 2                                 *
*      File Description: Do pivot quick sort an array with  *
*      ten integers.                                        *
*      Date Last Modified: 24/4/2015                        *
************************************************************/

#include <iostream>
#include "movement.h"
#include "sort.h"
using namespace std;

int main()
{
	const int size = 10;
	T array[size] = {6, 5, 1, 8, 4, 7, 2, 9, 6, 3};

	int ncomp, nswap;
	//quick sort function call
	dpqsort(array, size, ncomp, nswap);
	cout << "Sorted " << size << " records in " 
		<< ncomp << " comparisons and "
		<< nswap << " swaps." << endl;
	//print sorted arry
	for(int i=0; i<size; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;

	//call quick sort function on a sorted array
	dpqsort(array, size, ncomp, nswap);
	cout << "Sorted " << size << " already sorted records in " 
		<< ncomp << " comparisons and "
		<< nswap << " swaps." << endl;

	for(int i=0; i<size; i++)
	{
		array[i] = 1;
	}
	//call quick sort function on an array with same numbers
	dpqsort(array, size, ncomp, nswap);
	cout << "Sorted " << size << " duplicate records in " 
		<< ncomp << " comparisons and "
		<< nswap << " swaps." << endl;
}
