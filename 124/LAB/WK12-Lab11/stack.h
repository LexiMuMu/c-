/****************************************************************
Stack class.
change typedef in dataType.h to allow stacks of different types.

size of stack is set when constructed and does not change
constructor throws bad_alloc if stack cannot be allocated
push method throws out_of_range if stack is full
pop method throws out_of_range if stack is empty
peek method throws out_of_range if stack is empty

****************************************************************/
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "dataType.h"

class Stack
{
	public:
		Stack(int size=20);
		Stack(Stack& from);
		~Stack();

		void push(T val);
		T pop();
		T peek();
		void print(std::ostream& o);

		bool isFull();
		bool isEmpty();

	private:
		int n;
		int top;
		T* data;	
};

#endif

