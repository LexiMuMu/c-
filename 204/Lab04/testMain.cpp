/********************************************************************************
* Filename: mylist.h                                         			   		
* Name & Student No.: Yanhong Ben, 4845675															
* Lab No: 4
* File Description: drive file of mylist
* Date Last Modified: 26/08/2015
*********************************************************************************/

#include <iostream>
#include <stdexcept>
using namespace std;

#include "mylist.h"

int main()
{
	Item temp;
	MyStack stack;
	cout << "Input integers: ";

	while (cin >> temp)
		stack.push(temp);

	cout << "\nPop from the stack: ";

	try
	{
		while(true)
			cout << stack.pop() << " ";
		cout << endl;
	}
	catch(out_of_range err)
	{
		cout << endl;
		cout << "error: " << err.what() << endl;
	}
	return 0;
}

