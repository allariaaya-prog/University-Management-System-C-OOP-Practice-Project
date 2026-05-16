#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
    private:
    string name;
    vector<Student> registeredCourses;
    int id;
    double gpa;

    public:
    //setters and getters
    void setName(string pName)
    {
        name = pName;
    }

    string getName()
    {
        return name;
    }

    void setId(int pId)
    {
        id = pId;
    }

    int getId()
    {
        return id;
    }

    void setGpa(double pGpa)
    {
        gpa = pGpa;
    }

    double getGpa()
    {
        return gpa;
    }
};

#endif // STUDENT_H