/************************************************************
 Filename: hanoi.cpp                           
 Name: Yanhong Ben, 4845675						
 Time: Mon 8:30-10:30 17.106					
 Lab No: 11 										
 File Description: implementation of the class of hanoi game		
 Date Last Modified: 25/05/2015                
*************************************************************/

#include <iostream>
using namespace std;

#include "hanoi.h"


bool Hanoi::run()
{
	while (!isSolved())
	{
		if (!move())
			return false;
	}
	if (isSolved())
		cout << "Congratulations, you won!" << endl;
	return true;
}

void Hanoi::rules()
{
	cout << "Welcome to the Towers of Hanoi" << endl;
	cout << "The aim is to move all discs from tower A to tower C" << endl;
	cout << "You can type 'q' at any time to quit" << endl;
}


bool Hanoi::setup()
{
	for (int i=0; i<SIZE; i++)
	{
		while(!stage[i].isEmpty())
			stage[i].pop();
	}

	int discNum;
	char order;
	for (int i=0; i<SIZE; i++)
	{
		if (stage[i].isEmpty() == true)
		{	
			cout << "How many discs?" << endl;
			while (!(cin>> discNum))
			{	
				cin.clear();
				cin >> order;
				if (order =='q')
					return false;
			}

			if (discNum <= 20 && discNum > 0)
			{
				for (int i=discNum; i>0; i--)
					stage[0].push(i);
					return true;
			}
			else
				cout << "Discs cannot bigger than 20 and less than 0, pls re-enter." << endl;
		}
	}
	return false;
}

bool Hanoi::isSolved()
{
	if (stage[0].isEmpty() == 1 && stage[1].isEmpty() == 1)
		return true;
	return false;
}

void Hanoi::print()
{
	cout << "A ";
	stage[0].print(cout);
	cout << "B ";
	stage[1].print(cout);
	cout << "C ";
	stage[2].print(cout);
}

bool Hanoi::moveDisc(T org, T des)
{
	if (!stage[org].isEmpty())
	{
		if (!stage[des].isEmpty())
		{
			if (stage[org].peek() > stage[des].peek())
				return false;
		}
		T moveDisc;
		moveDisc = stage[org].pop();
		stage[des].push(moveDisc);
		return true;
	}
	return false;
}

bool Hanoi::move()
{
	char from, to;
	bool flag = false;
	while (flag == false)
	{
		cout << "Move from ";
		cin >> from;
		if (from == 'q')
			return false;

		cout << "Move to ";
		cin >> to;
		if (to == 'q')
			return false;

		T org = static_cast<int>(from);
		T des = static_cast<int>(to);

		org = toupper(org) - 65;
		des = toupper(des) - 65;

		if (org > 2 || org < 0 || des > 2 || des < 0)
			cout << "Cannot move from " << from << " to " << to << endl;
		else
		{
			flag = moveDisc(org, des);
			if (flag == false )
				cout << "Cannot move from " << from << " to " << to << endl;
		}
		print();
	}
	return true;
}


