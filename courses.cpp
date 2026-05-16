#include<iostream>
#include<string>
#include <vector>
#include<fstream> // for file handling


//#include "prof.h"

using namespace std;
class Course;

vector<Course> prerequistCourses;
vector<Course> completedCourses;

vector<double> grades;
vector<int> hours;
vector<int> prerequisites;

class Course
{
    
    private:
    //data members

    int courseId; //==course code
    string courseName;
    int creditHours;
    int maxStudents;
    int enrolledStudents;
    double gpa;
    
    vector<int> prerequisiteId;
    vector<int> prerequisites;
    vector<Course> registeredCourses;
    public:
    //setters and getters

    //setters& getters for vectors
    void prerequisiteCourse(int pId)
    {
        prerequisiteId.push_back(pId);
    }

    vector<int> getPrerequisiteCourse()
    {
        return prerequisiteId;
    }

    //setters& getters for other data members
    void setMaxStudents(int mStudents)
    {
        maxStudents = mStudents;
    }

    int getMaxStudents()
    {
        return maxStudents;
    }

    void setEnrolledStudents(int eStudents)
    {
        enrolledStudents = eStudents;
    }

    int getEnrolledStudents()
    {
        return enrolledStudents;
    }

    void setGpa(double g)
    {
        if(g >= 0.0 && g <= 4.0)
        {
            gpa = g;
        }
        else
        {
            cout << "Invalid GPA" << endl;
        }
    }

    double getGpa()
    {
        return gpa;
    }

    void setCourseId(int cId)
    {
        courseId = cId;
    }

    int getCourseId() const
    {
        return courseId;
    }

    void setCourseName(string cName)
    {
        courseName = cName;
    }

    string getCourseName()
    {
        return courseName;
    }
    
    void setPrerequisiteId(int pId)
    {
        prerequisiteId.push_back(pId);
    }

    vector<int> getPrerequisiteId()
    {
        return prerequisiteId;
    }

    void setCreditHours(int cHours)
    {
        creditHours = cHours;
    }

    int getCreditHours()
    {
        return creditHours;
    }

    //constructors

    Course() //empty cIdnstructor
    {
        courseId = 0;
        courseName = "unknown";
        creditHours = 0;
    }

    Course(int cId, string cName, int cHours, int mStudents) //parameterized constructor
    {
        courseId = cId;
        courseName = cName;
        creditHours = cHours;
        maxStudents = mStudents;
    }

    //functions

     bool isFull() const
    {
        return enrolledStudents >= maxStudents;
    }

     void increaseEnrollment()
    {
        enrolledStudents++;
    }

    void decreaseEnrollment()
    {
        if (enrolledStudents > 0)
            enrolledStudents--;
    }

     void addPrerequisite(int id)
    {
        prerequisiteId.push_back(id);
    }

