#include<iostream>
#include<string>
#include <vector>
#include<fstream> // for file handling

#include"uni.h"
class Student;

#include "student.h"

using namespace std;
vector<Student> students;
vector<Course> courses;

int main()
{
    Uni university;

    int choice;

do
{
    cout << "1. Add Student\n";
    cout << "2. Display Students\n";
    cout << "3. Add Course\n";
    cout << "4. Exit\n";

    cin >> choice;

    switch(choice)
    {
        case 1: 
        {
            // add student
            Student s;
            students.push_back(s);

            cout << "Student added successfully\n";
            break;
        }

        case 2: 
        {
            // display students
            if(students.empty())
            {
                cout << "No students found\n";
            }
            else
            {
                for(int i = 0; i < students.size(); i++)
                {
                    cout << "Student ID: " << students[i].getId() << endl;
                    cout << "Student Name: " << students[i].getName() << endl;
                    cout << "Student GPA: " << students[i].getGpa() << endl;
                    cout << "-----------------------------\n";
                }
            }
            break;
        }

        case 3: {
            // add course
            Course c ;
            courses.push_back(c);
            cout << "Course added successfully\n";
            break;
        }

        case 4: {
           if(students.empty() && courses.empty())
            {
                cout << "No students or courses found. Exiting...\n";
            }
            else
            {
                cout << "Exiting...\n";
            }
            break;
        }

        case 5: {
            // add professor
            Prof p;
            profs.push_back(p);
            cout << "Professor added successfully\n";
            break;
        }

        case 6: {
            if (profs.empty())
            {
                cout << "No professors found\n";
            }
            else
            {
                for(int i = 0; i < profs.size(); i++)
                {
                    cout << "Professor Name: " << profs[i].getName() << endl;
                    cout << "-----------------------------\n";
                }
            }

            break;
        }

        case 7: {
            cout<<"Exiting..."<<endl;
            break;
        }

        default:
            cout << "Invalid choice";
    }

} while(choice != 7);
}
