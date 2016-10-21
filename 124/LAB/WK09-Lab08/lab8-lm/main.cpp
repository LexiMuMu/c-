

#include <iostream>
#include "image.h"
using namespace std;

int main()
{
	char filename[20], fnametmp[20];
	image img;
	int scale;
	cout << "Enter original Filename:" << endl;
	cin >> filename;
	cout << "Enter a Filename to write in:" << endl;
	cin >> fnametmp;
	cout << "Enter scale:" << endl;
	cin >> scale;
	img.readImage(filename);
	img.scaleImage(scale);
	img.writeImage(fnametmp);
	cout << "Succeed!" << endl;
}
