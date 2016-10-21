/****************************************************
 Filename: main.cpp
 Name: Yanhong Ben, 4845675
 Time: Mon 8:30-10:30 17.106
 Lab No: 12
 File Description: creates a binary search tree 
 Date Last Modified: 02/06/2015
*****************************************************/

#include <iostream>
#include <ctime>
using namespace std;

#include "binarytree.h"

int sum = 0;

void TwoTimes(const T&);
void sumNum(const T&);

int main()
{
	srand(time(0));

	BinaryTree bst;

	for (int i = 0; i<20; i++)
	{
		int sumTemp = rand() % 100;
		bst.insert(sumTemp);
		sumNum(sumTemp);
	}

	cout << "Traverse the tree in-order: " << endl;
	bst.printAll();
	cout << endl;

	cout << "Traverse the tree in-order and print twice: " << endl;
	bst.applyToAll(TwoTimes);
	cout << endl;
	cout << "Sum of all numbers in the tree is: " << sum << "." << endl;

	cout << "Traverse the tree pre-order: " << endl;
	bst.preorderPrintAll();
	cout << endl;

	return 0;
}

void TwoTimes(const T& a)
{
	cout << a << " " << a << " ";
}

void sumNum(const T& a)
{
	sum = sum + a;
}

