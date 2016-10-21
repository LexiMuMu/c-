/********************************************************************************
 * Filename: stringIO.cpp
 * Name & Student No.: Yanhong Ben, 4845675
 * Lab No: 9
 * File Description: String Stream
 * Date Last Modified: 15/10/2015
 *********************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Student.h"

template<class T>
string toString(T value); //convert a value into a string

template<class T>
T toValue(string str); //convert a string into a value

int main()
{
    int newInt;
    string tempStr;
    cout << "Input an integer: ";
    cin >> newInt;
    
    tempStr = toString(newInt); //int to string
    cout << "Integer to string: " << tempStr << endl;
    
    newInt = toValue<int>(tempStr); //string to int
    cout << "String to integer: " << newInt << endl;
    cout << endl;
    
    
    double newDouble;
    cout << "Input an double: ";
    cin >> newDouble;
    
    tempStr = toString(newDouble); //double to string
    cout << "Double to string: " << tempStr << endl;
    
    newDouble = toValue<double>(tempStr); //string to double
    cout << "String to double: " << newDouble << endl;
    cout << endl;
    
    Student stud;
    cout << "Input a student record (first-name:last-name:number:gpa): ";
    cin.ignore();

    cin >> stud;
    tempStr = toString(stud); //Student to string
    cout << "Student to string: " << endl;
    cout << tempStr << endl;

    stud = toValue<Student>(tempStr); //string to Student
    cout << "String to Student: " << endl;
    cout << stud << endl;
    cout << endl;
    
    return 0;
}

template<class T>
string toString(T value)
{
    ostringstream sout;
    sout << value;
    return sout.str();
}

template<class T>
T toValue(string str)
{
    T value;
    istringstream sin(str);
    sin >> value;
    return value;
}

