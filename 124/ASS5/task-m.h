/************************************************************
*      Filename: task.h                                     *
*      Login: lm890                                         *
*      lab No: Assignment 5                                 *
*      File Description: define the struct                  *
*      Date Last Modified: 5/6/2015                         *
************************************************************/
#include <iostream>
#include <cstring>

#ifndef _TASK
#define _TASK
using namespace std;
const int MAX = 100;

struct task
{
	char userID[10];
	unsigned int taskID;
	unsigned int priority;
	char commandPath[MAX];
};

int compare(task, task);
ostream & print(ostream &, task);
#endif
