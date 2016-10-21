/********************************************************************************
 * Filename: postfix.h
 * Name & Student No.: Yanhong Ben, 4845675
 * ASS No: 3
 * File Description: head file of task 2 infix to postfix
 *********************************************************************************/

#include <iostream>
#include <string>

#ifndef POSTFIX_H
#define POSTFIX_H

class InfixToPostfix
{
	private:
		std::string infix;
		std::string postfix;
	public:
		void setInfix(const std::string &);
		void convert();
		std::string getPostfix();
};

#endif

