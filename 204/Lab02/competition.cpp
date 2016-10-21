/********************************************************************************
* Filename: competition.cpp                                        			   		
* Name & Student No.: Yanhong Ben, 4845675															
* Lab No: 2																		
* File Description: implementation file of basetball competitions										
* Date Last Modified: 14/08/2015                                				
*********************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

#include "competition.h"

Team::Team()
{
	name = "Uninitialized";
	totalWin = 0;
	totalLoss = 0;
	totalFor = 0;
	totalAgainst = 0;
}

void Team::setName(string newName)
{
	name = newName;
}

void Team::setScore(int scoreA, int scoreB)
{
	totalFor += scoreA;
	totalAgainst += scoreB;
	if (scoreA > scoreB)
		totalWin += 1;
	else
		totalLoss += 1;
}

string Team::getName()
{
	return name;
}

int Team::getWin()
{
	return totalWin;
}

int Team::getLoss()
{
	return totalLoss;
}

int Team::getFor()
{
	return totalFor;
}

int Team::getAgainst()
{
	return totalAgainst;
}

void Team::print()
{
	cout << name << endl;
	cout << "Win: " << totalWin << endl;
	cout << "Loss: " << totalLoss << endl;
	cout << "For: " << totalFor << endl;
	cout << "Against: " << totalAgainst << endl;
}

Result::Result()
{
	count = 0;
}

void Result::loadRecord(string filename)
{
	ifstream fin;
	fin.open(filename.c_str(), ios::in);
	if (!fin.good())
	{
		cout << "Could not open the file. Please check if you had input correct." << endl;
		return;
	}//open the file

	string tmpTeam[2];
	int tmpScore[2], tmpIndex;
	bool flag;

	while(!fin.eof())
	{
		getline(fin, tmpTeam[0], ':');
		if (fin.good())
		{
			getline(fin, tmpTeam[1], '\n');
			fin >> tmpScore[0];
			fin.ignore();
			fin >> tmpScore[1];
			fin.ignore();

			for (int i = 0; i < 2; i++)
			{
				flag = false;
				for (int j = 0; j < count; j++)
				{
					if (team[j].getName().compare(tmpTeam[i]) == 0)//if find same name update data to the team
					{
						if (i == 0)
							team[j].setScore(tmpScore[0], tmpScore[1]);
						else
							team[j].setScore(tmpScore[1], tmpScore[0]);
						flag = true;
					}
				}
				if (flag == false)//not find same team name, build a new one
				{
					if (i == 0)
					{
						team[count].setName(tmpTeam[0]);
						team[count].setScore(tmpScore[0], tmpScore[1]);
					}
					else
					{
						team[count].setName(tmpTeam[1]);
						team[count].setScore(tmpScore[1], tmpScore[0]);
					}
					count++;
				}
			}			
		}
	}
	fin.close();
}

void Result::sortRecord()
{
	Team tmpTeam;
	for (int i = count - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (team[j].getWin() < team[j+1].getWin())
			{
				tmpTeam = team[j];
				team[j] = team[j+1];
				team[j+1] = tmpTeam;
			}
		}
	}

	for (int i = count - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (team[j].getLoss() > team[j+1].getLoss())
			{
				tmpTeam = team[j];
				team[j] = team[j+1];
				team[j+1] = tmpTeam;
			}
		}
	}

	for (int i = count - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (team[j].getWin() == team[j+1].getWin() && 
				team[j].getLoss() == team[j+1].getLoss() &&
				(team[j].getFor()-team[j].getAgainst()) < (team[j].getFor()-team[j+1].getAgainst()))
			{
				tmpTeam = team[j];
				team[j] = team[j+1];
				team[j+1] = tmpTeam;
			}
		}
	}

}

void Result::printRecord()
{
	for (int i = 0; i < count; i++)
	{
		cout << setw(20) << left << team[i].getName() 
			 << setw(10) << team[i].getWin()
			 << setw(10) << team[i].getLoss()
			 << setw(10) << team[i].getFor()
			 << setw(5) << team[i].getAgainst()
			 << endl;
	}
}


