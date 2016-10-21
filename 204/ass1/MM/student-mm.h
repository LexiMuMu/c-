/*******************************************************
*      Filename: student.h                             *
*      Login: lm890                                    *
*      lab No: assignment 1                            *
*      File Description: student class                 *
*      Date Last Modified: August 27th,2015            *
********************************************************/

class Student
{
private:
	char* name;
	int mark[4];//up to 4?
	int num;

public:
	Student();
	~Student();
	char* getName();
	int getMark(int);
	void setMark(int*);
	void setName(char*);
	void print();
};

