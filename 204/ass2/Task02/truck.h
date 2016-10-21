/********************************************************************************
* Filename: truck.h                                         			   		
* Name & Student No.: Yanhong Ben, 4845675
* ASS No: 2																		
* File Description: head file of task 2 derived truck class										
* Date Last Modified: 27/09/2015                                				
*********************************************************************************/

#include "vehicle.h"

#ifndef _TRUCK_
#define _TRUCK_

enum TRUCKTYPE {Light, Formal, Heavy};

class Truck: public Vehicle
{
	private:
	    char model[15];
	    TRUCKTYPE type;
	    double gross;
	public:
		Truck();
		void display();  // Display to screen
		void update();  // Input from keyboard
	friend std::ifstream& operator>>(std::ifstream &, Truck *);  // overloading >> to read data from a file
	friend std::ofstream& operator<<(std::ofstream &, const Truck *);  // overloading << to write to file

};

#endif

