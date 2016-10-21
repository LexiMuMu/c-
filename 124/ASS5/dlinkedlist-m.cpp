/************************************************************
*      Filename: dlinklist.cpp                              *
*      Login: lm890                                         *
*      lab No: Assignment 5                                 *
*      File Description: define the list functions          *
*      Date Last Modified: 5/6/2015                         *
************************************************************/
#include "dlinkedlist.h"

DNode::DNode()
{
	previous = NULL;
	next = NULL;
}

DNode::DNode(const item & copy)
{
	strcpy(data.userID, copy.userID);
	data.taskID = copy.taskID;
	data.priority = copy.priority;
	strcpy(data.commandPath, copy.commandPath);
	previous = NULL;
	next = NULL;
}

DLinkedlist::DLinkedlist()
{
	head = NULL;
	tail = NULL;
}

DLinkedlist::DLinkedlist(const DLinkedlist& input)
{
	head = NULL;
	tail = NULL;
	DNode* cur = input.tail;
	while(cur != NULL)
	{
		item data = cur->data;
		push_front(data);
		cur = cur->previous;
	}
}


DLinkedlist::~DLinkedlist()
{
	while(hasMore())
	{
		DNode * tmp = head;
		head = head->next;
		delete tmp;
	}
}

void DLinkedlist::push_front(const item & input)
{
	DNode * tmp = new DNode;
	tmp->data = input;
	tmp->next = head;
	tmp->previous = NULL;
	if(tail == NULL)
		tail = tmp;
	if(head != NULL)
		head->previous = tmp;
	head = tmp;
}

void DLinkedlist::push_back(const item & input)
{
	DNode * tmp = new DNode;
	tmp->previous = tail;
	tmp->data = input;
	tmp->next = NULL;
	if(tail != NULL)
		tail->next = tmp;
	if(!hasMore())
		head = tmp;	
	tail = tmp;
}

void DLinkedlist::pop_front()
{
	if(!hasMore())
	{
		return;
	}

	DNode * pop = head;
	head = head->next;
	if(hasMore())
		head->previous = NULL;
	if(!hasMore())
		tail = NULL;
	delete pop;
}

void DLinkedlist::pop_back()
{
	if(!hasMore())
	{
		return;
	}

	DNode * pop = tail;
	tail = tail->previous;
	if(hasMore())
		tail->next = NULL;
	else
		head = NULL;
	delete pop;
}

item DLinkedlist::front()
{	
	if(!hasMore())
	{
		cout << "No node!\n";
	}
	else
	{
		return head->data;
	}
}

item DLinkedlist::back()
{
	if(!hasMore())
	{
		cout << "No node!\n";
	}
	else
	{
		return tail->data;	
	}
}

bool DLinkedlist::exist(const unsigned int& input, item & store)
{
	DNode * tmp = head;
	while(tmp != NULL)
	{
		if(input == tmp->data.taskID)
		{
			store = tmp->data;
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

void DLinkedlist::insert(const item & input)
{
	if(!hasMore())
	{
		push_front(input);
		return;
	}
	if(input.priority <= head->data.priority)
	{
		push_front(input);
		return;
	}
	else if(input.priority >= tail->data.priority)
	{
		push_back(input);
		return;		
	}
	else
	{
		DNode * cur = head->next;
		while(true)
		{
			if(input.priority <= cur->data.priority)
			{
					DNode * tmp = new DNode;
					tmp->previous = cur->previous;
					tmp->data = input;
					tmp->next = cur;
					cur->previous->next = tmp;
					cur->previous = tmp;

					return;
			}
			else
				cur = cur->next;
		}
	}
}

void DLinkedlist::printList(ostream & out)
{
	if(!hasMore())
	{
		cout << "No node!\n";
		return;
	}
	DNode * tmp = head;
	print(out, tmp->data);
	while(tmp->next != NULL)
	{		
		tmp = tmp->next;
		print(out, tmp->data);
	}
}

bool DLinkedlist::hasMore()
{
	return (head != NULL) && (tail != NULL);
}

void DLinkedlist::remove(const unsigned int find)
{
	if(!hasMore())
	{
		cout << "No node!\n";
		return;
	}
	if(head->data.taskID == find)
	{	
		DNode * tmp = head;
		head = head->next;
		delete tmp;
	}
	else
	{
		DNode * cur = head;
		while(cur != NULL)
		{
			if(cur->data.taskID == find)
			{
				DNode * tmp = cur;
				cur->previous->next = cur->next;

				delete tmp;
			}
			cur = cur->next;
		}
	}

}
