#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course
{
public:
    string title;
    int courseID;

    Course();
    Course(string t, int courseid);
    void details();
    ~Course();
};

#endif
