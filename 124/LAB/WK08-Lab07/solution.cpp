#include <iostream>
using namespace std;

struct student
{
	char name[128];
	int age;
	int courseno;
};

int main()
{
	int n=5;
	student *stuptr = new student[n];
	delete [] stuptr;
	return 0;
}
