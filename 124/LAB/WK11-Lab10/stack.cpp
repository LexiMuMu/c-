/************************************************
 Filename: stack.cpp                           
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


Stack::Stack(int size)
{
	n = size;
	top = -1;
	data = new T [size];
}

Stack::~Stack()
{
	delete [] data;
}

void Stack::push(T val)
{
	if(isFull())
	{
		throw(out_of_range("Stack is full."));
	}
	else
	{
		top++;
		data[top] = val;
	}
}

T Stack::pop()
{
	T valpop = 0;
	if (isEmpty())
	{
		throw(out_of_range("Stack is empty."));
	}
	else
	{
		valpop = data[top];
		top--;
	}
	return valpop;
}

bool Stack::isFull()
{
	if(top == n-1)
		return 1;
	return 0;
}

bool Stack::isEmpty()
{
	return (top < 0);
}

Stack::Stack(const Stack& from)
{
	n = from.n;
	top = from.top;
	data = new T [n];
	for (int i=0; i<n; i++)
		data[i] = from.data[i];
}

