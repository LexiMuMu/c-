/*******************************************************
*      Filename: BigInteger.h                          *
*      Login: lm890                                    *
*      lab No: week 4 lab 3                            *
*      File Description: BigInteger class design       *
*      Date Last Modified: August 20th,2015            *
********************************************************/

class BigInteger
{
private:
	short int * num;
	int size;
public:
	BigInteger();
	BigInteger(char []);
	BigInteger(long long int big);
	BigInteger(const BigInteger&);
	~BigInteger();
	BigInteger add(const BigInteger&);
	void print(std::ostream&);
};
