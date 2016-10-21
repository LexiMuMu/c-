/****************************************************************
Stack class.
change typedef in dataType.h to allow stacks of different types.

Size of stack is set when constructed and does not change
constructor throws bad_alloc if stack cannot be allocated
push method throws out_of_range if stack is full
pop method throws out_of_range if stack is empty
peek method throws out_of_range if stack is empty
****************************************************************/

#include <stdexcept>
#include "stack.h"
using namespace std;

Stack::Stack(int size)
{
	n = size;
	top = -1;
	data = new T[n];
}

Stack::Stack(Stack& from)
{
	n = from.n;
	top = from.top;
	data = new T[n];	

	for(int i=0; i<=top; i++)
	{
		data[i] = from.data[i];
	}	
}

Stack::~Stack()
{
	delete[] data;
}

void Stack::push(T val)
{
	if(top == n-1)
		throw out_of_range("cannot push onto full stack");
	
	data[++top] = val;
}

T Stack::pop()
{
	if(top == -1)
		throw out_of_range("cannot pop from empty stack");
	
	return data[top--];
}

bool Stack::isFull()
{
	return (top == n-1);
}

bool Stack::isEmpty()
{
	return (top == -1);
}

void Stack::print(std::ostream& o)
{
	for(int i=0; i<=top; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

T Stack::peek()
{
	return data[top];
}

