/********************************************************************************
* Filename: competition.h                                         			   		
* Name & Student No.: Yanhong Ben, 4845675															
* Lab No: 2																		
* File Description: header file of basetball competitions										
* Date Last Modified: 14/08/2015                                				
*********************************************************************************/

#ifndef COMPETITION_H
#define COMPETITION_H

const int MAX = 10;

class Team
{
	private:
		string name;
		int totalWin;
		int totalLoss;
		int totalFor;
		int totalAgainst;
	public:
		Team();
		void setName(string);
		void setScore(int, int);
		string getName();
		int getWin();
		int getLoss();
		int getFor();
		int getAgainst();
		void print();
};

class Result
{
	private:
		Team team[MAX];
		int count;
	public:
		Result();
		void loadRecord(string);
		void sortRecord();
		void printRecord();
};

#endif
