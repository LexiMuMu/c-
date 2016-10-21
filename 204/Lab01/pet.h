/********************************************************************************
* Filename: pet.h                                        			   		
* Name & Student No.: Yanhong Ben, 4845675															
* Lab No: 1																		
* File Description: pet lost and found  										
* Date Last Modified: 06/08/2015                                				
*********************************************************************************/

#ifndef PET_H
#define PET_H

struct Pet
{
	char status[10];
	char type[10];
	char gender[10];
	char breed[50];
	int ageYear;
	int ageMonth;
	char color[20];
	char chip[20];
	char location[20];
	int phone;
};

int countRecords(char*);
void loadRecords(char*, Pet*, int);
void printRecords(Pet*, int);

#endif