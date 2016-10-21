/************************************************
* Filename: deck.cpp                            *
* Name: Yanhong Ben								*
* Time: Mon 8:30-10:30 17.106					*
* Lab No: 9										*
* File Description: play cards source file		*
* Date Last Modified: 14/05/2015                *
*************************************************/


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "deck.h"


deck::deck()
{
	for (int i = 0; i < 52; i++)
	{
		play[i].set(i);
		size = 52;
	}
}

void deck::shuffle()
{
	srand(time(0));
	card temp;
	for (int i = 0; i < size; i++)
	{
		int j = rand() % (size - i) + i;
		temp = play[i];
		play[i] = play[j];
		play[j] = temp;
	}
}

void deck::deal()
{
	play[size-1].print(cout);
	size--;
	if(size == 0)
	{
		cout << "There is no card left." << endl;
		return;
	}
}

void deck::print()
{
	cout << "There are " << size << " cards left." << endl; 
}

