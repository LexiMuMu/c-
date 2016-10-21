/**********************************************************************
Functions to work with the struct Move.
Includes formatted I/O functions and relational operators.

Angela Piper
March 2015
**********************************************************************/

#include "movement.h"
#include <fstream>
#include <iomanip>
using namespace std;


//read moves from the file specified by filename into the array movement
//returns the number of records successfuly read or 0 if there was an error
int readfile(Move movement[], int max, const char filename[])
{
	int d, i=0;
	ifstream fin(filename);
	
	if(!fin.good())
	{
		return 0;
	}

	fin >> d;
	while(i<max && fin.good())
	{
		movement[i].dir = Direction(d);
		fin.ignore(1); //ignore the ','
		fin.getline(movement[i].date, 9, ',');
		fin >> movement[i].hr; 
		fin.ignore(1); //ignore the ':'
		fin >> movement[i].min;
		fin.ignore(4); //ignore the ':00,'
		fin >> movement[i].count;
		i++;

		fin >> d;
	}
	fin.close();
	if(fin.eof())
		return i;	//we reached the eof after i entries
	else
		return 0;	//we overran the array or the read failed
}

//write size moves from the array movement to file specified by filename
//returns true if the write succeeded, false if it failed
bool writefile(const Move movement[], int size, const char filename[])
{
	ofstream fout(filename);

	if(!fout.good())
	{
		return false;
	}

	for(int i=0; i<size; i++)
	{
		fout << movement[i].dir << ','
			<< movement[i].date << ','
			<< setfill('0') << setw(2) << movement[i].hr << ':' 
			<< setw(2) << movement[i].min << ":00,"
			<< movement[i].count << endl;
	}
	fout.close();
	return fout.good();
}

//returns true if a < b, false otherwise
bool operator<(const Move& a, const Move& b)
{
	return (a.count < b.count);	
}

//returns true if a > b, false otherwise
bool operator>(const Move& a, const Move& b)
{
	return (a.count > b.count);	
}

//returns true if a <= b, false otherwise
bool operator<=(const Move& a, const Move& b)
{
	return (a.count <= b.count);	
}

//returns true if a >= b, false otherwise
bool operator>=(const Move& a, const Move& b)
{
	return (a.count >= b.count);	
}

//returns true if a == b, false otherwise
bool operator==(const Move& a, const Move& b)
{
	return (a.count == b.count);	
}

//returns true if a != b, false otherwise
bool operator!=(const Move& a, const Move& b)
{
	return (a.count != b.count);	
}
