/**********************************************************************
Functions to work with the struct Move.
Includes formatted I/O functions and relational operators.

Angela Piper
March 2015
**********************************************************************/

#ifndef MOVEMENT_H_
#define MOVEMENT_H_

enum Direction {in = 7, out = 9};
struct Move
{
	Direction dir;
	char date[9];
	int hr;
	int min;
	int count;
};

int readfile(Move movement[], int max, const char filename[]);
bool writefile(const Move movement[], int size, const char filename[]);
bool operator<(const Move& a, const Move& b);
bool operator>(const Move& a, const Move& b);
bool operator<=(const Move& a, const Move& b);
bool operator>=(const Move& a, const Move& b);
bool operator==(const Move& a, const Move& b);
bool operator!=(const Move& a, const Move& b);

#endif
