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

#include <iostream>
#include "binarytree.h"


BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	postorderDelete(root);
	root = NULL;
}

void BinaryTree::insert(const T& in)
{
	if (root==NULL)
		root = createNode(in);
	else
		insertNode(root, in);
}

bool BinaryTree::search(T & out, const T& key) const
{
	nptr target = findNode(root, key);
	if (target==NULL)
		return false;
	else
	{
		copy(out, target->data);
		return true;
	}
}

void BinaryTree::printAll() const
{
	inorderPrint(root);
}

void BinaryTree::preorderPrintAll() const
{
	preorderPrint(root);
}

void BinaryTree::applyToAll(void (*func)(const T&))
{
	inorderApply(root, func);
}

bool BinaryTree::remove(T& out, const T&key)
{
	return removeRe(root, out, key);
}

void BinaryTree::clear()
{
	postorderDelete(root);
	root = NULL;
}

void BinaryTree::postorderDelete(nptr cur)
{
	if (cur!=NULL) {
		postorderDelete(cur->left);
		postorderDelete(cur->right);
		delete cur;
	}
}

BinaryTree::nptr BinaryTree::createNode(const T &data) const
{
	nptr tmp = new node;
	copy(tmp->data, data);
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = NULL;
	return tmp;
}

void BinaryTree::insertNode(nptr &cur, const T& data)
{
	if (cmp(data, cur->data) > 0) {
		if (cur->right==NULL) {
			cur->right = createNode(data);
			(cur->right)->parent = cur;
		} else
			insertNode(cur->right, data);
	} else {	
		if (cur->left==NULL) {
			cur->left = createNode(data);
			(cur->left)->parent = cur;
		} else
			insertNode(cur->left, data);
	}
}

BinaryTree::nptr BinaryTree::findNode(nptr cur, const T& key) const
{
	if (cur==NULL)
		return NULL;
	else if (cmp(key,cur->data)==0)
	{
		return cur;
	} else if (cmp(key, cur->data) > 0)
	{
		return findNode(cur->right, key);
	} else
		return findNode(cur->left, key);
}

void BinaryTree::inorderPrint(nptr cur) const
{
	if(cur != NULL) {
		inorderPrint(cur->left);
		print(cur->data);
		inorderPrint(cur->right);
	}
}

void BinaryTree::preorderPrint(nptr cur) const
{
		if(cur != NULL) {
		print(cur->data);
		inorderPrint(cur->left);
		inorderPrint(cur->right);
	}
}

void BinaryTree::inorderApply(nptr cur, void (*func)(const T&)) const
{
		if(cur != NULL) {
		inorderApply(cur->left, func);
		func(cur->data);
		inorderApply(cur->right, func);
	}
}

bool BinaryTree::removeRe(nptr &cur, T& out, const T& key)
{
	if (cur==NULL)
		return false;
	if (cmp(key, cur->data)>0)
		return removeRe(cur->right, out, key);
	else if (cmp(key, cur->data)<0)
		return removeRe(cur->left, out, key);
	else	// found!
		return removeNode(cur, out);
}

bool BinaryTree::removeNode(nptr &target, T& out)
{
	if (target==NULL)
		return false;
	if (target->left!=NULL&&target->right!=NULL) {
		nptr largest=findLargest(target->left);
		largest->right = target->right;
		target->right->parent = largest;	
	}
	copy(out, target->data);

	nptr tmp = target;
	if (target->left ==NULL)
		target = target->right;
	else 
		target = target->left;
	if (target!=NULL)
		target->parent = tmp->parent;
	delete tmp;
	return true;
}

BinaryTree::nptr BinaryTree::findLargest(nptr cur) const
{
	while (cur->right !=NULL)
		cur = cur->right;
	return cur;
}

