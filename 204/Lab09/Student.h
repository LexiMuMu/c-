/********************************************************************************
 * Filename: Student.h
 * Name & Student No.: Yanhong Ben, 4845675
 * Lab No: 9
 * File Description: String Stream
 * Date Last Modified: 15/10/2015
 *********************************************************************************/


#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student 
{
    private:
        string firstname;
        string lastname;
        int id; //student number
        float gpa;
    public:
        Student();
        Student(string, string, int, float);
    friend std::istream& operator>>(std::istream &, Student &);
    friend std::ostream& operator<<(std::ostream &, const Student &);
};

#endif


