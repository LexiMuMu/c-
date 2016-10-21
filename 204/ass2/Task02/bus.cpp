/********************************************************************************
 * Filename: bus.cpp
 * Name & Student No.: Yanhong Ben, 4845675
 * ASS No: 2
 * File Description: implementation file of task 2 bus head file
 * Date Last Modified: 27/09/2015
 *********************************************************************************/

#include <iostream>
#include <cstring>
#include "bus.h"
using namespace std;

// init 
Bus::Bus()
{
	vtype = 'b';
    type = Mini;
    number_of_seats = 0;
}

//display vehicle infor
void Bus::display()
{
    cout << "Vehicle type: Bus" << endl;
    Vehicle::display();
    cout << "Model: " << model<< endl;
    cout << "Type: ";
    switch(type)
    {
        case Mini:
            cout << "Mini";
            break;
        case Normal:
            cout << "Normal";
            break;
        case Double:
            cout << "Double";
            break;
        case School:
            cout << "School";
            break;
        default:
            cout << "Unknown" << endl;
            break;
    }
    cout << endl;
    cout << "Number of seats: " << number_of_seats << endl;
}

void Bus::update()
{
    Vehicle::update();
    cout << "Model: ";
    cin.getline(model, 15, '\n');
    int tempType;
    cout << "Type (1-mini, 2-normal, 3-double, 4-school): ";
    cin >> tempType;
    cin.ignore();
    type = static_cast<BUSTYPE>(tempType);
    cout << "Number of seats: ";
    cin >> number_of_seats;
    cin.ignore();
}

// overloading to read data from file
ifstream& operator>>(ifstream &fin, Bus *b)
{
    fin.getline(b->model, 15, ',');
    
    char tempType[6];
    fin.getline(tempType, 6, ',');
    if(strcmp(tempType, "Mini") == 0)
        b->type = Mini;
    else if(strcmp(tempType, "Normal") == 0)
        b->type = Normal;
    else if(strcmp(tempType, "Double") == 0)
        b->type = Double;
    else if(strcmp(tempType, "School") == 0)
        b->type = School;
    else
        cout << "Wrong type." << endl;
    
    fin >> b->number_of_seats;
    fin.ignore();
    fin >> dynamic_cast<Vehicle *>(b);
    return fin;
}

// overloading to write data to file
ofstream& operator<<(ofstream &fout, const Bus *b)
{
    fout << 'b' << ',';
    fout << b->model << ',';
    switch(b->type)
    {
        case Mini:
            fout << "Mini";
            break;
        case Normal:
            fout << "Normal";
            break;
        case Double:
            fout << "Double";
            break;
        case School:
            fout << "School";
            break;	
        default:
            fout << "Unknown" << endl;
            break;
    }
    fout << ',';    
    fout << b->number_of_seats << ',';
    fout << dynamic_cast<const Vehicle*>(b);
    return fout;
}

