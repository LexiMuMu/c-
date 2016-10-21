/**********************************************************
 Filename: hanoi.h                           
 Name: Yanhong Ben, 4845675						
 Time: Mon 8:30-10:30 17.106					
 Lab No: 11 										
 File Description: definitation of the class of hanoi game		
 Date Last Modified: 25/05/2015                
***********************************************************/

#ifndef HANOI_H
#define HANOI_H
#include <iostream>
#include "dataType.h"
#include "stack.h"

const int SIZE = 3;

class Hanoi
{
	public:
		bool run();
		void rules();
		bool setup();
		bool isSolved();
		void print();
		bool moveDisc(T, T);
		bool move();

	private:
		Stack stage[SIZE];
};

#endif

