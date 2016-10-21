/********************************************************************************
 * Filename: truck.cpp
 * Name & Student No.: Yanhong Ben, 4845675
 * ASS No: 2
 * File Description: implementation file of task 2 truck head file
 * Date Last Modified: 27/09/2015
 *********************************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include "truck.h"
using namespace std;

Truck::Truck()
{
	vtype = 't';
    type = Light;
    gross = 0.0;
}

void Truck::update()
{
    Vehicle::update();
    cout << "Model: ";
    cin.getline(model, 15, '\n');
    int tempType;
    cout << "Type (1-light, 2-formal, 3-heavy): ";
    cin >> tempType;
    cin.ignore();
    type = static_cast<TRUCKTYPE>(tempType);
    cout << "Number of seats: ";
    cin >> gross;
    cin.ignore();
}

void Truck::display()
{
    cout << "Vehicle type: Truck" << endl;
    Vehicle::display();
    cout << "Model: " << model << endl;
    cout << "Type: ";
    switch(type)
    {
        case Light:
            cout << "Light";
            break;
        case Formal:
            cout << "Formal";
            break;
        case Heavy:
            cout << "Heavy";
            break;
        default:
            cout << "Unknown" << endl;
            break;
    }
    cout << endl;
    cout << "Can carry(KGs): " << gross << endl;
}

// overloading to read data from file
ifstream& operator>>(ifstream &fin, Truck *t)
{
    fin.getline(t->model, 15, ',');
    
    //get the type from the file and compare to the enum
    char tempType[10];
    fin.getline(tempType, 10, ',');
    if(strcmp(tempType, "Light") == 0)
        t->type = Light;
    else if(strcmp(tempType, "Formal") == 0)
        t->type = Formal;
    else if(strcmp(tempType, "Heavy") == 0)
        t->type = Heavy;
    else
        cout << "Wrong type." << endl;
    
    fin >> t->gross;
    fin.ignore();
    fin >> dynamic_cast<Vehicle *>(t);
    return fin;
}

// overloading to write data to file
ofstream& operator<<(ofstream &fout, const Truck *t)
{
    fout << 't' << ',';
    fout << t->model << ',';
    switch(t->type)
    {
        case Light:
            fout << "Light";
            break;
        case Formal:
            fout << "Formal";
            break;
        case Heavy:
            fout << "Heavy";
            break;
        default:
            fout << "Unknown" << endl;
            break;
    }
    fout << ',';    
    fout << t->gross << ',';
    fout << dynamic_cast<const Vehicle*>(t);
    return fout;
}

