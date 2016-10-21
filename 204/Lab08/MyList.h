/********************************************************************************
 * Filename: MyList.h
 * Name & Student No.: Yanhong Ben, 4845675
 * Lab No: 8
 * File Description: head file of a linked list
 * Date Last Modified: 24/09/2015
 *********************************************************************************/
#include <iostream>

#ifndef MYLIST_H
#define MYLIST_H

namespace MyProject
{
	// class Node definition
    template<class T>
    class Node
    {
    private:
        T data;
        Node<T> *next;
    public:
        Node();
        void setData(T &);
        void setlink(Node *);
        T getData();
        Node<T>* getlink();
    };
    
    template<class T>
    Node<T>::Node()
    {
        next = NULL;
    }
    
    template<class T>
    void Node<T>::setData(T & newData)
    {
        data = newData;
    }
    
    template<class T>
    void Node<T>::setlink(Node *newPtr)
    {
        next = newPtr;
    }
    
    template<class T>
    T Node<T>::getData()
    {
        return data;
    }
    
    template<class T>
    Node<T>* Node<T>::getlink()
    {
        return next;
    }
    


    //class MyList definition
    template<class T>
    class MyList
    {
    private:
        Node<T> *head;
        Node<T> *tail;
    public:
        MyList();
        ~MyList();
        void insert(T&);
        void print(std::ostream&);
    };
    
    template<class T>
    MyList<T>::MyList()
    {
        head = NULL;
        tail = NULL;
    }
    
    template<class T>
    MyList<T>::~MyList()
    {
        Node<T> *curr;
        curr = head;
        while (head != NULL && tail != NULL)
        {
            head = curr->getlink();
            delete curr;
            curr = head;
        }
        head = NULL;
        tail = NULL;
    }
    
    template<class T>
    void MyList<T>::insert(T &elt)
    {
    	bool found = false;
        Node<T> *temPtr = new Node<T>;

        temPtr->setData(elt);
		temPtr->setlink(NULL);
        if(head == NULL)
        {
            head = temPtr;
            tail = temPtr;
        }
        //if list is empty, just add the new node at the first position.
        else
        {
            Node<T> *curr = head;
            while (curr->getlink() != NULL && !found)
            {
            	if (head->getData() < elt)
                {
                	if(curr->getlink()->getData() > elt)
                	{
                		temPtr->setlink(curr->getlink());
                		curr->setlink(temPtr);
                        found = true;
                    }
                    else
                        curr = curr->getlink();
                }
                else
                {
                	temPtr->setlink(head);
            		head = temPtr;
            		found = true;
                }
            }
            //compare each data in the linked list to find the right position for the new node

            if (!found)
            {
            	curr->setlink(temPtr);
           		tail = temPtr;
           	}
            //if new node is bigger than every nodes in the list, just add the new node to the buttom
        }
    }
    
    template<class T>
    void MyList<T>::print(std::ostream& out)
    {
        Node<T> *temPtr = head;
        while (temPtr != NULL)
        {
            out << temPtr->getData() << " ";
            temPtr = temPtr->getlink();
        }
    }
}

#endif


