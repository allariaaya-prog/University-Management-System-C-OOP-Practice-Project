#include<iostream>
#include<string>
#include <vector>
#include<fstream> // for file handling

#include "courses.h"

using namespace std;


class Prof
{
    private:
    //data members

    int id;
    string name;
    string department;
    double salary;
    int courseId;
    vector<Course> assignedCourses;
    vector<Course> allCourses;

    public:
    //setters and getters

    void setCourseId(int pCourseId)
    {
        courseId = pCourseId;
    }

    int getCourseId()
    {
        return courseId;
    }

    void setSalary(double pSalary)
    {
        salary = pSalary;
    }

    double getSalary()
    {
        return salary;
    }
    
    void setId(int pId)
    {
        id = pId;
    }

    int getId()
    {
        return id;
    }

    void setName(string pName)
    {
        name = pName;
    }

    string getName()
    {
        return name;
    }

    void setDepartment(string pDepartment)
    {
        department = pDepartment;
    }

    string getDepartment()
    {
        return department;
    }

    //constructors
    Prof() //empty constructor
    {
        id = 0;
        name = "unknown";
        department = "unknown";
    }

    Prof(int pId, string pName, string pDepartment) //parameterized constructor
    {
        id = pId;
        name = pName;
        department = pDepartment;
    }

    //functions

    bool assignCourse( Course & course)
    {
        if (course.getCourseId() == 0)
        {
            return false;
        }

        if (assignedCourses.size() >= 5) // max 5 courses per professor
        {
            return false;
        }

        assignedCourses.push_back(course);
        return true;
    }

    bool removeCourse(int courseId)
    {
        for (int i = 0; i < assignedCourses.size(); i++)
        {
            if (assignedCourses[i].getCourseId() == courseId)
            {
                assignedCourses.erase(assignedCourses.begin() + i);
                return true;
            }
        }
        return false;
    }

    bool checkCourseAssigned(int courseId)
    {
        for (int i = 0; i < assignedCourses.size(); i++)
        {
            if (assignedCourses[i].getCourseId() == courseId)
            {
                return true;
            }
        }
        return false;
    }

    void displayAssignedCourses()
    {
        cout << "Courses assigned to Professor " << name << ":" << endl;
        for (int i = 0; i < assignedCourses.size(); i++)
        {
            cout << assignedCourses[i].getCourseName() << endl;
        }
    }

   bool hasCourse(int courseId)
{
    for (int i = 0; i < assignedCourses.size(); i++)
    {
        if (assignedCourses[i].getCourseId() == courseId)
        {
            return true;
        }
    }

    return false;
}

    

};