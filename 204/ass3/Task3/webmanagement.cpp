/********************************************************************************
 * Filename: webmanagement.cpp
 * Name & Student No.: Yanhong Ben, 4845675
 * ASS No: 3
 * File Description: implementation file of task 3 STL container
 *********************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

#include "webmanagement.h"

void WebManagement::loadWebsite(char* filename)
{
    ifstream fin;
	fin.open(filename);
	int counter = 0; //count recorder number
	string webName, webAddress;
	getline(fin, webName, ':');
	getline(fin, webAddress);
	while(fin.good())
	{
		Website tempWeb(webName, webAddress);
		listWebsite[webName] = tempWeb; //save to map container
		counter++;
		getline(fin, webName, ':');
		getline(fin, webAddress);
	}
	fin.close();
	cout << counter << " records loaded." << endl;
	cout << endl;
}

void WebManagement::run()
{
	int choice;
	bool isQuit = false;
	do
	{
		cout << "1. Add a new website" << endl;
		cout << "2. Find a website" << endl;
		cout << "3. Update a website" << endl;
		cout << "4. Remove a website" << endl;
		cout << "5. Display all websites" << endl;
		cout << "6. Save all websites" << endl;
		cout << "0. Quit" << endl;
		cout << "Choice: ";
		cin >> choice;
		cin.ignore();
		cout << endl;
		switch(choice)
		{
			case 1:
				addWebsite();
				break;
			case 2:
				findWebsite();
				break;
			case 3:
				updateWebsite();
				break;
			case 4:
				removeWebsite();
				break;
			case 5:
				displayAll();
				break;
			case 6:
				saveWebiste();
				break;
			case 0:
				cout << "Bye" << endl;
				cout << endl;
				isQuit = true;
				break;
			default:
				cout << "Wrong choice, please re-enter." << endl;
				break;
		}
	} while (!isQuit);
}

void WebManagement::addWebsite()
{
	string newName;
	cout << "Name: ";
	getline(cin, newName);
	if (listWebsite.find(newName) != listWebsite.end()) //search the container
		cout << "The website for " << newName << " already exits." << endl;
	else
	{
		string neWebAddress;
		cout << "Website: ";
		getline(cin, neWebAddress);
		cin.clear();
		Website tempWeb(newName, neWebAddress);
		listWebsite[newName] = tempWeb;
		cout << "The website has been added." << endl;
	}
	cin.clear();
	cout << endl;
}

void WebManagement::findWebsite()
{
	string newName;
	cout << "Name: ";
	getline(cin, newName);
	if (listWebsite.find(newName) == listWebsite.end()) //search the container
		cout << "The website does not exist. " << endl;
	else
		cout << listWebsite[newName] << endl;
	cin.clear();
	cout << endl;
}

void WebManagement::updateWebsite()
{
	string newName;
	cout << "Name: ";
	getline(cin, newName);
	if (listWebsite.find(newName) == listWebsite.end()) //search the container
		cout << "The website does not exist." << endl;
	else
	{
		string neWebAddress;
		cout << "Website: ";
		getline(cin, neWebAddress);
		cin.clear();
		Website tempWeb(newName, neWebAddress);
		listWebsite[newName] = tempWeb;
		cout << "The website has been updated." << endl;
	}
	cin.clear();
	cout << endl;
}

void WebManagement::removeWebsite()
{
	string newName;
	cout << "Name: ";
	getline(cin, newName);
	if (listWebsite.find(newName) == listWebsite.end()) //search the container
		cout << "The website does not exist." << endl;
	else
	{
		listWebsite.erase(newName);
		cout << "The website has been removed." << endl;
	}
	cin.clear();
	cout << endl;
}

void WebManagement::displayAll()
{
	map<string, Website>::iterator p = listWebsite.begin();
	while(p != listWebsite.end())
	{
		cout << p->second << endl;
		p++;
	}
	cout << endl;
}

void WebManagement::saveWebiste()
{
	char filename[20];
	cout << "Filename: ";
	cin.getline(filename, 20, '\n');
	cin.clear();
	ofstream fout;
	fout.open(filename, ios::trunc); //overwrite if the same file as last time
	map<string, Website>::iterator p = listWebsite.begin();
	while(p != listWebsite.end())
	{
		fout << p->second << endl;
		p++;
	}
	fout.close();
	cout << listWebsite.size() << " records have been saved." << endl; //get the size of the current container
	cout << endl;
}

