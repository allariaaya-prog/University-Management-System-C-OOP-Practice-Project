#pragma once

#include<iostream>
#include<string>
#include<vector>

#include "courses.h"

using namespace std;

class Prof
{

private:
    int id;
    string name;

    vector<Course> assignedCourses;

public:
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

    bool assignCourse(const Course& course)
    {
        assignedCourses.push_back(course);
        return true;
    }
};