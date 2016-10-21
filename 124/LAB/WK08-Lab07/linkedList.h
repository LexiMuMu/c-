#ifndef LINKEDLIST_H
#define LINKEDLIST_H

const int MAX = 128;

struct word
{
	char data[MAX];
	int count;
	word* next;
};

void initialise(word*&);		// initalise the linked list
void addnode(char[], word*&);		// add a word to the list
void printnodes(word*&);		// print the list
void freelist(word*&);			// delete the entire list

#endif
