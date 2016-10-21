/********************************************************************************
 * Filename: webmanagement.h
 * Name & Student No.: Yanhong Ben, 4845675
 * ASS No: 3
 * File Description: head file of task 3 STL container
 *********************************************************************************/


#ifndef WEBMANAGEMENT_H
#define WEBMANAGEMENT_H

#include <iostream>
#include <map>
#include "website.h"

class WebManagement
{
private:
	std::map<std::string, Website> listWebsite; //set map container take string as a key
public:
	void loadWebsite(char *);
	void run();
	void addWebsite();
	void findWebsite();
	void updateWebsite();
	void removeWebsite();
	void displayAll();
	void saveWebiste();
};

#endif
