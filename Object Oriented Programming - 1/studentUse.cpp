#include <iostream>
using namespace std;
#include "student.cpp"

int main()
{
    //Create objects statically
    student s1;
    student s2;

    student s3, s4, s5;

    //s1.age = 24;
    s1.rollNumber = 101;

    cout << "S1 age :" << s1.getAge() << endl;
    cout << "S1 Roll NO :" << s1.rollNumber << endl;

    s1.display();
    //s2.display();
    //Create objects dynamically
    student *s6 = new student;
    //(*s6).age = 52;
    (*s6).rollNumber = 84;

    // Alternate way of assigning value;
    //s6->age = 21;
    s6->rollNumber = 18;
    cout << "S6 age :" << s6->getAge() << endl;
    cout << "S6 Roll No: :" << s6->rollNumber << endl;

    //(*s6).display();
    // alternate
    s6->display();
}