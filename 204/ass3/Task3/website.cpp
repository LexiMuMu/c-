/********************************************************************************
 * Filename: website.cpp
 * Name & Student No.: Yanhong Ben, 4845675
 * ASS No: 3
 * File Description: implementation file of task 3 STL container
 *********************************************************************************/

#include <iostream>
using namespace std;

#include "website.h"

Website::Website()
{
	name = "";
	webAddress = "";
}

Website::Website(const string newName, const string neWebAddress)
{
	name = newName;
	webAddress = neWebAddress;
}

void Website::setName(string newName)
{
	name = newName;
}

void Website::setWebsite(string newName)
{
	newName = name;
}

string Website::getName()
{
	return name;
}

string Website::getWebsite()
{
	return webAddress;
}

ostream& operator<<(ostream &out, const Website &web)
{
	out << web.name << " " << web.webAddress;
	return out;
}

