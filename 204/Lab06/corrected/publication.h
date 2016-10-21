/********************************************************************************
* Filename: publication.h                                         			   		
* Name & Student No.: Yanhong Ben, 4845675															
* Lab No: 6															
* File Description: head file of publication										
* Date Last Modified: 06/09/2015                                				
*********************************************************************************/

#ifndef PUBLICATION_H
#define PUBLICATION_H

class Publication
{
	private:
		string title;
		int publishYear;
		string publisher;
	public:
		Publication(string, int, string);
		virtual void print(ostream&);
};

class Book: public Publication
{
	private:
		string NoOfISBN;
		string authors[3];
	public:
		Book(string, int, string, string, string[]);
		void print(ostream&);
};

class Journal: public Publication
{
	private:
		string NoOfISSN;
		string chiefEditor;
		int volume;
	public:
		Journal(string, int, string, string, string, int);
		void print(ostream&);
};

#endif

