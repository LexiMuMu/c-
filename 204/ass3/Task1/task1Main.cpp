/********************************************************************************
 * Filename: test1Main.cpp
 * Name & Student No.: Yanhong Ben, 4845675
 * ASS No: 3
 * File Description: main drive file of task 1 template class,iterator
 *********************************************************************************/

#include <iostream>
using namespace std;

#include "MyList.h"

int main()
{
    cout << "Push integers 0...9 to the back of a linked list." << endl;
    //push
    MyProject::MyList<int> listInt;
    for (int i=0; i<10; i++)
    	listInt.push_back(i);

    cout << "Display integers from the front of the linked list." << endl;
    //print
    listInt.print(cout);
    cout << endl;

    cout << "Push characters A...Z to the back of a linked list." << endl;
    //push
    MyProject::MyList<char> listChar;
    for (int i='A'; i<='Z'; i++)
    	listChar.push_back(i);

    cout << "Display characters from the front of the linked list." << endl;
    //print
    listChar.print(cout);
    cout << endl;

    cout << "Copy a linked list with characters into another linkede list." << endl;
    //copy
    MyProject::MyList<char> listCopyChar(listChar);

    cout << "Display characters from the front of the copy linked list." << endl;
    //print
    listCopyChar.print(cout);
    cout << endl;

    cout << "Push strings Monday...Sunday to the back of a linked list." << endl;
    //push
    MyProject::MyList<string> listString;
    listString.push_back("Monday");
    listString.push_back("Tuesday");
    listString.push_back("Wednesday");
    listString.push_back("Thursday");
    listString.push_back("Friday");
    listString.push_back("Saturday");
    listString.push_back("Sunday");

    cout << "Display strings from the front of the linked list." << endl;
    //print
    listString.print(cout);
    cout << endl;

    return 0;
}