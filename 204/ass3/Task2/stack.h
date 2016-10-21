/********************************************************************************
 * Filename: stack.h
 * Name & Student No.: Yanhong Ben, 4845675
 * ASS No: 3
 * File Description: head file of task 2 infix to postfix
 *********************************************************************************/

#include <iostream>

#include "MyList.h"

#ifndef STACK_H
#define STACK_H

template<class T>
class Stack
{
	private:
		MyProject::MyList<T> list;
	public:
		void push(T);
		T pop();
		bool isEmpty();
		void print(ostream &);
		T stackTop();
};

template<class T>
void Stack<T>::push(T entry)
{
	list.push_back(entry);
}

template<class T>
T Stack<T>::pop()
{
	T temp = list.back();
	list.pop_back();
	return temp;
}

template<class T>
bool Stack<T>::isEmpty()
{
	return list.isEmpty();
}

template<class T>
void Stack<T>::print(ostream &out)
{
	list.print(out);
}

template<class T>
T Stack<T>::stackTop()
{
	T temp = list.back();
	return temp;
}


#endif

