/********************************************************************************
 * Filename: bag.cpp
 * Name & Student No.: Yanhong Ben, 4845675
 * Lab No: 7
 * File Description: implementation file of bag
 * Date Last Modified: 17/09/2015
 *********************************************************************************/

#include <iostream>
#include "Bag.h"


template <class T>
MYLIB::Bag<T>::Bag()
{
    size = MAX;
	curr_num = 0;
	data = new T[size];
}

template <class T>
MYLIB::Bag<T>::~Bag()
{
	delete [] data;
}

template<class T>
MYLIB::Bag<T>::Bag(const MYLIB::Bag<T>& newBag)
{
	size = newBag.size;
	curr_num = newBag.curr_num;	
	data = new T[size];
	for(int i=0; i<curr_num; i++)
		data[i] = newBag.data[i];
}

template <class T>
void MYLIB::Bag<T>::add(T newInst)
{
    if (curr_num >= size)
    {
    	T temp[size];
    	for (int i=0; i<size; i++)
    		temp[i] = data[i];
    	delete [] data;
    	size += MAX;
    	data = new T[size];
    	for (int i=0; i<curr_num; i++)
    		data[i] = temp[i];
    	data[curr_num] = newInst;
	    curr_num++;
    	//copy to template dynamic array and copy back to new dynamic array
    }
	data[curr_num] = newInst;
	curr_num++;
}

template <class T>
void MYLIB::Bag<T>::remove(T rmInst)
{
	bool isFound = false;
	for (int i=0; i<curr_num && !isFound; i++)
	{
		if (data[i] == rmInst)
		{
			for (int j=i; j<curr_num-1; j++)
				data[j] = data[j+1];
			isFound = true;
			curr_num--;
		}
	}
	if (isFound == false)
        std::cout << "No value found in Bag, pls re-input." << std::endl;
}

template <class T>
MYLIB::Bag<T> MYLIB::Bag<T>::operator+(const MYLIB::Bag<T> & newBag)
{
    Bag<T> des;
    des.curr_num = newBag.curr_num + curr_num;
    if (des.curr_num > size)
    {
        delete [] des.data;
        des.size = newBag.curr_num + curr_num;
        des.data = new T[des.size];
    }
    
    for (int i=0; i<curr_num; i++)
        des.data[i] = data[i];
	for (int i=curr_num; i<(des.size); i++)
        des.data[i] = newBag.data[i-curr_num];

    return des;
}

template <class T>
std::ostream& MYLIB::operator<<(std::ostream & out, const MYLIB::Bag<T> & newBag)
{
    for (int i=0; i<newBag.curr_num; i++)
    	out << newBag.data[i] << ' ';
    return out;
}

