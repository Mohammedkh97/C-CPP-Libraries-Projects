#include "Department.hpp"
#include <iostream>
#include <fstream>

Department::Department() {}

Department::~Department() {}

void Department::details()
{
    cout << "Department Details" << endl;
}

void Department::addCourse()
{
    string title;
    int courseid;
    cout << "Enter Course name: ";
    cin >> title;
    cout << "Enter Course ID: ";
    cin >> courseid;

    Course newCourse(title, courseid);
    courses.push_back(newCourse);

    ofstream outFile("courses.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << "Course Name: " << title << "            "
                << "Coures ID: " << courseid << endl;
        outFile.close();
        cout << "Course added and written to file." << endl;
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}
