#include <iostream>
#include <cmath>
using namespace std;

const int SIZE = 6;

int main()
{
	int distance =1;

	while ((pow(2,distance) - 1) < SIZE && (pow(2,distance+1) - 1) < SIZE)
	{
		distance++;
	}
	cout << distance << " " << pow(2,distance) -1 << endl;

	return 0;
}