/************************************************
* Filename: main.cpp                            *
* Name: Yanhong Ben								*
* Time: Mon 8:30-10:30 17.106					*
* Lab No: 9										*
* File Description: play cards main file		*
* Date Last Modified: 14/05/2015                *
*************************************************/


#include <iostream>
using namespace std;

#include "deck.h"

int main()
{
	int dealNum;
	cout << "How many cards do you want to deal each time? " << endl;
	cin >> dealNum;
	deck single;

	single.shuffle();

	for (int i = 0; i < dealNum; i++)
	{
		single.deal();
	}
	single.print();
}