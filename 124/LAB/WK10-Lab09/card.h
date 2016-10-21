/************************************************
* Filename: card.h 	                            *
* Name: Yanhong Ben								*
* Time: Mon 8:30-10:30 17.106					*
* Lab No: 9										*
* File Description: play cards source file		*
* Date Last Modified: 14/05/2015                *
*************************************************/

#include <iostream>
using namespace std;

class card
{
	public:
		card();
		card(int);
		void set(int);
		void print(ostream&) const;
	private:
		int value;
		// 0-51, -1 means uninitialised
};

