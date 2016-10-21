/********************************************************************************
* Filename: bus.h                                         			   		
* Name & Student No.: Yanhong Ben, 4845675
* ASS No: 2																		
* File Description: head file of task 2 derived bus class										
* Date Last Modified: 27/09/2015                                				
*********************************************************************************/

#include "vehicle.h"

#ifndef _BUS_
#define _BUS_

enum BUSTYPE {Mini, Normal, Double, School};

class Bus: public Vehicle
{
	private:
	    char model[15];
	    BUSTYPE type;
	    int number_of_seats;
	public:
		Bus();
		void display();  // Display to screen
		void update();  // Input from keyboard    
    friend std::ifstream& operator>>(std::ifstream &, Bus*);
    friend std::ofstream& operator<<(std::ofstream &, const Bus*);
};

#endif

