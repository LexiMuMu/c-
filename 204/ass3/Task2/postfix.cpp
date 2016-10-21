/********************************************************************************
 * Filename: postfix.cpp
 * Name & Student No.: Yanhong Ben, 4845675
 * ASS No: 3
 * File Description: implementation file of task 2 infix to postfix
 *********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

#include "postfix.h"
#include "Stack.h"


void InfixToPostfix::setInfix(const std::string &entry)
{
	infix = entry;
}

void InfixToPostfix::convert()
{
	Stack<char> stack;
	stack.push('(');
	infix += ')';
	int i = 0; //index of the string
	char tempCh; //template stor char value of the string
	while (!stack.isEmpty())
	{
		switch(infix.at(i))
		{
			case '(':
				stack.push(infix.at(i));
				break;
			case '+':
			case '-':
				postfix += ' ';
				tempCh = stack.stackTop();
				while (tempCh != '(')
				{
					postfix += stack.pop();
					postfix += ' ';
					tempCh = stack.stackTop();
				}
				stack.push(infix.at(i));
				break;
			case '*':
			case '%':
			case '/':
				postfix += ' ';
				tempCh = stack.stackTop();
				while(tempCh == '*' || tempCh == '%' || tempCh == '/')
				{
					postfix += stack.pop();
					postfix += ' ';
					tempCh = stack.stackTop();
				}
				stack.push(infix.at(i));
				break;
			case ')':
				while(stack.stackTop() != '(')
				{
					postfix += ' ';
					postfix += stack.pop();
				}
				stack.pop();
				break;
			default:
				if(infix.at(i) != ' ')
					postfix += infix.at(i);

		}
		i++;
	}
}

std::string InfixToPostfix::getPostfix()
{
	return postfix;
}

