/********************************************************************************
* Filename: polynomial.h                                         			   		
* Name & Student No.: Yanhong Ben, 4845675															
* ASS No: 2																		
* File Description: head file of task 1 polynomial handling										
* Date Last Modified: 27/09/2015                                				
*********************************************************************************/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial
{
	private:
		int length;
		double *coeff;
	public:
		Polynomial();
		~Polynomial();
		Polynomial(double*, int);
		Polynomial(const Polynomial &);
		void operator=(const Polynomial &);
		Polynomial operator+(const Polynomial &);
		Polynomial operator-(const Polynomial &);
		Polynomial operator*(const Polynomial &);
		Polynomial operator/(const Polynomial &);
		Polynomial operator%(const Polynomial &);
		friend std::istream& operator>>(std::istream &, Polynomial &);
		friend std::ostream& operator<<(std::ostream &, Polynomial &);
};

std::istream& operator>>(std::istream &, Polynomial &);
std::ostream& operator<<(std::ostream &, Polynomial &);

#endif


