/************************************************************
*      Filename: polynomial.h                               *
*      Login: lm890                                         *
*      lab No: Assignment 4                                 *
*      File Description:  define class polynomial *
*      Date Last Modified: 20/5/2015                        *
************************************************************/

class poly
{
private:
	int degree;
	double* coefficient;

public:
	poly();
	poly(double [], int);
	poly(const poly&);
	~poly();
	void input();
	void print();
	void operator =(const poly&);
	poly add(const poly&);
	poly sub(const poly&);
};

