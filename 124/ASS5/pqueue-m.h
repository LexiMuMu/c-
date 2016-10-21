/************************************************************
*      Filename: pqueue.h                                   *
*      Login: lm890                                         *
*      lab No: Assignment 5                                 *
*      File Description: define the queue                   *
*      Date Last Modified: 5/6/2015                         *
************************************************************/
#include <iostream>

#include "dlinkedlist.h"

#ifndef _QUEUE
#define _QUEUE

class PQueue
{
private:
	DLinkedlist list;
public:
	PQueue();
	PQueue(const PQueue&);
	void enqueue(const item&);
	item dequeue();
	item peek();
	item removeLowest();
	bool find(const unsigned int, item &);
	void incrementPriority(const unsigned int);
	void merge(PQueue);
	void print(ostream &);
};

#endif
