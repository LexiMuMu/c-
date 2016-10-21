/************************************************************
*      Filename: task.h                                     *
*      Login: lm890                                         *
*      lab No: Assignment 5                                 *
*      File Description: define the compare and print       *
*      Date Last Modified: 5/6/2015                         *
************************************************************/
#include <iostream>
#include <cstring>
#include <iomanip>
#include "task.h"

int compare(task a, task b)
{
	return b.priority - a.priority;
}

ostream & print(ostream & out, task data)
{
	out << setw(15) << left << data.userID;
	out << setw(6) << left << data.taskID;
	out << setw(2) << left << data.priority;
	out << left << data.commandPath << endl;
}
