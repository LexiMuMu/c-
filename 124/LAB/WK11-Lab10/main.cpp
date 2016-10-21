/************************************************
 Filename: main.cpp                           
 Name: Yanhong Ben								
 Time: Mon 8:30-10:30 17.106					
 Lab No: 10 										
 File Description: implement an array stack		
 Date Last Modified: 18/05/2015                
*************************************************/


#include <iostream>
#include <stdexcept>
using namespace std;

#include "stack.h"

int main()
{
	Stack st;
	int size = 20;

	cout << "Set stack full with given array size" << endl;
	for (int i=0; i<size; i++)
	{
		st.push(i);	
	}

	Stack copy(st);//cout stack value by using copied stack
	for (int i=0; i<size; i++)
		cout << copy.pop() << " ";
	cout << endl;

	if (st.isFull())
	{
		cout << endl;
		cout << "Stack is full now." << endl;
	}

	cout << "Then try to push 1 more value into full stack" << endl;
	try
	{
			st.push(20);
	}
	catch(out_of_range err)
	{
		cout << "error: " << err.what() << endl;
	}

	cout << endl;
	cout << "Let us try empty error exception." << endl;
	cout << "Now we pop the value out by pop 1 more values." << endl;
	for (int i=0; i<size+1; i++)
	{
		try
		{
			cout << st.pop() << " ";
		}
		catch(out_of_range err)
		{
			cout << endl;
			cout << "error: " << err.what() << endl;
		}
	}
	return 0;
}
