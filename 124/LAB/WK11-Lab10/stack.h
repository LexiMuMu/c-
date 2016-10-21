/****************************************************************
Stack class.
change typedef to allow stacks of different types.

size of stack is set when constructed and does not change
push method throws out_of_range if stack is full
pop method throws out_of_range if stack is empty

****************************************************************/
#ifndef STACK_H
#define STACK_H

typedef int T;

class Stack
{
	public:
		Stack(int size=20);
		Stack(const Stack& from);
		~Stack();

		void push(T val);
		T pop();

		bool isFull();
		bool isEmpty();

	private:
		int n;
		int top;
		T* data;	
};

#endif
