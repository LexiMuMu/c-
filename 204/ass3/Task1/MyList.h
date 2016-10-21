/********************************************************************************
 * Filename: MyList.h
 * Name & Student No.: Yanhong Ben, 4845675
 * ASS No: 3
 * File Description: head file of task 1 template class,iterator
 *********************************************************************************/

#include <iostream>

#ifndef MYLIST_H
#define MYLIST_H

namespace MyProject
{
    //class Node definition
    template<class T>
    class Node
    {
    private:
        T data;
        Node<T> *next;
    public:
        Node(){next = NULL;}; //default constructor
        void setData(const T &);
        void setLink(Node *);
        T getData();
        Node<T>* getLink();
    };
    
    //implement Node functions
    template<class T>
    void Node<T>::setData(const T &newData)
    {
        data = newData;
    }
    
    template<class T>
    void Node<T>::setLink(Node *newPtr)
    {
        next = newPtr;
    }
    
    template<class T>
    T Node<T>::getData()
    {
        return data;
    }
    
    template<class T>
    Node<T>* Node<T>::getLink()
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
            MyList(){head = NULL; tail = NULL;}; //default constructor
            MyList(const MyList &); //copy constructor
            ~MyList(); //deconstructor
            void push_front(const T &);
            void push_back(const T &);
            bool isEmpty();
            T front();
            T back();
            void pop_front();
            void pop_back();
            //nested class iterator inside MyList
            class iterator
            {
                friend class MyList;
                private:
                    Node<T> *current;
                    Node<T> *last;
                public:
                    iterator() {current = NULL; last = NULL;}; //constructor
                    iterator(Node<T> *, Node<T> *); //set value of iterator
                    T operator*();
                    void operator++(int);
                    bool operator!=(const iterator&);
            };
            iterator begin() const;
            iterator end() const;
            void print(ostream &) const;
    };

    //implement of MyList functions
    template<class T>
    MyList<T>::MyList(const MyList &list)
    {
        head = NULL;
        Node<T> *curr = list.head;
        while(curr != NULL)
        {
            push_back(curr->getData());
            curr = curr->getLink();
        }
    }

    template<class T>
    MyList<T>::~MyList()
    {
        Node<T> *curr;
        curr = head;
        while (head != NULL && tail != NULL)
        {
            head = curr->getLink();
            delete curr;
            curr = head;
        }
        head = NULL;
        tail = NULL;
    }

    template<class T>
    void MyList<T>::push_front(const T &entry) 
    {
        Node<T> *new_ptr = new Node<T>;
        new_ptr->setData(entry);
        new_ptr->setLink(head);
        head = new_ptr;
        if(tail == NULL)
            tail = new_ptr;
    }

    template<class T>
    void MyList<T>::push_back(const T &entry) 
    {
        Node<T> *new_ptr = new Node<T>;
        new_ptr->setData(entry);
        new_ptr->setLink(NULL);
        if(tail != NULL) //Not an empty linked list
            tail->setLink(new_ptr);
        else //Linked list is empty, head points to the first node
            head = new_ptr;
        tail = new_ptr;
    }

    template<class T>
    bool MyList<T>::isEmpty()
    {
        return (head == NULL && tail == NULL);
    }
    
    template<class T>
    T MyList<T>::front()
    {
        T data;
        if(head != NULL)
            data = head->getData();
        return data;
    }

    template<class T>
    T MyList<T>::back()
    {
        T data;
        if(tail != NULL)
            data = tail->getData();
        return data;
    }

    template<class T>
    void MyList<T>::pop_front()
    {
        Node<T> *remove_ptr = head;
        if(remove_ptr != NULL) 
        {
            //If there is only one node left
            if(head == tail)
                tail = NULL;
            //Not an empty linked list        
            head = remove_ptr->getLink();
            delete remove_ptr;
        }
    }

    template<class T>
    void MyList<T>::pop_back()
    {
        Node<T> *remove_ptr = head;
        //list is not empty
        if(!isEmpty()) 
        {
            //If there is only one node left
            if(head == tail)
            {
                head = NULL;
                tail = NULL;
            }
            else
            {
                while(remove_ptr->getLink()->getLink() != NULL)
                    remove_ptr = remove_ptr->getLink();
                delete tail;
                tail = remove_ptr;
                tail->setLink(NULL);
            }
        }
    }
    
    //implement nested class functions
    template<class T>
    MyList<T>::iterator::iterator(Node<T> *a, Node<T> *b)
    {
        current = a;
        last = b;
    }

    template<class T>
    T MyList<T>::iterator::operator*()
    {
        return current->getData();
    }

    template<class T>
    void MyList<T>::iterator::operator++(int)
    {
        current = current->getLink();
    }

    //implement MyList function related to the nested class
    template<class T>
    bool MyList<T>::iterator::operator!=(const iterator& i)
    {
        return (current != i.current || last != i.last);
    }

    template<class T>
    typename MyList<T>::iterator MyList<T>::begin() const
    {
        return iterator(head, tail);
    }

    template<class T>
    typename MyList<T>::iterator MyList<T>::end() const
    {
        return iterator(NULL, tail);
    }

    template<class T>
    void MyList<T>::print(ostream & out) const
    {
        typename MyList<T>::iterator i;
        for(i=begin(); i!=end(); i++)
            out << *i << ' ';
        out << endl;
    }
}

#endif

