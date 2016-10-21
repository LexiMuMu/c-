/************************************************
* Filename: card.cpp                            *
* Name: Yanhong Ben								*
* Time: Mon 8:30-10:30 17.106					*
* Lab No: 9										*
* File Description: play cards source file		*
* Date Last Modified: 14/05/2015                *
*************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

#include "card.h"

card::card() //default constructor
{
	value = -1;
}

card::card(int proVal) //initialising constructor and checking illegal
{
	if (proVal < 0 || proVal > 51)
	{
		cout << "Invalid input." << endl;
		exit(EXIT_FAILURE);
	}
	else
		value = proVal;
}

void card::set(int spcVal)  //check set function and get value from input
{
	if (spcVal >= 0 && spcVal <= 51)
	{
		if (value == -1)
			value = spcVal;
		else
			cout << "Card already had a valid value." << endl;
	}
	else
		cout << "Invalid input."  << endl;
}

void card::print(ostream& out) const //implement print function
{
	if (value <= 12 && value >= 0)
	{
		if (value <= 8 && value > 0)
			out << value << "S" << endl;
		else if (value == 9)
			out << "X" << "S" << endl;
		else if (value == 10)
			out << "J" << "S" << endl;
		else if (value == 11)
			out << "Q" << "S" << endl;
		else if (value == 12)
			out << "K" << "S" << endl;
		else
			out << "A" << "S" << endl;
	}
	else if (value <= 25 && value >= 13)
	{
		if (value <= 21 && value > 13)
			out << value - 12 << "C" << endl;
		else if (value == 22)
			out << "X" << "C" << endl;
		else if (value == 23)
			out << "J" << "C" << endl;
		else if (value == 24)
			out << "Q" << "C" << endl;
		else if (value == 25)
			out << "K" << "C" << endl;
		else
			out << "A" << "C" << endl;
	}
	else if (value <= 38 && value >= 26)
	{
		if (value <= 34 && value > 26)
			out << value - 25 << "D" << endl;
		else if (value == 35)
			out << "X" << "D" << endl;
		else if (value == 36)
			out << "J" << "D" << endl;
		else if (value == 37)
			out << "Q" << "D" << endl;
		else if (value == 38)
			out << "K" << "D" << endl;
		else
			out << "A" << "D" << endl;
	}
	else if (value <= 51 && value >= 39)
	{
		if (value <= 47 && value > 39)
			out << value - 38 << "H" << endl;
		else if (value == 48)
			out << "X" << "H" << endl;
		else if (value == 49)
			out << "J" << "H" << endl;
		else if (value == 50)
			out << "Q" << "H" << endl;
		else if (value == 51)
			out << "K" << "H" << endl;
		else
			out << "A" << "H" << endl;
	}
	else 
		out << "uninitialised" << endl;
}



