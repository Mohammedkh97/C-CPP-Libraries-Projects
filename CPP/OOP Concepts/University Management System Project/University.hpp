#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <vector>
#include "Faculty.hpp"

class University
{
public:
    string title;
    vector<Faculty> faculties;

    University();
    ~University();

    void details();
    void addFaculty();
};

#endif
