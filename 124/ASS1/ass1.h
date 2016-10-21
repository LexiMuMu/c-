/************************************************************
*      Filename: ass1.h                                     *
*      Login: lm890                                         *
*      lab No: week4 Assignment 1                           *
*      File Description: pet structure                      *
*      Date Last Modified: 25/3/2015                        *
************************************************************/

#include <iostream>
using namespace std;

const int SIZE = 50;

struct pet
{
	char status[10];	//lost or found
	char type[20];	//cat hippopotamus
	char gender[10];	//male or female
	char breed[20];
	int year;
	int month;
	char colour[15];
	char chip[16];	//15 number
	char location[50];
	int phone;
};

int pow(int);
void load(pet [], int &);
int display(pet [], int &, int);
int add(pet [], int &);
void search(pet [], int, int &);
void remove(pet [], int &, int &, pet &);
void undo(pet [], int &, pet &);
