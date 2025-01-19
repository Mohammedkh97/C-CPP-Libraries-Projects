#include "Course.hpp"
#include <iostream>

Course::Course() {}

Course::Course(string t, int courseid) : title{t}, courseID{courseid} {}

void Course::details()
{
    cout << "Course: " << title << ", ID: " << courseID << endl;
}

Course::~Course() {}
