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

    cout << s1.age << endl;
    cout << s1.rollNumber << endl;


    s1.display();
    s2.display();
    //Create objects dynamically
    student *s6 = new student;
    (*s6).age = 52;
    (*s6).rollNumber = 84;

    // Alternate way of assigning value;
    s6->age = 21;
    s6->rollNumber = 18;
} 