/********************************************************************************
 * Filename: vehicleManagement.cpp
 * Name & Student No.: Yanhong Ben, 4845675
 * ASS No: 2
 * File Description: implementation file of task 2 managment head file
 * Date Last Modified: 27/09/2015
 *********************************************************************************/

#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <fstream>
#include "vehicleManagement.h"
using namespace std;

VehicleManagement::VehicleManagement()
{
    recs = NULL;
    size = 0;
    recNum = 0;
}

VehicleManagement::~VehicleManagement()
{
    for(int i=0; i<recNum; i++)
        delete recs[i];
    delete [] recs;
}

void VehicleManagement::loadVehicles(ifstream & fin)
{
    char vtype, comma;
    int i = 0;
    recs = new Vehicle*[100];
    while (!fin.eof())
    {
    	fin >> vtype >> comma; //comma to deal with the comma in the file
    	if(fin.good())
    	{
    		if(vtype == 'c' ||vtype == 'C' )
    		{
    		    Car *tmpC = new Car;
    		    fin >> tmpC;
    		    recs[i] = tmpC;
    		}
    		else if(vtype == 'b' ||vtype == 'B' )
    		{
    		    Bus *tmpB = new Bus;
    		    fin >> tmpB;
    		    recs[i] = tmpB;
    		}
    		else if(vtype == 't' ||vtype == 'T' )
    		{
    		    Truck *tmpT = new Truck;
    		    fin >> tmpT;
    		    recs[i] = tmpT;
    		}
    		i++;
    	}
    }
    recNum = i;
    cout << recNum << " records loaded." << endl;
}

void VehicleManagement::addVehicle()
{
    char newPlate[10];
    int index = 0;
    bool isFound;
    do
    {
        isFound = false;
        cout << "Plate number: ";
        cin.getline(newPlate, 10, '\n');
        
        //change to Uppercase
        for(int i=0; newPlate[i] != '\0'; i++)
        {
            if(islower(newPlate[i]))
                newPlate[i] = toupper(newPlate[i]);
        }
        
        //search if plate number already exists
        index = searchVehicle(newPlate);
        if(index != -1)
        {
            cout << "Plate exists." << endl;
            isFound = true;
        }
    }
    while (isFound == true);
    
    int vtype;
    cout << "Choose vehicle (1-car, 2-bus, 3-truck): ";
    cin >> vtype;
    cin.ignore();
    
    // store to the array based on user input
    if (vtype == 1)
        recs[recNum] = new Car;
    else if (vtype == 2)
        recs[recNum] = new Bus;
    else if (vtype == 3)
        recs[recNum] = new Truck;
    
    recs[recNum]->update();
    recs[recNum]->setNumber(newPlate); //plate number need to set seperately since it is used to search records
    recNum++;
    cout << "Successfully registered. " << recNum << " car recorded have been saved." << endl;
}

void VehicleManagement::displayVehicle()
{
    char newPlate[10];
    int index = 0;

    cout << "Plate number: ";
    cin.getline(newPlate, 10, '\n');
    
    //change to Uppercase
    for(int i=0; newPlate[i] != '\0'; i++)
    {
        if(islower(newPlate[i]))
            newPlate[i] = toupper(newPlate[i]);
    }

    //search if plate number already exists
    index = searchVehicle(newPlate);
    if(index == -1)
        cout << "Plate not found." << endl;
    else
        recs[index]->display();
}

void VehicleManagement::renewVehicle()
{
    char newPlate[10];
    int index = 0;
    cout << "Plate number: ";
    cin.getline(newPlate, 10, '\n');
    
    //change to Uppercase
    for(int i=0; newPlate[i] != '\0'; i++)
    {
        if(islower(newPlate[i]))
            newPlate[i] = toupper(newPlate[i]);
    }

    //search if plate number already exists
    index = searchVehicle(newPlate);
    if(index == -1)
        cout << "Plate not found." << endl;
    else
    {
        char choice;
        cout << "Renew registration? (Y/N)";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            recs[index]->setRegistedDate(recs[index]->getTodayDate()); //use today date to replace the old date
            cout << "Registration renewed." << endl;
        }
    }
}

