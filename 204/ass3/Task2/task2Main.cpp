/********************************************************************************
 * Filename: task2Main.cpp
 * Name & Student No.: Yanhong Ben, 4845675
 * ASS No: 3
 * File Description: main drive file of task 2 infix to postfix
 *********************************************************************************/

#include <iostream>
#include "postfix.h"
using namespace std;

int main()
{
	string expresion;
	//get expression from input
	getline(cin, expresion);
	//init infix value with expression get from above
	InfixToPostfix inToPost;
	inToPost.setInfix(expresion);

	//change to postfix
	inToPost.convert();
	//print
	cout << inToPost.getPostfix() << endl;

	return 0;
}