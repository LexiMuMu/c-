#include <iostream>
#include <cstring>
using namespace std;


const int MAX_WORD = 100;
struct node
{
	void * data;
	node * left;
	node * right;
};

struct Word {
	char word[MAX_WORD];
	double frequency;
};

void init(node * &head, void (*clone_word)(void* &, const void*), 
	void (*compare_word)(const void*, const void*),
	void (*destroy_word)(void* &),
	void (*print_word)(const void*));

static void (*copydata)(void* &, const void*);
static int (*compare)(const void*, const void*);
static void (*deleting)(void* &);
static void (*printing)(const void*);

bool add_word(void*, node* &);
int compare_word(const void*, const void*);
void destroy_word(void* &);
bool remove_word(void *, void * &, node *&);
void print_word(const void* data);
void print_node(const node*);

void init(node * &head, void (*clone_word)(void* &, const void*), 
	int (*compare_word)(const void*, const void*),
	void (*destroy_word)(void* &),
	void (*print_word)(const void*))
{
	head = NULL;
	copydata = clone_word;
	compare = compare_word;
	deleting = destroy_word;//remove?
	printing = print_word;
}

void clone_word(void* &dest, const void* source)
{
	Word * clone = new Word;
	Word * old = (Word*) source;
	strcpy(clone->word, old->word);
	clone->frequency = old->frequency;
	dest = clone;
}

int compare_word(const void* a, const void* b)
{
	Word * i = (Word*) a;
	Word * j = (Word*) b;

	if(i->frequency > j->frequency)
		return 1;
	else if(i->frequency < j->frequency)
		return -1;
	else if(i->frequency == j->frequency)
		return 0;
	return -2;
}

bool add_word(void* data, node* &head)
{
	node* tmp = new node;
	copydata(tmp->data, data);
	tmp->left = NULL;
	tmp->right = NULL;
	node ** save = NULL;
	bool find = false;
	
	if(head == NULL)
	{
		head = tmp;
		return true;
	}
	else
	{
		node * cur = head;
		while(find != true)
		{
			if(compare(data, cur->data) == -1)
			{
				if(cur->left == NULL)
				{
					save = &(cur->left);
					find = true;
				}
				else
					cur = cur->left;
			}
			else if(compare(data, cur->data) == 1)
			{
				if(cur->right == NULL)
				{
					save = &(cur->right);
					find = true;
				}
				else
					cur = cur->right;
			}	
			else if(compare(data, cur->data) == 0)
			{
				delete tmp;
				return false;
			}	

		}
	}
	*save = tmp;
	return true;
}

void destroy_word(void* &data)
{
	delete static_cast<Word*>(data);
}

bool remove_word(void * data, void * &deletenode, node *& cur)
{
	if(cur == NULL)
	{
		cout << "Nothing to delete.\n";
		return false;
	}
	if(compare(data, (Word *)(cur->data)) == -1)
	{
		remove_word(data, deletenode, cur->left);
	}
	else if(compare(data, cur->data) == 1)
	{
		remove_word(data, deletenode, cur->right);
	}
	else if(compare(data, cur->data) == 0)
	{
		if(cur->left != NULL && cur->right == NULL)
		{
			node * tmp = cur;
			cur = cur->left;
			copydata(deletenode, tmp->data);
			deleting(tmp->data);
			delete tmp;
			return true;
		}
		else if(cur->left == NULL && cur->right != NULL)
		{
			node * tmp = cur;
			cur = cur->right;
			copydata(deletenode, tmp->data);
			deleting(tmp->data); 
			delete tmp;
			return true;
		}
		else if(cur->left == NULL && cur->right == NULL)
		{
			copydata(deletenode, cur->data);
			deleting(cur->data);
			delete cur;
			cur = NULL;
			return true;
		}
		else if(cur->left != NULL && cur->right != NULL)
		{
			copydata(deletenode, cur->data);
			//to find the leftmost of the right tree
			node * find = cur->right;
			
			while(find->left != NULL)
			{
				find = find->left;
			}
			find->left = cur->left;
			node * tmp;
			tmp = cur;
			cur = cur->right;
			deleting(tmp->data);
			delete tmp;
		}
	}
	return true;
}

void print_word(const void* data)
{
	Word * print = (Word *) data;
	cout << print->frequency << ": " << print->word << endl;
}

void print_node(const node * head)
{
	if(head == NULL)
	{
		cout << "fool!";
		return;
	}
	if(head->left != NULL)
		print_node(head->left);
	printing(head->data);
	if(head->right != NULL)
		print_node(head->right);
}

int main()
{
	Word *w = new Word;
	node * head;
	init(head, &clone_word, &compare_word, &destroy_word, &print_word);
	
	void *tmp;
	Word * tmpword = new Word;
	tmpword->frequency = 2;
	tmp = tmpword;
	void * data;
	remove_word(tmp, data, head);

      strcpy(w->word, "abc");
      w->frequency = 2;
      add_word(w, head);
      strcpy(w->word, "def");
      w->frequency = 1;
      add_word(w, head);
      strcpy(w->word, "ghi");
      w->frequency = 3;
      add_word(w, head);
      strcpy(w->word, "jkl");
      w->frequency = 5;
      add_word(w, head);
      strcpy(w->word, "mno");
      w->frequency = 4;
      add_word(w, head);
	print_node(head);
	remove_word(tmp, data, head);
	print_node(head);
	printing(data);

	delete w;
	delete tmpword;
}
