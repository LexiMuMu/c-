/********************************************************************************
* Filename: vehicleManagement.h                                         			   		
* Name & Student No.: Yanhong Ben, 4845675															
* ASS No: 2																		
* File Description: head file of task 2 management vehicle										
* Date Last Modified: 27/09/2015                                				
*********************************************************************************/

#include "vehicle.h"
#include "car.h"
#include "bus.h"
#include "truck.h"
#include <fstream>
#ifndef _MANAGEMENT_
#define _MANAGEMENT_

class VehicleManagement
{
	private:
		Vehicle **recs; //pointer of base case vehicle
		int size; //size of the array
		int recNum; //records number of the file
	public:
		VehicleManagement();
		~VehicleManagement();
		void loadVehicles(std::ifstream &);
		void addVehicle();
		void displayVehicle();
		void renewVehicle();
		void transformVehicle();
		void deleteVehicle();
		int searchVehicle(const char*);  // Search specific vehicle from record array
		void run(); // process of the management
};

#endif


