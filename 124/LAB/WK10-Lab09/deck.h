/************************************************
* Filename: deck.h                              *
* Name: Yanhong Ben								*
* Time: Mon 8:30-10:30 17.106					*
* Lab No: 9										*
* File Description: play cards head file		*
* Date Last Modified: 14/05/2015                *
*************************************************/

#include "card.h" 

class deck
{
	public:
		deck();
		void shuffle();
		void deal();
		void print();
	private:
		int size;
		card play[52];
};

