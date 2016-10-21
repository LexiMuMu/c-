/*******************************************************
*      Filename: shapes.h                              *
*      Login: lm890                                    *
*      lab No: assignment 1                            *
*      File Description: point/line/circle functions   *
*      Date Last Modified: August 27th,2015            *
********************************************************/

#include <iostream>
#include <math.h>
#include "shapes.h"
using namespace std;

Point::Point(int a = 0, int b = 0)
{
	x = a;
	y = b;
}

Point::Point(const Point & copy)
{
	x = copy.x;
	y = copy.y;
}

void Point::set(int newx, int newy)
{
	x = newx;
	y = newy;
}

int Point::getx() const
{
	return x;
}

int Point::gety() const
{
	return y;
}

Line::Line(Point x, Point y)
{
	a.set(x.getx(), x.gety());
	b.set(y.getx(), y.gety());
}

//const
Line::Line(const Line & copy)
{
	a.set(copy.a.getx(), copy.a.gety());
	b.set(copy.b.getx(), copy.b.gety());
}

void Line::set(Point newa, Point newb)
{
	a.set(newa.getx(), newa.gety());
	b.set(newb.getx(), newb.gety());
}

Point Line::geta()
{
	return a;
}

Point Line::getb()
{
	return b;
}

Circle::Circle(Point x, double r)
{
	centre.set(x.getx(), x.gety());
	radius = r;
}

Circle::Circle(const Circle & copy)
{
	centre.set(copy.centre.getx(), copy.centre.gety());
	radius = copy.radius;
}

void Circle::set(Point c, double r)
{
	centre.set(c.getx(), c.gety());
	radius = r;
}

Point Circle::getc()
{
	return centre;
}

double Circle::getr()
{
	return radius;
}

double Circle::intersect(Line line)
{
	Point a = line.geta();
	Point b = line.getb();
	int ax = a.getx();
	int ay = a.gety();
	int bx = b.getx();
	int by = b.gety();
	int cx = centre.getx();
	int cy = centre.gety();

	//calculate the 
	int distance = 
	((bx - ax) * (ay - cy) - (ax - cx) * (by - ay)) / 
	sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
	
	cout << "A line (" << ax << ", " << ay << ")-(" 
		 <<  bx << ", " << by
		 << ") and a circle(" << cx << ", " << cy 
		 << ") of radius 50 ";

	// intersect when distance is less than radius
	if(distance > radius)
		cout << "are not intersected. ";
	else
		cout << "are intersected. ";

	cout << "distance=" << distance << endl;
}

