/************************************************************
*      Filename: pqueue.cpp                                 *
*      Login: lm890                                         *
*      lab No: Assignment 5                                 *
*      File Description: define the queue functions         *
*      Date Last Modified: 5/6/2015                         *
************************************************************/
#include <iostream>
#include "pqueue.h"

PQueue::PQueue()
{
	while(list.hasMore())
		list.pop_front();
}

PQueue::PQueue(const PQueue& copy)
{
	DLinkedlist tmp(copy.list);
	while(tmp.hasMore())
	{
		list.insert(tmp.front());
		tmp.pop_front();
	}
}

void PQueue::enqueue(const item & input)
{
	list.insert(input);
}

item PQueue::dequeue()
{
	item tmp = list.front();
	list.pop_front();
	return tmp;
}

item PQueue::peek()
{
	item tmp = list.front();
	return tmp;
}

item PQueue::removeLowest()
{
	item tmp = list.back();
	list.pop_back();
	return tmp;
}

bool PQueue::find(const unsigned int needed, item & store)
{
	return list.exist(needed, store);
}

void PQueue::incrementPriority(const unsigned int find)
{
	item store;
	if(list.exist(find, store))
	{
		if(store.priority == 0)
			return;
		list.remove(find);
		if(store.priority >= 2)
			store.priority -= 2;
		else
			store.priority = 0;

		enqueue(store);
	}

}

void PQueue::merge(PQueue input)
{
	while(input.list.hasMore())
	{
		list.insert(input.list.front());
		input.list.pop_front();
	}
}

void PQueue::print(ostream & out)
{
	list.printList(out);
}


