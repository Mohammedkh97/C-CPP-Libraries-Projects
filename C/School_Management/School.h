#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Include the usleep function
#include <time.h>
#include <windows.h>

#define FILENAME "students.txt"
#define MAX_STUDENTS 1000

// ANSI escape codes for text color (Windows)
#define COLOR_RESET "\033[0m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_CYAN "\033[1;36m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"



typedef struct person
{
    char name[30];
    int age;
    char phone[11];

} person;

typedef struct student
{
    char name[30];
    int age;
    int ID;
    char grade;
    int NoOfbrothers;
    person father;
    person mother;
    person *brothers;

}student;

void add_NewStudent(student *s);
void editStudent(student *arr , int size , student *s);
int removeStudent(student *arr , int *size);
void scanString(char *str, int maxSize);
void printStudent(student s);
int printAll(student *arr , int size);
void string_UppertoLower(char *str);
int string_CompareNotSensetiveCase(char *str1, char *str2);
int loadStudents(student *arr, int *size);
int saveStudents(const student *arr, int size);
void delay(int seconds);
void options();
void editingOptions(student *school, int option, int size , int *exitFlag);
void welcomeMessage();
void byeMessage();
