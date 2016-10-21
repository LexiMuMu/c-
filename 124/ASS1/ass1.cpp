/************************************************************
*      Filename: ass1.h                                     *
*      Login: lm890                                         *
*      lab No: week4 Assignment 1                           *
*      File Description: pet structure                      *
*      Date Last Modified: 25/3/2015                        *
************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#include "ass1.h"

const char FILENAME[9] = "pets.dat";

int pow(int b)
{
	int a = 1;
	for(int i = 0; i < b; i++)
		a *= 10;
	return a;	
}

void load(pet data[], int & recNum)
{
	ifstream infile;
	recNum = 0;
	infile.open(FILENAME);
	if(infile.good() && recNum < 50)
	{
		infile.getline(data[recNum].status, 10, '\n');
		//cout << data[recNum].status;
		while(!infile.eof())
		{
			infile.getline(data[recNum].type, 20, '\n');
			//cout << data[recNum].type << endl;
			infile.getline(data[recNum].gender, 10, '\n');
			//cout << data[recNum].gender << endl;
			infile.getline(data[recNum].breed, 20, '\n');
			//cout << data[recNum].breed << endl;
			infile >> data[recNum].year;
			infile >> data[recNum].month;
			infile.ignore();
			//cout << data[recNum].year << data[recNum].month << endl;
			infile.getline(data[recNum].colour, 15, '\n');
			//cout << data[recNum].colour << endl;
			infile.getline(data[recNum].chip, 20, '\n');
			//cout << data[recNum].chip << endl;
			infile.getline(data[recNum].location, 50, '\n');
			//cout << data[recNum].location << endl;
			infile >> data[recNum].phone;
			//cout << data[recNum].phone << endl;
			infile.ignore();
			//cout << endl;
			recNum++;
			infile.getline(data[recNum].status, 10, '\n');
			//cout << data[recNum].status << endl;
		}
	}
	else
		cout << "File is lost!!\n";
	infile.close();
}


int display(pet data[], int & count, int recNum)
{
	char next;
	bool condition = true;
	if(count != 0)
		count = 0;
	while(condition == true && count < recNum)
	{
		//if all the record is displayed
		if(count > recNum - 1)
		{
			cout << "Already print all the records."
				 << endl;
			return 0;
		}
		else
		{
			cout << setw(10) << left << "Status" 
				 << data[count].status << endl;
			cout << setw(10) << left << "Type" 
				 << data[count].type << endl;
			cout << setw(10) << left << "Gender" 
				 << data[count].gender << endl;
			cout << setw(10) << left <<  "Breed" 
				 << data[count].breed << endl;
			cout << setw(10) << left <<  "Age" 
				 << data[count].year << " yrs "
				 << data[count].month << " mths " 
				 << endl;
			cout << setw(10) << left << "Colour" 
				 << data[count].colour << endl;
			cout << setw(10) << left << "Microchip" 
				 << data[count].chip << endl;
			cout << setw(10) << left << "Location" 
				 << data[count].location << endl;
			cout << setw(10) << left << "Phone" 
				 << data[count].phone << endl;
			count++;
		}
		cout << "Display next record? (y/n)>";
		cin >> next;
		if(next != 'y')
		{
			condition = false;
			if(count > 1)
				count--;
		}
	}
	if(recNum == 0)
		cout << "No record has been load yet. Do load first.\n";
	else if(count >= recNum)
		cout << "All of the data has been displayed.\n";
}

int add(pet data[], int & recNum)
{
	pet addpet;
	char tmp;
	int digits = 1;
	cout << "Add Record to Directory" << endl
		 << "(Enter your pet's details)" << endl
		 << "(Press return if detail is unknown)\n" << endl;
	if(recNum >= SIZE)
	{
		cout << "The file is full, cannot add record.\n";
		return 0;
	}
	if(recNum == 0)
	{
		cout << "Please load file first.\n";
		return 0;
	}
	//status
	cout << setw(40) << left 
		 << "Is the pet lost of found? (l/f)" << " => ";
	tmp = getchar();
	if(tmp == 'f')
	{
		strcpy(addpet.status, "found");
		// cout << addpet.status;
		cin.ignore(50, '\n');
	}
	else if(tmp == 'l')
	{
		strcpy(addpet.status, "lost");
		cin.ignore(50, '\n');
	}
	else if(tmp == '\n')
	{
		strcpy(addpet.status, "unknown");
	}
	else
	{
		strcpy(addpet.status, "unknown");
		cin.ignore(50, '\n');
	}
	//type
	cout << setw(40) << left 
		 << "Is the pet a dog or cat? (d/c)" << " => ";
	tmp = getchar();
	if(tmp == 'd')
	{
		strcpy(addpet.type, "dog");
		cin.ignore(50, '\n');
	}
	else if(tmp == 'c')
	{
		strcpy(addpet.type, "cat");
		cin.ignore(50, '\n');
	}
	else if(tmp == '\n')
	{
		strcpy(addpet.type, "unknown");
	}
	else 
	{
		strcpy(addpet.type, "unknown");
		cin.ignore(50, '\n');
	}
	//gender
	cout << setw(40) << left 
		 << "What gender is the pet? (m/f)" << " => ";
	tmp = getchar();
	if(tmp == 'f')
	{
		strcpy(addpet.gender, "female");
		cin.ignore(50, '\n');
	}
	else if(tmp == 'm')
	{
		strcpy(addpet.gender, "male");
		cin.ignore(50, '\n');
	}
	else if(tmp == '\n')
	{
		strcpy(addpet.gender, "unknown");
	}
	else 
	{
		strcpy(addpet.gender, "unknown");
		cin.ignore(50, '\n');
	}
	//breed
	cout << setw(40) << left 
		 << "What breed is the pet?" << " => ";
	cin.getline(addpet.breed, 20, '\n');
	if(!strcmp(addpet.breed, ""))
		strcpy(addpet.breed, "unknown");
	//age
	char tmpAge;
	cout << setw(40) << left 
		 << "What age is the pet? (yy mm)" << " => ";
	tmpAge = getchar();
	// both year and month can be two digits
	if(tmpAge == '\n')
	{
		addpet.month = -1;
		addpet.year = -1;
	}
	else
	{
		addpet.year = tmpAge - '0';
		tmpAge = getchar();
		if(tmpAge == '\n')
			addpet.month = -1;
		else if(tmpAge == ' ')
		{
			tmpAge = getchar();
			addpet.month = tmpAge - '0';
			tmpAge = getchar();
			if(tmpAge != '\n')
			{
				addpet.month = addpet.month * 10 + 
							   (tmpAge - '0');
			}
		}
		else
		{
			addpet.year = addpet.year * 10 + 
						  (tmpAge - '0');
			tmpAge = getchar();
			if(tmpAge == '\n')
				addpet.month = -1;
			else if(tmpAge == ' ')
			{
				tmpAge = getchar();
				addpet.month = tmpAge - '0';
				tmpAge = getchar();
				if(tmpAge != '\n')
				{
					addpet.month = addpet.month * 10 + 
								   (tmpAge - '0');
					cin.ignore();
				}
			}
		}
		
	}

	//colour
	cout << setw(40) << left 
		 << "What colour is the pet?" << " => ";
	cin.getline(addpet.colour, 15, '\n');
	if(!strcmp(addpet.colour, ""))
		strcpy(addpet.colour, "unknown");
	//chip
	cout << setw(40) << left 
		 << "What is the Microchip number?" << " => ";
	cin.getline(addpet.chip, 16, '\n');
	if(!strcmp(addpet.chip, ""))
		strcpy(addpet.chip, "unknown");
	//location
	cout << setw(40) << left 
		 << "In what suburb was the pet lost?" << " => ";
	cin.getline(addpet.location, 50, '\n');
	if(!strcmp(addpet.location, ""))
		strcpy(addpet.location, "unknown");
	//phone
	cout << setw(40) << left 
		 << "What is your phone number?" << " => ";
	tmp = getchar();
	if(tmp != '\n')
	{
		cin >> addpet.phone;
		while(addpet.phone % pow(digits) != addpet.phone)
			digits++;
		addpet.phone = (tmp - '0') * pow(digits) + addpet.phone;
	}
		
	else
		addpet.phone = -1;

	ofstream ofile;
	ofile.open(FILENAME, ios::app);
	ofile << addpet.status << endl;
	ofile << addpet.type << endl;
	ofile << addpet.gender << endl;
	ofile << addpet.breed << endl;
	ofile << addpet.year << " " << addpet.month << endl;
	ofile << addpet.colour << endl;
	ofile << addpet.chip << endl;
	ofile << addpet.location << endl;
	ofile << addpet.phone << endl;
	ofile.close();

	//add to the struct array if the file has been load before. 
	if(recNum != 0)
	{
		recNum++;
		strcmp(data[recNum].status, addpet.status);
		strcmp(data[recNum].type, addpet.type);
		strcmp(data[recNum].gender, addpet.gender);
		strcmp(data[recNum].breed, addpet.breed);
		strcmp(data[recNum].colour, addpet.colour);
		strcmp(data[recNum].chip, addpet.chip);
		strcmp(data[recNum].location, addpet.location);
		data[recNum].month = addpet.month;
		data[recNum].year = addpet.year;
	}
}

void search(pet data[], int recNum, int & last)
{
	pet searchpet;
	char tmp, next;
	bool condition = true;
	int count = 0, found[SIZE], foundNum = 0;

	cout << setw(40) << left 
		 << "Search lost or found? (l/f)" << " => ";
	tmp = getchar();
	if(tmp == 'f')
	{
		strcpy(searchpet.status, "found");
		cin.ignore(50, '\n');
	}
	else if(tmp == 'l')
	{
		strcpy(searchpet.status, "lost");
		cin.ignore(50, '\n');
	}	
	else if(tmp == '\n')
	{
		strcpy(searchpet.status, "");
	}
	else 
	{
		strcpy(searchpet.status, "");
		cin.ignore(50, '\n');
	}
	//type
	cout << setw(40) << left 
		 << "Search for a dog or cat? (d/c)" << " => ";
	tmp = getchar();
	if(tmp == 'd')
	{
		strcpy(searchpet.type, "dog");
		cin.ignore(50, '\n');
	}
	else if(tmp == 'c')
	{
		strcpy(searchpet.type, "cat");
		cin.ignore(50, '\n');
	}	
	else if(tmp == '\n')
	{
		strcpy(searchpet.type, "");
	}
	else 
	{
		strcpy(searchpet.type, "");
		cin.ignore(50, '\n');
	}
	//gender
	cout << setw(40) << left 
		 << "What gender is the pet? (m/f)" << " => ";
	tmp = getchar();
	if(tmp == 'f')
	{
		strcpy(searchpet.gender, "female");
		cin.ignore(50, '\n');
	}
	else if(tmp == 'm')
	{
		strcpy(searchpet.gender, "male");
		cin.ignore(50, '\n');
	}	
	else if(tmp == '\n')
	{
		strcpy(searchpet.gender, "");
	}
	else 
	{
		strcpy(searchpet.gender, "");
		cin.ignore(50, '\n');
	}
	//breed
	cout << setw(40) << left 
		 << "What breed is the pet?" << " => ";
	cin.getline(searchpet.breed, 20, '\n');
	if(!strcmp(searchpet.breed, ""))
		strcpy(searchpet.breed, "");
	//age
	char tmpAge;
	cout << setw(40) << left 
		 << "What age is the pet? (yy mm)" << " => ";
	tmpAge = getchar();
	// both year and month can be two digits
	if(tmpAge == '\n')
	{
		searchpet.month = -1;
		searchpet.year = -1;
	}
	else
	{
		searchpet.year = tmpAge - '0';
		tmpAge = getchar();
		if(tmpAge == '\n')
			searchpet.month = -1;
		else if(tmpAge == ' ')
		{
			tmpAge = getchar();
			searchpet.month = tmpAge - '0';
			tmpAge = getchar();
			if(tmpAge != '\n')
			{
				searchpet.month = searchpet.month * 10 + 
							   (tmpAge - '0');
			}
		}
		else
		{
			searchpet.year = searchpet.year * 10 + 
						  (tmpAge - '0');
			tmpAge = getchar();
			if(tmpAge == '\n')
				searchpet.month = -1;
			else if(tmpAge == ' ')
			{
				tmpAge = getchar();
				searchpet.month = tmpAge - '0';
				tmpAge = getchar();
				if(tmpAge != '\n')
				{
					searchpet.month = searchpet.month * 10 + 
								   (tmpAge - '0');
					cin.ignore();
				}
			}
		}
		
	}
	//colour
	cout << setw(40) << left 
		 << "What colour is the pet?" << " => ";
	cin.getline(searchpet.colour, 15, '\n');
	//chip
	cout << setw(40) << left 
		 << "What is the Microchip number?" << " => ";
	cin.getline(searchpet.chip, 16, '\n');
	//chip
	cout << setw(40) << left 
		 << "In what suburb was the pet found/lost?" << " => ";
	cin.getline(searchpet.location, 50, '\n');

	// cout << setw(10) << left << "Status" 
	// 			 << searchpet.status << endl;
	// 		cout << setw(10) << left << "Type" 
	// 			 << searchpet.type << endl;
	// 		cout << setw(10) << left << "Gender" 
	// 			 << searchpet.gender << endl;
	// 		cout << setw(10) << left <<  "Breed" 
	// 			 << searchpet.breed << endl;
	// 		cout << setw(10) << left <<  "Age" 
	// 			 << searchpet.year << " yrs "
	// 			 << searchpet.month << " mths " 
	// 			 << endl;
	// 		cout << setw(10) << left << "Colour" 
	// 			 << searchpet.colour << endl;
	// 		cout << setw(10) << left << "Microchip" 
	// 			 << searchpet.chip << endl;
	// 		cout << setw(10) << left << "Location" 
	// 			 << searchpet.location << endl;

	//search
	for(int i = 0; i < recNum; i++)
	{
		if((!strcmp(data[i].status, searchpet.status) || 
			!strcmp(searchpet.status, "")) &&
			(!strcmp(data[i].type, searchpet.type) || 
			!strcmp(searchpet.type, "")) &&
			(!strcmp(data[i].gender, searchpet.gender) || 
			!strcmp(searchpet.gender, "")) &&
			(!strcmp(data[i].breed, searchpet.breed) || 
			!strcmp(searchpet.breed, "")) &&
			(!strcmp(data[i].colour, searchpet.colour) || 
			!strcmp(searchpet.colour, "")) &&
			(!strcmp(data[i].chip, searchpet.chip) || 
			!strcmp(searchpet.chip, "")) &&
			 (!strcmp(data[i].location, searchpet.location) || 
			!strcmp(searchpet.location, "")) &&
			 (searchpet.month == -1 || 
			 (data[i].month == searchpet.month)) && 
			 (searchpet.year == -1 ||
			 (data[i].year == searchpet.year))
			)
		{
			{
				found[foundNum] = i;
				foundNum++;
			}
		}

	}
	//print
	if(foundNum == 0)
	{
		condition = false;
		cout << "No match." << endl;
	}
	else
	{
		cout << "There are " << foundNum 
			 << " records that match the criteria."
			 << endl; 
	}

	while(condition == true)
	{
		//if all the record is displayed
		if(count > foundNum - 1)
		{
			cout << "Already print all the records."
				 << endl;
			condition = false;
		}
		else
		{
			cout << setw(10) << left << "Status" 
				 << data[found[count]].status << endl;
			cout << setw(10) << left << "Type" 
				 << data[found[count]].type << endl;
			cout << setw(10) << left << "Gender" 
				 << data[found[count]].gender << endl;
			cout << setw(10) << left <<  "Breed" 
				 << data[found[count]].breed << endl;
			cout << setw(10) << left <<  "Age" 
				 << data[found[count]].year << " yrs "
				 << data[found[count]].month << " mths " 
				 << endl;
			cout << setw(10) << left << "Colour" 
				 << data[found[count]].colour << endl;
			cout << setw(10) << left << "Microchip" 
				 << data[found[count]].chip << endl;
			cout << setw(10) << left << "Location" 
				 << data[found[count]].location << endl;
			cout << setw(10) << left << "Phone" 
				 << data[found[count]].phone << endl;
			count++;
		}
		cout << "Display next record? (y/n)>";
		cin >> next;
		if(next != 'y')
		{
			condition = false;
			last = found[count - 1];
		}
	}
}

void remove(pet data[], int & recNum, int & count, pet & tmp)
{
	if(count == 0)
	{
		cout << "No recently viewed record, "
			 << "please search for a record first.\n";
	}
	else
	{
		cout << setw(10) << left << "Status" 
			 << data[count].status << endl;
		cout << setw(10) << left << "Type" 
			 << data[count].type << endl;
		cout << setw(10) << left << "Gender" 
			 << data[count].gender << endl;
		cout << setw(10) << left <<  "Breed" 
			 << data[count].breed << endl;
		cout << setw(10) << left <<  "Age" 
			 << data[count].year << " yrs "
			 << data[count].month << " mths " 
			 << endl;
		cout << setw(10) << left << "Colour" 
			 << data[count].colour << endl;
		cout << setw(10) << left << "Microchip" 
			 << data[count].chip << endl;
		cout << setw(10) << left << "Location" 
			 << data[count].location << endl;
		cout << setw(10) << left << "Phone" 
			 << data[count].phone << endl;

		strcpy(tmp.status, data[count].status);
		strcpy(tmp.type, data[count].type);
		strcpy(tmp.gender, data[count].gender);
		strcpy(tmp.breed, data[count].breed);
		strcpy(tmp.colour, data[count].colour);
		strcpy(tmp.chip, data[count].chip);
		strcpy(tmp.location, data[count].location);
		tmp.month = data[count].month;
		tmp.year = data[count].year;
		tmp.phone = data[count].phone;

		ofstream ofile;
		ofile.open(FILENAME);
		for(int i = 0; i < recNum; i++)
		{	
			if(i != count)
			{
				ofile << data[i].status << endl;
				ofile << data[i].type << endl;
				ofile << data[i].gender << endl;
				ofile << data[i].breed << endl;
				ofile << data[i].year << " " << data[i].month << endl;
				ofile << data[i].colour << endl;
				ofile << data[i].chip << endl;
				ofile << data[i].location << endl;
				ofile << data[i].phone << endl;
			}
		}
		ofile.close();

		cout << "The record has been removed from the directory."
			 << endl 
			 << "There are " << --recNum 
			 << " records in the directory." << endl;

		count = 0;
	}
}

void undo(pet data[], int & recNum, pet & tmp)
{

	if(tmp.month == -2)
	{
		cout << "No recently deleted record.\n";
	}
	else if(recNum == SIZE)
	{
		cout << "The file is full.\n";
	}
	else
	{
		cout << setw(10) << left << "Status" 
			 << tmp.status << endl;
		cout << setw(10) << left << "Type" 
			 << tmp.type << endl;
		cout << setw(10) << left << "Gender" 
			 << tmp.gender << endl;
		cout << setw(10) << left <<  "Breed" 
			 << tmp.breed << endl;
		cout << setw(10) << left <<  "Age" 
			 << tmp.year << " yrs "
			 << tmp.month << " mths " 
			 << endl;
		cout << setw(10) << left << "Colour" 
			 << tmp.colour << endl;
		cout << setw(10) << left << "Microchip" 
			 << tmp.chip << endl;
		cout << setw(10) << left << "Location" 
			 << tmp.location << endl;
		cout << setw(10) << left << "Phone" 
			 << tmp.phone << endl;

		ofstream ofile;
		ofile.open(FILENAME, ios::app);
		ofile << tmp.status << endl;
		ofile << tmp.type << endl;
		ofile << tmp.gender << endl;
		ofile << tmp.breed << endl;
		ofile << tmp.year << " " << tmp.month << endl;
		ofile << tmp.colour << endl;
		ofile << tmp.chip << endl;
		ofile << tmp.location << endl;
		ofile << tmp.phone << endl;
		ofile.close();

		cout << "The record has been reinserted to the directory."
			 << endl 
			 << "There are " << ++recNum
			 << " records in the directory." << endl;

		tmp.month = -2;
	}
}

