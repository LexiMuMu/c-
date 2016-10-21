/********************************************************************************
* Filename: mylist.h                                         			   		
* Name & Student No.: Yanhong Ben, 4845675															
* Lab No: 4
* File Description: head file of mylist
* Date Last Modified: 26/08/2015
*********************************************************************************/

typedef int Item;

class Node{
private:
	Item data;
	Node* link;
public: 
	Node();
	void setData(const Item &);
	void setLink(Node *);
	Item getData();
	Node * getLink();
};

class Mylist
{
public:
	Mylist();
	~Mylist();
	void push_front(Item &);
	void pop_front();
	Item front();
	bool isEmpty();
private:
	Node* head;
};

class MyStack
{
public:
	MyStack();
	bool isEmpty();
	void push(Item &);
	Item pop();
	Item stackTop();
private:
	Mylist list;
};
