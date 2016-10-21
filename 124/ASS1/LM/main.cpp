#include <iostream>
#include <fstream>

using namespace std;

#include "ass1.h"

char Menu();

int main()
{
	pet petdata[SIZE];
	int recNum = 0, count = 0;
	pet tmp;
	tmp.month = -2;

	while(true)
	{
		switch(Menu())
		{
			//load
			case 'l': 
				load(petdata, recNum);
				cout << "There are " << recNum
					 << " records in the directory."
					 << endl;
				// for(int i = 0; i < recNum; i++)
				// {
				//	cout << petdata[i].status << endl;
				//	cout << petdata[i].type << endl;
				// 	cout << petdata[i].gender << endl;
				// 	cout << petdata[i].breed << endl;
				// 	cout << petdata[i].year << endl;
				// 	cout << petdata[i].month << endl;
				// 	cout << petdata[i].colour << endl;
				// 	cout << petdata[i].chip << endl;
				// 	cout << petdata[i].location << endl;
				// 	cout << petdata[i].phone << endl;
				// }
				break;

			//display
			case 'd':
				display(petdata, count, recNum);
				break;
				
			//add
			case 'a':
				if(recNum >= SIZE)
					cout << "The directory is already full.\n";
				else
				{
					add(petdata, recNum);
					cout << "The new record has been added to the directory."
						 << endl;
					cout << "There are " << recNum
						 << " records in the directory."
						 << endl;
				}
				break;

			//search
			case 's':
				search(petdata, recNum, count);
				break;

			//remove
			case 'r':
				remove(petdata, recNum, count, tmp);
				break;

			//undo
			case 'u':
				undo(petdata, recNum, tmp);
				break;

			//quit
			case 'q':
				cout << "Thank you for using the Lost and Found Pet Directory\n";
				return 1;

			default:
				cout << "Invalid command!\n";
		}
	}
	return 0;
}

char Menu()
{
	char cmd;
	cout << "*********************************"<< endl;
	cout << "*  Lost and Found Pet Directory *"<< endl;
	cout << "*     (l)oad data file          *"<< endl;
	cout << "*     (d)isplay records         *"<< endl;
	cout << "*     (a)dd record to DB        *"<< endl;
	cout << "*     (s)earch records          *"<< endl;
	cout << "*     (r)emove records          *"<< endl;
	cout << "*     (u)ndo remove records     *"<< endl;
	cout << "*     (q)uit                    *"<< endl;
	cout << "*********************************"<< endl;
	cout << "Command: ";
	cin >> cmd;
	cin.ignore();
	return cmd;
}
