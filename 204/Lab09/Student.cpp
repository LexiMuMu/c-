/********************************************************************************
 * Filename: Student.cpp
 * Name & Student No.: Yanhong Ben, 4845675
 * Lab No: 9
 * File Description: String Stream
 * Date Last Modified: 15/10/2015
 *********************************************************************************/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "Student.h"

Student::Student()
{
    firstname = "";
    lastname = "";
    id = 0;
    gpa = 0;
}

Student::Student(string f, string l, int i, float g)
{
    firstname = f;
    lastname = l;
    id = i;
    gpa = g;
}

istream& operator>>(istream &in, Student &stud)
{
    char temp;

    getline(in, stud.firstname, ':');
    getline(in, stud.lastname, ':');
    in >> stud.id >> temp >> stud.gpa;

    return in;
}

ostream& operator<<(ostream &out, const Student &stud)
{
    out << stud.firstname << ":" << stud.lastname << ":" << stud.id << ":" << stud.gpa;
    return out;
}


