#include <stdio.h>

struct Student
{
    char name[50];
    char major[50];
    int age;
    double gpa;
};


int main()
{
    struct Student stud1;
    stud1.age = 22;
    stud1.gpa = 3.2;
    strcpy(stud1.name, "Rahul");
    strcpy(stud1.major, "Business");
    return 0;
}