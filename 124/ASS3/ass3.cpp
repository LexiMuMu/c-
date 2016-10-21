#include <iostream>
using namespace std;

struct tree
{
	char search;
	int count;
	tree * left;
	tree * right;
};

void initialize(tree *&);
bool add(tree *&, char, int);
void print(tree *);
bool remove(tree *&, char, int &);

void initialize(tree *&root)
{
	root = NULL;
}

bool add(tree *&root, char letter, int count)
{
	tree * tmptree = new tree;
	tmptree->search = letter;
	tmptree->count = count;
	tmptree->left = NULL;
	tmptree->right = NULL;
	tree * tmp = root;
	tree ** save = NULL;
	bool find = false;
	
	if(root == NULL)
	{
		root = tmptree;
		return true;
	}

	while(find != true)
	{
		if(letter < tmp->search)
		{
			if(tmp->left == NULL)
			{
				save = &(tmp->left);
				find = true;
			}
			else
				tmp = tmp->left;
		}
		else if(letter > tmp->search)
		{
			if(tmp->right == NULL)
			{
				save = &(tmp->right);
				find = true;
			}
			else
				tmp = tmp->right;
		}	
		else if(letter == tmp->search)
		{
			delete tmptree;
			return false;
		}		
	}
	*save = tmptree;
}


void print(tree * root)
{
	if(root == NULL)
		return;
	print(root->left);
	cout << root->search;
	print(root->right);
}


bool remove(tree *& root, char letter, int & count)
{
	if(root == NULL)
	{
		cout << "Nothing to delete.\n";
		return false;
	}
	if(letter < root->search)
	{
		remove(root->left, letter, count);
	}
	else if(letter > root->search)
	{
		remove(root->right, letter, count);
	}
	else if(letter == root->search)
	{
		if(root->left != NULL && root->right == NULL)
		{
			count = root->count;
			tree * tmptree = root;
			root = root->left;
			delete tmptree;
			return true;
		}
		else if(root->left == NULL && root->right != NULL)
		{
			count = root->count;
			tree * tmptree = root;
			root = root->right;
			delete tmptree;
			return true;
		}
		else if(root->left == NULL && root->right == NULL)
		{
				delete root;
				root = NULL;
				return true;
		}
		else if(root->left != NULL && root->right != NULL)
		{
			//to find the leftmost of the right tree
			tree * find = root->right;
			
			if(find->left != NULL)
			{
				find = find->left;
			}
			find->left = root->left;
			count = root->count;
			tree * tmptree = root;
			root = root->right;
			delete tmptree;
		}
	}
}



int main()
{
	tree* a;
	initialize(a);

	int save;
	remove(a, 'x', save);

	add(a, 'l', 0);
	add(a, 'm', 0);
	add(a, 'n', 0);
	add(a, 'o', 0);
	add(a, 'p', 0);
	add(a, 'q', 0);
	add(a, 'r', 0);
	add(a, 's', 0);
	add(a, 't', 0);
	add(a, 'u', 0);
	add(a, 'v', 0);
	add(a, 'd', 0);
	add(a, 'e', 0);
	add(a, 'f', 0);
	add(a, 'g', 0);
	add(a, 'h', 0);
	add(a, 'i', 0);
	add(a, 'b', 10);
	add(a, 'a', 0);
	add(a, 'c', 0);
	add(a, 'j', 0);
	add(a, 'k', 0);
	add(a, 'y', 0);
	add(a, 'z', 0);
	add(a, 'w', 9);
	add(a, 'x', 5);
	print(a);
	cout << endl;
	remove(a, 'x', save);
	cout << save;

	remove(a, 'b', save);
	cout << save;

	remove(a, 's', save);
	cout << save;

	cout << endl;
	print(a);

	cout << endl;
}