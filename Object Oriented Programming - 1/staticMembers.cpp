#include <iostream>
using namespace std;
#include "TotalStudent.cpp"

int main()
{
    Student s1;
    Student s2;
    Student s3, s4, s5;
    //cout << s1.rollNumber << " " << s1.age << endl;
    //cout << s1.totalStudents << endl; //this is not the way to access but this won't give an error.

    //s1.totalStudents = 20;

    //cout << s2.totalStudents << endl;

    //cout << Student ::totalStudents << endl; //will give rror bcz total studentsis now a private property.

    cout << Student :: getTotalStudents() << endl;
}