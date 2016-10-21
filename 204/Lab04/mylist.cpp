/********************************************************************************
* Filename: mylist.cpp                                         			   		
* Name & Student No.: Yanhong Ben, 4845675															
* Lab No: 4
* File Description: implement file of mylist
* Date Last Modified: 26/08/2015
*********************************************************************************/

#include <iostream>
#include <stdexcept>
using namespace std;

#include "mylist.h"

//Implementations for the Node
Node::Node()
{
	data = 0;
	link = NULL;
}

void Node::setData(const Item & newData)
{
	data = newData;
}

void Node::setLink(Node * newPtr)
{
	link = newPtr;
}

Item Node::getData()
{
	return data;
}

Node * Node::getLink()
{
	return link;
}


//Implementations for the Linkedlist
Mylist::Mylist()
{
	head = NULL;
}

Mylist::~Mylist()
{
	Node *ptr;
	ptr = head;
	while (ptr != NULL)
	{
		head = ptr->getLink();
		delete ptr;
		ptr = head;
	}
	head = NULL;
}

void Mylist::push_front(Item & newData)
{
	Node *new_ptr = new Node;
	new_ptr->setData(newData);
	new_ptr->setLink(head);
	head = new_ptr;
}

void Mylist::pop_front()
{
	Node *rm_ptr = head;
	if(rm_ptr != NULL)
	{
		head = rm_ptr->getLink();
		delete rm_ptr;
	}
}

Item Mylist::front()
{
	Item data;
	if (head != NULL)
		data = head->getData();
	return data;
}

bool Mylist::isEmpty()
{
	return (head == NULL);
}

//implement for the stack
MyStack::MyStack(){};

bool MyStack::isEmpty()
{
	return list.isEmpty();
}

void MyStack::push(Item & newData)
{
	list.push_front(newData);
}

Item MyStack::pop()
{
	Item data = list.front();

	if (list.isEmpty())
		throw(out_of_range("Stack is empty."));
	else
		list.pop_front();
	return data;
}

Item MyStack::stackTop()
{
	Item data = list.front();
	return data;
}

