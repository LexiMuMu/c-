/********************************************************************************
 * Filename: car.h
 * Name & Student No.: Yanhong Ben, 4845675
 * ASS No: 2
 * File Description: head file of task 2 derived car class
 * Date Last Modified: 27/09/2015
 *********************************************************************************/

#include "vehicle.h"

#ifndef _CAR_
#define _CAR_

enum CARSIZE {Small, Middle, Sport, Luxury};
enum CARTYPE {Manual, Automatic};

class Car: public Vehicle
{
private:
    char model[15];
    CARSIZE size;
    CARTYPE type;
    int number_of_seats;
public:
	Car();
    void display();  // Display to screen
	void update();  // Input from keyboard

friend std::ifstream& operator>>(std::ifstream &, Car *);  // overloading >> to read data from a file
friend std::ofstream& operator<<(std::ofstream &, const Car *);  // overloading << to write to file
};

#endif

