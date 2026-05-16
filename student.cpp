#include<iostream>
#include<string>
#include <vector>
#include<fstream> // for file handling
#include<uni.h>

using namespace std;
// between the <> put the type of data you want to store in the vector
// if you want to add value to the vector:
// registeredCourses.push_back(value); // this will add the value to the end of the vector
// also you can add value to the vector at a specific index like arrays

class Student
{
    private:
    //data members

    int id;
    string name;
    double gpa;

    public:
    //setters and getters

    void setId(int i)
    {
        id = i;
    }

    int getId()
    {
        return id;
    }

    void setName(string n)
    {
        name = n;
    }

    string getName()
    {
        return name;
    }

    void setGpa(double g)
    {
        gpa = g;
    }

    double getGpa()
    {
        return gpa;
    }

    //constructors

    Student() //empty constructor
    {
        id = 0;
        name = "unKnown";
        gpa = 0.0;
    }

    Student(int i, string n, double g) //parameterized constructor
    {
        id = i;
        name = n;
        gpa = g;
    }

    //functions
    void searchStudent(int studentId)
{
    for(int i = 0; i < students.size(); i++)
    {
        if(students[i].getId() == studentId)
        {
            cout << "Student found: " 
                 << students[i].getName() << endl;

        }
    }

    cout << "Student not found" << endl;
}


    //validations
     bool isIdExists(int id)
{
    for(int i = 0; i < students.size(); i++)
    {
        if(students[i].getId() == id)
        {
            return true;
        }
    }

    return false;
}

    bool isStudentExists(int id)
{
    for(int i = 0; i < students.size(); i++)
    {
        if(students[i].getId() == id)
        {
            return true;
        }
    }

    return false;
}

     void checkStudentName(string name)
     {
        for(int i = 0; i < students.size(); i++)
        {
            if(students[i].getName() == "")
            {
                cout << "there is no student name, plz enter a valid name" << endl;
                return;
            }
        }
     }

     void checkStudentGpa(double gpa)
     {
        if(gpa < 0.0 || gpa > 4.0)
        {
            cout << "invalid gpa, plz enter a valid gpa" << endl;
            return;
        }
     }

    
        


};
vector<Student> registeredCourses;
vector<Student> completedCourses;
vector<Student> students;