    const vector<int>& getPrerequisites() const
    {
        return prerequisites;
    }
};




    class EnrollmentSystem
    {

    private:
    vector<Course> courses;
    vector<int> completedCourses;
    vector<Course> registeredCourses;

    public:

     bool courseExists(int id)
    {
        for (auto &c : courses)
            if (c.getCourseId() == id)
                return true;

        return false;
    }


        bool isDuplicate(int id)
        {
        for (auto &c : registeredCourses)
            if (c.getCourseId() == id)
            {
                return true;
            }
            return false;
        }
    

        bool hasPrerequisites(const Course & course)
    {
        for (int pre : course.getPrerequisites())
        {
            bool found = false;

            for (int done : completedCourses)
            {
                if (done == pre)
                {
                    found = true;
                    break;
                }
            }

            if (!found)
                return false;
        }

        return true;
    }

    bool isDuplicateCourse(int id)
    {
        for (auto &c : registeredCourses)
            if (c.getCourseId() == id)
            {
                return true;
            }
            return false;
    }

    
   void enrollCourse(const Course & newCourse)
{
    // check duplicate
    if(isDuplicateCourse(newCourse.getCourseId()))
    {
        cout << "Course already registered" << endl;
        return;
    }
    // enroll
    registeredCourses.push_back(newCourse);
    cout << "Course enrolled successfully" << endl;
}

      bool drop(int courseId)
    {
        for (int i = 0; i < registeredCourses.size(); i++)
        {
            if (registeredCourses[i].getCourseId() == courseId)
            {
                registeredCourses.erase(registeredCourses.begin() + i);
                return true;
            }
        }

        return false;
    }

   void searchCourse(int courseId)
{
    for(int i = 0; i < courses.size(); i++)
    {
        if(courses[i].getCourseId() == courseId)
        {
            cout << "Course found: " 
                 << courses[i].getCourseName() << endl;

        }
    }

    cout << "Course not found" << endl;
}

    //validations
    string addPrerequistCourse(Course course)
    {
        prerequistCourses.push_back(course);
        return "Prerequist course added successfully";
    }

    int checkprerequisite(Course course)
    {
        for(int i = 0; i < prerequistCourses.size(); i++)
        {
            if(prerequistCourses[i].getCourseId() == course.getCourseId())
            {
                cout << "you finished the prerequist course ,so you can enroll the next course: " << endl;
                return 1;
            }
        }

        cout << "you didnt finish the prerequist course before taking this course" << endl;
        return 0;
    }

    string removePrerequistCourse(int courseId)
    {
        for(int i = 0; i < prerequistCourses.size(); i++)
        {
            if(prerequistCourses[i].getCourseId() == courseId)
            {
                prerequistCourses.erase(prerequistCourses.begin() + i);
                return "Prerequist course removed successfully";
            }
        }

        return "Failed to remove prerequist course";
    }

 bool checkPrerequisite(Course course)
{
    vector<int> prerequisiteIds = course.getPrerequisiteId();

    for(int i = 0; i < completedCourses.size(); i++)
    {
        for(int j = 0; j < prerequisiteIds.size(); j++)
        {
            if(completedCourses[i] == prerequisiteIds[j])
            {
                return true;
            }
        }
    }

    return false;
}

    bool enroledHours(int cHours, int hours, bool isSummer, bool isGraduate)
    {
        if(isSummer) // summer semester condition
        {
            if(cHours >= 6 && cHours <= 9)
            {
                int creditHours = cHours;
                return true;
            }
            else
            {
                return false; 
            }

            if(isGraduate) // summer semester condition for graduate students
            {
                if(cHours >= 1 && cHours <= 18)
                {
                    int creditHours = cHours;
                    return true;
                }
                else
                {
                    return false; 
                }
            }
        }

        if(cHours >=12 && cHours <= 18) // regular semester condition
        {
            int creditHours = cHours;
            return true;
        }
        else
        {
            return false; 
        }

        if(isGraduate) // regular semester condition for graduate students
        {
            if(cHours >= 1 && cHours <= 12)
            {
                int creditHours = cHours;
                return true;
            }
            else
            {
                return false; 
            }
        }
    }

    string maxStudents(int mStudents)
    {
        if(mStudents > 0)
        {
            int maxStudents = mStudents;
            return "Max students updated successfully";
        }
        else
        {
            return "Failed to update max students"; 
        }
    }

bool checkCourseExists(int cId)
    {
    for(int i = 0; i < courses.size(); i++)
    {
        if(courses[i].getCourseId() == cId)
        {
            return true;
        }
    }
    return false;
}


    //gpa functions
 void setGpa(double g)
{
    if(g >= 0.0 && g <= 4.0)
    {
        double gpa = g;
    }
    else
    {
        cout << "Invalid GPA" << endl;
    }
}

    double calculateGPA(const vector<double>& grades, const vector<int>& hours) // to take vectors as parameters
{
    if (grades.size() != hours.size())
    {
        cout << "Error: mismatch between grades and hours\n";
        return -1;
    }

    //initialize total points and total hours
    double totalPoints = 0;
    int totalHours = 0;

    // calculate total points and total hours
    for (int i = 0; i < grades.size(); i++)
    {
        totalPoints += grades[i] * hours[i];
        totalHours += hours[i];
    }

    if (totalHours == 0)
    {
        cout << "Error: total hours is 0\n";
        return -1;
    }

    return totalPoints / totalHours;
}

    void academicProbation(double gpa)
    {
        if(gpa < 2.0)
        {
            cout << "Student is on academic probation" << endl;
        }
        else
        {
            cout << "Student is not on academic probation" << endl;
        }
    }

    void honorRoll(double gpa)
    {
        if(gpa >= 3.5)
        {
            cout << "Student is on the honor roll" << endl;
        }
    }

   int isTakeCourse(Course course)
    {
        for(int i = 0; i < registeredCourses.size(); i++)
        {
            if(registeredCourses[i].getCourseId() == course.getCourseId())
            {
                cout << "you already take this course before" << endl;
                return 0;
            }
        }

        return 1;
    }

    int isCompletedCourse(Course course)
    {
        for(int i = 0; i < completedCourses.size(); i++)
        {
            if(completedCourses[i] == course.getCourseId())
            {
                cout << "you already completed this course before" << endl;
                return 0;
            }
        }

        return 1;
    }


};
vector<Course> courses;
vector<Course> newCourses;