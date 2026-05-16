#include<iostream>
#include<string>
#include <vector>
#include<fstream> // for file handling

#include<uni.h>
#include "student.h"
#include "courses.h"
#include "prof.h"


using namespace std;

class uni 
{
private:

    //vectors to store students, courses and professors
    vector<Student> student;
    vector<Course> courses;
    vector<Prof> prof;

public:

    // functions from different files
    void addStudent(); //from courses file
    void addProf(); //from prof file
    void addCourse(); //from student file
    void registerCourse(); //from course file
};