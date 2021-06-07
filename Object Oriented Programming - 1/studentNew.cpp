#include <iostream>
using namespace std;
#include "student.cpp"

int main()
{
    student s1;

    student *s2 = new student;

    s1.setAge(23, 123);
    s2->setAge(18, 123);

    s1.display();
    s2->display();
}