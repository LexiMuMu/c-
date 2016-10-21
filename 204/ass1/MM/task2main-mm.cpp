/*******************************************************
*      Filename: task2main.cpp                         *
*      Login: lm890                                    *
*      lab No: assignment 1                            *
*      File Description: use the shape classes         *
*      Date Last Modified: August 27th,2015            *
********************************************************/

#include <iostream>
#include <math.h>
#include "shapes.h"
using namespace std;

int main()
{
	cout << "Create a point p1(10, 20)\n";
	Point p1(10,20);

	cout << "Copy a point p2(10, 20)\n";
	Point p2(p1);
	// Point p2 = p1;
	
	cout << "Set new coordinates for p2(100, 200)\n";
	p2.set(100, 200);
	
	cout << "Create a line (10, 20) - (100, 200)\n";
	Line p(p1, p2);
	
	cout << "Change point of the line (30, 40) - (100, 200)\n";
	Point tmp(30, 40);
	p.set(tmp, p2);
	
	cout << "Create a circle (80, 10), radius=50\n";
	Point centre(80, 10);
	Circle c1(centre, 50);
	
	cout << "Copy a circle (80, 10), radius=50\n";
	Circle c2(c1);
	
	//check if circle c2 is intersect wieh line p
	c2.intersect(p);
}

