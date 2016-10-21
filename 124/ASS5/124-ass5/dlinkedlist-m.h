/************************************************************
*      Filename: dlinkedlist.h                              *
*      Login: lm890                                         *
*      lab No: Assignment 5                                 *
*      File Description: define the list and node           *
*      Date Last Modified: 5/6/2015                         *
************************************************************/
#include <iostream>
#include "task.h"


#ifndef _LIST
#define _LIST
// typedef DNode * ptr;
typedef task item;

class DNode
{
friend class DLinkedlist;

private:
	item data;
	DNode * previous;
	DNode * next;

public:
	DNode();
	DNode(const item&);
};

class DLinkedlist
{
private:
	DNode * head;
	DNode * tail;

public:
	DLinkedlist();
	DLinkedlist(const DLinkedlist&);
	~DLinkedlist();
	void push_front(const item&);
	void push_back(const item&);
	void pop_front();
	void pop_back();
	item front();
	item back();
	bool exist(const unsigned int&, item &);
	void insert(const item&);
	void printList(ostream &);
	bool hasMore();
	void remove(const unsigned int);
};
#endif
