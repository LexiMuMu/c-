/************************************************************
BinaryTree class implements a binary search tree. 

It expects a datatype T
and functions
void copy(T &A, const T& B);
int cmp(const T& left, const T& right);
void print(const T& t);
to be defined through datatype.h

Consider how the implementation might change if 
it expected a class T
with appropriate constructors, 
comparison operators and 
stream insertion operator
************************************************************/

#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "datatype.h"

class BinaryTree
{
	public:
		BinaryTree();
		~BinaryTree();
		void insert(const T&);
		bool search(T&, const T&) const;
		void printAll() const;
		void applyToAll(void (*func)(const T&));
		void preorderPrintAll() const;
		bool remove(T&, const T&);
		void clear();
	private:
		struct node;
		typedef node* nptr;
		struct node {
			T data;
			nptr left, right, parent;
		};
		nptr root; 
		void postorderDelete(nptr cur);
		nptr createNode(const T& data) const;
		void insertNode(nptr& cur, const T& data);
		nptr findNode(nptr cur, const T& key) const;
		void inorderPrint(nptr cur) const;
		void preorderPrint(nptr cur) const;
		void inorderApply(nptr cur, void (*func)(const T&)) const;
		bool removeRe(nptr& cur, T& out, const T& key);	
		bool removeNode(nptr& target, T& out);
		nptr findLargest(nptr cur) const;
};

#endif
