#include <iostream>
using namespace std;
#include "student.cpp"

int main()
{
    //Create objects statically
    student s1;
    student s2;

    student s3, s4, s5;

    s1.age = 24;
    s1.rollNumber = 101;

    

    //Create objects dynamically
    student *s6 = new student;
}