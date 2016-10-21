/********************************************************************************
 * Filename: website.h
 * Name & Student No.: Yanhong Ben, 4845675
 * ASS No: 3
 * File Description: head file of task 3 STL container
 *********************************************************************************/

#ifndef WEBSITE_H
#define WEBSITE_H

#include <iostream>
#include <string>

class Website
{
	friend std::ostream& operator<<(std::ostream &, const Website &);
	private:
	    std::string name;
	    std::string webAddress;
	public:
	    Website();//default constructor
	    Website(const std::string, const std::string);//init constructor
	    void setName(std::string);
    	void setWebsite(std::string);
    	std::string getName();
    	std::string getWebsite();
};

#endif

