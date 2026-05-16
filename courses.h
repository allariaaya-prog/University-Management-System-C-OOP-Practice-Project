#pragma once

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Course
{
private:

    int courseId;
    string courseName;

public:

    int getCourseId()
    {
        return courseId;
    }

    string getCourseName()
    {
        return courseName;
    }
};