/************************************************************
* Filename: rotate.cpp										*
* Name: Yanhong Ben											*
* Time: Mon 8:30-10:30 17.106							 	*                                          	  			    *
* Lab No: 5													*
* File Description: pointer									*	                                                            *
* Date Last Modified: 16/04/2015							*
*************************************************************/


#include <iostream>
#include <cstring>
using namespace std;

void rotate (int *oneptr, int *twoptr, int *threeptr);

int main()
{
	int one = 1, two = 2, three = 3;
	char charA = 'a', charB = 'b', charC = 'c';
	int *oneptr = &one, *twoptr = &two, *threeptr = &three;

	cout << endl;
	cout << "The address of int '1' is " << &one << "." << endl;
	cout << "The address of int '2' is " << &two << "." << endl;
	cout << "The address of int '3' is " << &three << "." << endl;
	cout << "The address of int 'a' is " << reinterpret_cast<void*>(&charA) << "." << endl;
	cout << "The address of int 'b' is " << reinterpret_cast<void*>(&charB) << "." << endl;
	cout << "The address of int 'c' is " << reinterpret_cast<void*>(&charC) << "." << endl;
	cout << endl;

	int array[3] = {4,5,6};
	int *arrptrA = &array[0], *arrptrB = &array[1], *arrptrC = &array[2];

	cout << "The variable of the array is " << array[0] << " " << array[1] << " " << array[2] << "." << endl;
	cout << "The address of the array is " << &array[0] << " " << &array[1] << " " << &array[2] << "." << endl; 
	cout << endl;

	cout << "Before rotate the int order is: " << *oneptr << " " << *twoptr << " " << *threeptr << endl;
	rotate(oneptr, twoptr, threeptr);
	cout << "After rotate the int order is: " << *oneptr << " " << *twoptr << " " << *threeptr << endl;
	cout << endl;
	cout << "Before rotate the array order is: " << *arrptrA << " " << *arrptrB << " " << *arrptrC << endl;
	rotate(arrptrA, arrptrB, arrptrC);
	cout << "After rotate the array order is: " << *arrptrA << " " << *arrptrB << " " << *arrptrC << endl;


}


void rotate (int *oneptr, int *twoptr, int *threeptr)
{
	int temp1 = 0, temp2 = 0, temp3 = 0, temp = 0;
	temp1 = *oneptr;
	temp2 = *twoptr;
	temp3 = *threeptr;


	temp = temp1;
	temp1 = temp2;
	temp2 = temp3;
	temp3 = temp;

	*oneptr = temp1;
	*twoptr = temp2;
	*threeptr = temp3;

}



