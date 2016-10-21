/********************************************************************************
* Filename: BigInteger.h                                         			   		
* Name & Student No.: Yanhong Ben, 4845675															
* Lab No: 5																
* File Description: header file of Big Integer										
* Date Last Modified: 04/09/2015                                				
*********************************************************************************/

#ifndef BIGINTEGER_H
#define BIGINTEGER_H

class BigInteger
{
	private:
		unsigned short *ptr;
		int size;
	public:
		BigInteger();
		~BigInteger();
		BigInteger(const char []);
		BigInteger(const BigInteger&);
		friend ostream& operator<<(ostream &,const BigInteger &);
		friend istream& operator>>(istream&, BigInteger &);
		BigInteger operator=(const BigInteger &);
		BigInteger operator+(const BigInteger &);
		BigInteger operator*(const BigInteger &);
		bool operator==(const BigInteger&);
};

ostream& operator<<(ostream& out, const BigInteger &);
istream& operator>>(istream &in, BigInteger &);

#endif
