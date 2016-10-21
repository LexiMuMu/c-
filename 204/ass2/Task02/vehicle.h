#include <iostream>
#include <fstream>
#include <string>
#ifndef _VEHICLE_
#define _VEHICLE_

class Vehicle
{
	friend std::ifstream& operator>>(std::ifstream &, Vehicle *);
	friend std::ofstream& operator<<(std::ofstream &, const Vehicle *);
	protected:
		char plateNumber[10];
		char maker[20];
		char producedDate[11];	//store the vehicle produced date dd/mm/yyyy
		char registedDate[11];	//store the vehicle registed date dd/mm/yyyy
		float grossWeight;	//1000.0 means 1000.0 Kilo gram
		char ownerName[60];
		char address[80];
		long phone;
		char vtype;    //'c'-car, 'b'-bus, 't'-truck
	public:
		Vehicle();
		Vehicle(const char*, const char*, const char*, const char*, const float, const char*, const char*, const long);
		//Vehicle(const char* number="", const char* make="", const char* pdate="", const char* rdate="", const float weight=0.0, const char* name="", const char* add="", const long ph=0);
		Vehicle(const Vehicle &);
		virtual ~Vehicle();

		virtual	void display();  // Display to screen
		virtual	void update();  // Input from keyboard
		const	char* getNumber(){return plateNumber;}
		void init(const char* , const char* , const char* , const char* , const float , const char* , const char* , const long );
		void setRegistedDate(const char *);
		void setOwner(const char *);
		void setAddress(const char *);
		void setPhone(const long);
		void setNumber(const char*);
		char getVType();
		const char* getTodayDate();
		void saveData(std::ofstream &out); //Save vehicle info in a text file

};

#endif	
