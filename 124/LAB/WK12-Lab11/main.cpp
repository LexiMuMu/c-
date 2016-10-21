/**********************************************************
 Filename: main.cpp                          
 Name: Yanhong Ben, 4845675						
 Time: Mon 8:30-10:30 17.106					
 Lab No: 11 										
 File Description: main program to play the hanoi game		
 Date Last Modified: 25/05/2015                
***********************************************************/

#include <iostream>
#include <cstring>
using namespace std;

#include "hanoi.h"

int main()
{
	char yesOrno;
	Hanoi play;

	play.rules();
	play.setup();
	play.print();

	if (!play.run())
		cout << "Oh well, never mind\n";

	cout << "play again(y/n)?\n";
	cin >> yesOrno;

	while (yesOrno == 'y')
	{
		play.setup();
		play.print();

		if (!play.run())
			cout << "Oh well, never mind\n";

		cout << "play again(y/n)?\n";
		cin >> yesOrno;
	}
	cout << "Bye" << endl;
	
	return 0;
}

