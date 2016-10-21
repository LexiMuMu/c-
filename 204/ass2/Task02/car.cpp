/********************************************************************************
 * Filename: car.cpp
 * Name & Student No.: Yanhong Ben, 4845675
 * ASS No: 2
 * File Description: implementation file of task 2 car head file
 * Date Last Modified: 27/09/2015
 *********************************************************************************/

#include <iostream>
#include <cstring>
#include "car.h"
using namespace std;

Car::Car()
{
	vtype = 'c';
    size = Small;
    type = Manual;
    number_of_seats = 0;
}

void Car::update()
{
    Vehicle::update();
    cout << "Model: ";
    cin.getline(model, 15);
    int tempSize;
    cout << "Size (1-small, 2-middle, 3-sport, 4-luxury): ";
    cin >> tempSize;
    size = static_cast<CARSIZE>(tempSize);
    cout << "Type (1-manual, 2-auto): ";
    int tempType;
    cin >> tempType;
    type = static_cast<CARTYPE>(tempType);
    cout << "Number of seats: ";
    cin >> number_of_seats;
    cin.ignore();
}

void Car::display()
{
    cout << "Vehicle type: Car" << endl;
    Vehicle::display();
    cout << "Model: " << model << endl;
    cout << "Size: ";
    switch(size)
    {
        case Small:
            cout << "Small";
            break;
        case Middle:
            cout << "Middle";
            break;
        case Sport:
            cout << "Sport";
            break;
        case Luxury:
            cout << "Luxury";
            break;
        default:
            cout << "Unknown" << endl;
            break;
    }
    cout << endl;
    cout << "Type: ";
    switch(type)
    {
        case Manual:
            cout << "Manual";
            break;
        case Automatic:
            cout << "Automatic";
            break;
        default:
            cout << "Unknown" << endl;
            break;
    }
    cout << endl;
    cout << "Number of seats: " << number_of_seats << endl;
}

// overloading to read data from file
ifstream& operator>>(ifstream &fin, Car *c)
{
    fin.getline(c->model, 15, ',');
    
    char tempSize[10];
    fin.getline(tempSize, 10, ',');
    if(strcmp(tempSize, "Small") == 0)
        c->size = Small;
    else if(strcmp(tempSize, "Middle") == 0)
        c->size = Middle;
    else if(strcmp(tempSize, "Sport") == 0)
        c->size = Sport;
    else if(strcmp(tempSize, "Luxury") == 0)
        c->size = Luxury;
    else
        cout << "Wrong size." << endl;
   
    char tempType[10];
    fin.getline(tempType, 10, ',');
    if(strcmp(tempType, "Manual") == 0)
        c->type = Manual;
    else if(strcmp(tempType, "Automatic") == 0)
        c->type = Automatic;
    else
        cout << "Wrong type." << endl;

    fin >> c->number_of_seats;
    fin.ignore();
    fin >> dynamic_cast<Vehicle *>(c);
    return fin;
}

// overloading to write data to file
ofstream& operator<<(ofstream &fout, const Car *c)
{
    fout << 'c' << ',';
    fout << c->model << ',';
    switch(c->size)
    {
        case Small:
            fout << "Small";
            break;
        case Middle:
            fout << "Middle";
            break;
        case Sport:
            fout << "Sport";
            break;
        case Luxury:
            fout << "Luxury";
            break;
        default:
            fout << "Unknown" << endl;
            break;
    }
    fout << ',';
    switch(c->type)
    {
        case Manual:
            fout << "Manual";
            break;
        case Automatic:
            fout << "Automatic";
            break;
        default:
            fout << "Unknown" << endl;
            break;
    }
    fout << ',';
    fout << c->number_of_seats << ',';
    fout << dynamic_cast<const Vehicle *>(c);
    
    return fout;
}



