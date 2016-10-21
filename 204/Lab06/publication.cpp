/********************************************************************************
* Filename: publication.cpp                                         			   		
* Name & Student No.: Yanhong Ben, 4845675															
* Lab No: 6															
* File Description: implementation file of publication										
* Date Last Modified: 06/09/2015                                				
*********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

#include "publication.h"

Publication::Publication(string tit, int pYear, string publ)
{
	title = tit;
	publishYear = pYear;
	publisher = publ;
}

void Publication::print(ostream& out)
{
	out << "Title: " << title << endl;
	out << "Published in " << publishYear << endl;
	out << "Publisher: " << publisher << endl;
}

Book::Book(string tit, int pYear, string publ, string newISBN, string auth[3])
: Publication(tit, pYear, publ)
{
	NoOfISBN = newISBN;
	for (int i = 0; i < 3; i++)
		authors[i] = auth[i];
}

void Book::print(ostream& out)
{
	Publication::print(out);
	out << "ISBN: " << NoOfISBN << endl;
	out << "Authors: ";
	for (int i=0; i<3; i++)
		out << authors[i] << " ";
	out << endl;
}

Journal::Journal(string tit, int pYear, string publ, string newISSN, string chieE, int vol)
: Publication(tit, pYear, publ)
{
	NoOfISSN = newISSN;
	chiefEditor = chieE;
	volume = vol;
}

void Journal::print(ostream& out)
{
	Publication::print(out);
	out << "ISSN: " << NoOfISSN << endl;
	out << "Editor in Chief: " << chiefEditor << endl;
	out << "Volume: " << volume << endl; 
}

