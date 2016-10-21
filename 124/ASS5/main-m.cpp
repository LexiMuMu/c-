/************************************************************
*      Filename: main.cpp                                   *
*      Login: lm890                                         *
*      lab No: Assignment 5                                 *
*      File Description: test the functions                 *
*      Date Last Modified: 5/6/2015                         *
************************************************************/
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include "task.h"
#include "dlinkedlist.h"
#include "pqueue.h"

using namespace std;

int main()
{
	PQueue q1;
	PQueue q2;
	srand(time(0));
	int id = 0;
	item store;
	ostringstream convert;
	for(int i = 0; i < 10; i++)
	{
		item tmp;
		//generate userID
		char user[10];
		id = rand()%101;

		if (id <= 80)
			strcpy(user, "user");
		else
		{
			strcpy(user, "guest");
			id -= 81;
		}

		strcpy(tmp.userID, user);
		strcat(tmp.userID, "_");
		convert << id;
		strcat(tmp.userID, (convert.str()).c_str());
		convert.str("");

		//commandpath

		strcpy(tmp.commandPath, "/home/");
		strcat(tmp.commandPath, user);
		strcat(tmp.commandPath, "/");
		strcat(tmp.commandPath, "q1/");
		strcat(tmp.commandPath, tmp.userID);
		strcat(tmp.commandPath, "/");

		//taskID
		tmp.taskID = rand()%10000;

		//priority
		tmp.priority = rand()%10;
		if(!q1.find(tmp.taskID, store))
			q1.enqueue(tmp);
		else
			i--;
	}

	for(int i = 0; i < 10; i++)
	{
		item tmp;
		//generate userID
		char user[10];
		id = rand()%101;

		if (id <= 80)
			strcpy(user, "user");
		else
		{
			strcpy(user, "guest");
			id -= 81;
		}

		strcpy(tmp.userID, user);
		strcat(tmp.userID, "_");
		convert << id;
		strcat(tmp.userID, (convert.str()).c_str());
		convert.str("");

		//commandpath

		strcpy(tmp.commandPath, "/home/");
		strcat(tmp.commandPath, user);
		strcat(tmp.commandPath, "/");
		strcat(tmp.commandPath, "q2/");
		strcat(tmp.commandPath, tmp.userID);
		strcat(tmp.commandPath, "/");

		//taskID
		tmp.taskID = rand()%10000;

		//priority
		tmp.priority = rand()%10;
		if(!q2.find(tmp.taskID, store))
			q2.enqueue(tmp);
		else
			i--;
	}

	cout << "Priority queue q1 tasks: \n";
	q1.print(cout);

	cout << "\nPriority queue q2 tasks: \n";
	q2.print(cout);

	q1.merge(q2);
	PQueue q3(q1);

	cout << "\nMerge q1 and q2 to a priority queue q3, q3 tasks are: \n";
	q3.print(cout);

	cout << "\nPeek q3, the data contains: \n";
	print(cout, q3.peek());
	cout << "After peek, the priority queue q3 tasks are: \n";
	q3.print(cout);

	cout << "\nDequeue q3, the data contains: \n";
	print(cout, q3.dequeue());
	cout << "After Dequeue, the priority queue q3 tasks are: \n";
	q3.print(cout);

	cout << "\nThe lowest item contains:\n";
	print(cout, q3.removeLowest());
	cout << "After remove the lowest item, "
		<< "the priority queue q3 tasks are:\n";
	q3.print(cout);

	cout << "\nInput a task id to find the task: ";
	unsigned int find;
	cin >> find;
	if(!q3.find(find, store))
		cout << "Task " << find << " does not exist." << endl;
	else
	{
		cout << "Found the task: \n";
		print(cout, store);
		q3.incrementPriority(find);
		cout << "increase the task priority by 2.\n";
	}
	cout << "The priority queue q3 tasks are:\n";
	q3.print(cout);
}
