#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <vector>
#include "Course.hpp"

class Department
{
public:
    vector<Course> courses;
    Department();
    ~Department();

    void details();
    void addCourse();
};

#endif
