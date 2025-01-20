#include "University.hpp"
#include <iostream>
#include <fstream>

University::University() {}

University::~University() {}

void University::details()
{
    cout << "University Details" << endl;
}

void University::addFaculty()
{
    string title;
    cout << "Enter Faculty name: ";
    getline(cin, title);

    Faculty newFaculty(title);
    faculties.push_back(newFaculty);

    ofstream outFile("faculties.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << title << endl;
        outFile.close();
        cout << "Faculty added and written to file." << endl;
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}
