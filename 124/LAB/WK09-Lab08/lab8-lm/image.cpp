#include <iostream>
#include <fstream>
#include <cstring>
#include "image.h"
using namespace std;

image::image()
{
	pixmap = NULL;
}

image::~image()
{
	delete [] pixmap;
	pixmap = 0;
}

void image::readImage(const char fname[])
{
	ifstream in;
	char tmp[100];
	int MAX;
	in.open(fname, ios::binary);
	if(!in.good())
	{
		cout << "Can't open the file!\n";
		return;
	}
	in >> tmp;
	if(strcmp(tmp, "P6"))
	{
		in.close();
		cout << "Wrong file!\n";
		return;
	}
	in.ignore();
	while(in.peek() == '#')
	{
		in.ignore(100, '\n');
	}
	in >> xdim;
	in >> ydim;
	pixmap = new (nothrow) pixel[xdim * ydim];
	if(pixmap == NULL)
	{
		cout << "No memory allocated!\n";
		return;
	}
	in >> MAX;
	in.ignore();
	in.read(reinterpret_cast<char*>(pixmap), sizeof(pixel)*xdim*ydim);
	in.close();
}

void image::writeImage(const char fname[])
{
	ofstream out;
	out.open(fname,ios::binary);
	out << "P6\n" << xdim << " " << ydim << "\n255\n";
	out.write(reinterpret_cast<char*>(pixmap),  sizeof(pixel)*xdim*ydim);
	out.close();
}

void image::scaleImage(int factor)
{
	pixel* pixtmp = new pixel[xdim * factor * ydim * factor];
	if(factor >= 1 && factor <= 10)
	{
		for(int i = 0; i < ydim; i++)
			for(int j = 0; j < xdim; j++)
				for(int y = 0; y < factor; y++)
					for(int x = 0; x < factor; x++)
					{	
						pixtmp[xdim * factor * (i * factor + x) + j * factor + y] = pixmap[i * xdim + j];
					// 	 cout << i << ' ' << j << endl;
					// 	 cout << factor * i + x << ' ' << j * factor + y << endl;
					}
	}
	delete [] pixmap;
	xdim = xdim * factor;
	ydim = ydim * factor;
	pixmap = pixtmp;	
}



