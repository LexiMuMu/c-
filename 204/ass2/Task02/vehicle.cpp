/********************************************************************************
 * Filename: vehicle.cpp
 * Name & Student No.: Yanhong Ben, 4845675
 * ASS No: 2
 * File Description: implementation file of task 2 vehicle head file
 * Date Last Modified: 27/09/2015
 *********************************************************************************/
 
#include "vehicle.h"
#include <cstring>
#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
using namespace std;

Vehicle::Vehicle(const char* number, const char* make, const char* pdate, const char* rdate, const float weight, const char* owner, const char* add, const long ph)
//Vehicle(const char* number="", const char* make="", const char* pdate="", const char* rdate="", const float weight=0.0, const char* name="", const char* add="", const long ph=0);
{
    strcpy(plateNumber, number);
    strcpy(maker, make);
    strcpy(producedDate, pdate);
    strcpy(registedDate, rdate);
    grossWeight = weight;
    strcpy(ownerName, owner);
    strcpy(address, add);
    phone = ph;
}

Vehicle::Vehicle(const Vehicle &newVehicle)
{
    strcpy(plateNumber, newVehicle.plateNumber);
    strcpy(maker, newVehicle.maker);
    strcpy(producedDate, newVehicle.producedDate);
    strcpy(registedDate, newVehicle.registedDate);
    grossWeight = newVehicle.grossWeight;
    strcpy(ownerName, newVehicle.ownerName);
    strcpy(address, newVehicle.address);
    phone = newVehicle.phone;
}

Vehicle::Vehicle()
{
	grossWeight = 0.0;
	phone = 0;
}

Vehicle::~Vehicle(){}


void Vehicle::init(const char* number, const char* make, const char* pdate, const char* rdate, const float weight, const char* owner, const char* add, const long ph)
{
    strcpy(plateNumber, number);
    strcpy(maker, make);
    strcpy(producedDate, pdate);
    strcpy(registedDate, rdate);
    grossWeight = weight;
    strcpy(ownerName, owner);
    strcpy(address, add);
    phone = ph;
}

void Vehicle::setRegistedDate(const char *rdate)
{
    strcpy(registedDate, rdate);
}

void Vehicle::setOwner(const char *owner)
{
    strcpy(ownerName, owner);
}

void Vehicle::setAddress(const char *add)
{
    strcpy(address, add);
}

void Vehicle::setPhone(const long ph)
{
    phone = ph;
}

void Vehicle::setNumber(const char* pn)
{
	strcpy(plateNumber, pn);
}

char Vehicle::getVType()
{
    return vtype;
}

//Save vehicle info in a text file
void Vehicle::saveData(ofstream &out)
{
    out << plateNumber << ','
    << maker << ','
    << producedDate << ','
    << registedDate << ','
    << grossWeight << ','
    << ownerName << ','
    << address << ','
    << ownerName << ','
    << phone;
}

//overloading insertion operator to read data from file
ifstream& operator>>(ifstream &fin, Vehicle *v)
{
	char comma;
	fin.getline(v->plateNumber, 10, ',');
    fin.getline(v->maker, 20, ',');
    fin.getline(v->producedDate, 11, ',');
    fin.getline(v->registedDate, 11, ',');
    fin >> v->grossWeight >> comma;
    fin.getline(v->ownerName, 60, ',');
    fin.getline(v->address, 80, ',');
    fin >> v->phone;
    fin.ignore();
    return fin;
}

//overloading extraction operator to write data to file
ofstream& operator<<(ofstream &fout, const Vehicle *v)
{
	fout << v->plateNumber << ',';
	fout << v->maker << ',';
	fout << v->producedDate << ',';
	fout << v->registedDate << ',';
	fout << v->grossWeight << ',';
	fout << v->ownerName << ',';
	fout << v->address << ',';
	fout << v->ownerName << ',';
	fout << v->phone << endl;
	return fout;
}

//get today's date
const char* Vehicle::getTodayDate()
{
	time_t t = time(0);   // get now time
    struct tm * now = localtime( & t );
    string today;
    stringstream ss;
    ss << now->tm_mday;
    today = ss.str(); //change time_t to string
    today += '/';
    ss.str("");
    ss << now->tm_mon + 1;
    today += ss.str();
    today += '/';
    ss.str("");
    ss << now->tm_year + 1900;
    today += ss.str();
    return today.c_str(); //change string to char array and return
}

void Vehicle::update()
{
    cout << "Made by: ";
    cin.getline(maker, 20);

    cout << "Produced: ";
    cin.getline(producedDate, 11);
    
    strcpy(registedDate, getTodayDate());
    cout << "Register date: " << registedDate << endl;

    cout << "Gross weight: ";
    cin >> grossWeight;
    cin.ignore();
    cout << "Owner name: ";
    cin.getline(ownerName, 60);
    cout << "Corresponding address: ";
    cin.getline(address, 80);
    cout << "Contact phone: ";
    cin >> phone;
    cin.ignore();
}

void Vehicle::display()
{
    cout << "Made by: " << maker << endl;
    cout << "Produced: " << producedDate << endl;
    cout << "Registered: " << registedDate << endl;
    cout << "Gross weight: " << grossWeight << endl;
    cout << "Owner name: " << ownerName << endl;
    cout << "Corresponding address: " << address << endl;
    cout << "Contact phone: " << phone << endl;
}

