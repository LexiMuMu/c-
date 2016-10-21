/*******************************************************
*      Filename: shapes.h                              *
*      Login: lm890                                    *
*      lab No: assignment 1                            *
*      File Description: class point/line/circle       *
*      Date Last Modified: August 27th,2015            *
********************************************************/

class Point
{
private:
	int x;
	int y;

public:
	Point(int, int);
	Point(const Point &);
	void set(int, int);
	int getx() const;
	int gety() const;
};

class Line
{
private:
	Point a;
	Point b;

public:
	Line(Point, Point);
	Line(const Line &);
	void set(Point, Point);
	Point geta();
	Point getb();
};

class Circle
{
private:
	Point centre;
	double radius;

public:
	Circle(Point, double);
	Circle(const Circle &);
	void set(Point, double);
	Point getc();
	double getr();
	double intersect(const Line);
};
