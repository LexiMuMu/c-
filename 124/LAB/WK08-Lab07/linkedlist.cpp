#include <iostream>
#include <cstring>
#include "linkedList.h"
using namespace std;

// initialise takes the head node pointer and sets it to NULL.
void initialise(word*& head)	
{
	head = NULL;
}

// addnode takes a word to insert into the list and a
// pointer to the head of the list.
// If the word exists in the list then it finds it and increments
// the count indicating it has been seen before. If it is a new
// word then the word is inserted at the end of the list
void addnode(char data[], word*& head)	
{
	word *temp = new word;
	strcpy(temp->data, data);
	temp->count = 1;
	temp->next = NULL;

	if (head == NULL)
	{	
		head = new word;
		strcpy(head->data, data);
		head->count = 1;
		head->next = NULL;
		delete temp;
		return;
	}
	//if the list is empty this will be the first node so add it

	else
	{		
		word *cur = head;
		while(cur->next != NULL)
		{
			if (strcmp (cur->data, temp->data) == 0)
			{
				cur->count ++;
				delete temp;
				return;
			}
			cur = cur->next;
		}

		if (strcmp (cur->data, temp->data) == 0)
		{
			cur->count ++;
			delete temp;
			return;
		}
		//otherwise while there is still a record to look at
		//if the data matches count it and we are done
		cur->next = temp;
		//if we went off the end of the list without finding anything
		//then create a new node and add it to the end of the list
	}
}

// printnodes is given the head pointer and prints
// out each word and count - it does this for every node in
// the list.
void printnodes(word*& head)		
{
	word *cur = head;
	cout << "words" << "			" << "count" << endl;
	cout << "----------------------------------" << endl;
	while (cur != NULL)
	{
		if (strlen(cur->data) > 7)
		{
			cout << cur->data << "		" << cur->count << endl;
		}
		else
		{
			cout << cur->data << "			" << cur->count << endl;
		}
		
		cur = cur->next;
	} 

}

//is given the head pointer and deletes the entire linked list
//creating an empty list (as though initialise had just been called)
void freelist(word*& head)
{
	while (head != NULL)
	{
		word *temp = head;
		head = head->next;
		delete temp;
	}
	initialise(head);
}