void VehicleManagement::transformVehicle()
{
    char newPlate[10];
    int index = 0;
    cout << "Plate number: ";
    cin.getline(newPlate, 10, '\n');
    
    //change to Uppercase
    for(int i=0; newPlate[i] != '\0'; i++)
    {
        if(islower(newPlate[i]))
            newPlate[i] = toupper(newPlate[i]);
    }

    //search if plate number already exists
    index = searchVehicle(newPlate);
    if(index == -1)
        cout << "Plate not found." << endl;
    else
    {
        recs[index]->display();//display the infor first
        char newOwner[60], newAddress[80];
        long newPhone;
        // overwrite with new info
        cout << "Please input new owner's information: " << endl;
        cout << "Owner name: " ;
        cin.getline(newOwner, 60, '\n');
        recs[index]->setOwner(newOwner);
        
        cout << "Corresponding address: ";
        cin.getline(newAddress, 80, '\n');
        recs[index]->setAddress(newAddress);
        
        cout << "Contact phone: ";
        cin >> newPhone;
        cin.ignore();
        recs[index]->setPhone(newPhone);
    }
}

void VehicleManagement::deleteVehicle()
{
    char newPlate[10];
    int index = 0;
    cout << "Plate number: ";
    cin.getline(newPlate, 10, '\n');
    
    //change to Uppercase
    for(int i=0; newPlate[i] != '\0'; i++)
    {
        if(islower(newPlate[i]))
            newPlate[i] = toupper(newPlate[i]);
    }

    //search if plate number already exists
    index = searchVehicle(newPlate);
    if(index == -1)
        cout << "Plate not found." << endl;
    else
    {
        char choice;
        cout << "Are you sure? (Y/N)";
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            delete recs[index];
            // move records behind the deleted records to move foreward
            for (int i=index; i<recNum-1; i++)
                recs[i] = recs[i+1];
            recNum--;
            cout << "Deletion succeed." << endl;
        }
    }
}

int VehicleManagement::searchVehicle(const char* newPlate)
{
    bool isFound = false;
    int index = 0;
    for( ; index<recNum && isFound == false; index++)
    {
        if (strcmp(newPlate, recs[index]->getNumber()) == 0)
            isFound = true;
    }

    if(isFound == false)
        return -1; //-1 represent not found
    else
        return index-1; // or return the index of the record
}

void VehicleManagement::run()
{
    //open file
    string filename;
    cout << "Input file name: ";
    cin >> filename;
    ifstream fin;
    fin.open(filename.c_str());
    while(!fin.good())
    {
        cout << "Filename wrong. Please re-enter: ";
        cin >> filename;
        fin.open(filename.c_str());
    }
    cin.ignore();
    loadVehicles(fin);
    fin.close();
    
    //do the processing
    bool quit = false;
    do
    {
        int choice;
        cout << "1. Register new vehicle " << endl;
        cout << "2. Display vehicle registration " << endl;
        cout << "3. Renew vehicle registration " << endl;
        cout << "4. Transform vehicle registration " << endl;
        cout << "5. Delete vehicle registration " << endl;
        cout << "6. Quit " << endl;
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();
        switch(choice)
        {
            case 1:
                addVehicle();
                break;
            case 2:
                displayVehicle();
                break;
            case 3:
                renewVehicle();
                break;
            case 4:
                transformVehicle();
                break;
            case 5:
                deleteVehicle();
                break;
            case 6:
            {
                //save data to the given file name
                cout << "Text file name: ";
                cin >> filename;
                ofstream fout;
                fout.open(filename.c_str());
                int index=0;
                for (index=0; index<recNum; index++)
                {
                    switch(recs[index]->getVType())
                    {
                        case 'c':
                            fout << reinterpret_cast<Car *>(recs[index]);
                            break;
                        case 'b':
                            fout << reinterpret_cast<Bus *>(recs[index]);
                            break;
                        case 't':
                            fout << reinterpret_cast<Truck *>(recs[index]);
                            break;
                        default:
                            fout.close();
                            return;
                    }
                }
                fin.close();
                cout << recNum << " car records have been saved." << endl;
                quit = true;
                break;
            }
            default:
                cout << "Wrong input. Please enter 1-6 options." << endl;
                break;
        }
    }while(!quit);
}


