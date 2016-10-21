/********************************************************************************
 * Filename: stock.cpp
 * Name & Student No.: Yanhong Ben, 4845675
 * Lab No: 8
 * File Description: implementation file of stock
 * Date Last Modified: 24/09/2015
 *********************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>

#include "stock.h"


Stock::Stock()
{
	strcpy(tag, "");
	cost = 0;
	vol = 0;
}

void Stock::setTag(char* newTag)
{
	strcpy(tag, newTag);
}


void Stock::setCost(int newCost)
{
	cost = newCost;
}


void Stock::setVol(int newVol)
{
	vol = newVol;
}


char* Stock::getTag()
{
	return tag;
}


int Stock::getCost()
{
	return cost;
}


int Stock::getVol()
{
	return vol;
}

//overloading greater operator to used to compare two objects
bool Stock::operator>(Stock &newStock)const
{
	return (strcmp(tag, newStock.tag) > 0);
}

//overloading less operator to used to compare two objects
bool Stock::operator<(Stock &newStock)const
{
	return (strcmp(tag, newStock.tag) < 0);
}

//overloading insertion operator to print out a single stcok information
std::ostream& operator<<(std::ostream &out, const Stock & newStock)
{
	out << std::setw(5) << std::left << newStock.tag
		<< std::setw(6) << newStock.cost
		<< std::setw(9) << newStock.vol << std::endl;
	return out;
}



