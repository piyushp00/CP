#include <iostream>
using namespace std;
#include "student.cpp"

int main(){

    student s1(10, 1001);
    student s2(20, 2001);
    student *s3 = new student(30, 3001);
    
    s2 = s1;
    *s3 = s1;

    s2 = *s3;
    //Destructor will be called only twice bcz s3 is created dynamically.
    
    delete s3;
    
    
    /* student s1(10, 1001);
    cout << "S1 : ";
    s1.display();

    student s2(s1);
    cout << "S2 : ";
    s2.display();

    student *s3 = new student(20, 2001);
    cout << " S3 : ";
    s3->display();

    student s4(*s3);
    cout << " S4 : ";
    s4.display();

    student *s5 = new student(*s3);
    student *s6 = new student(s1); */

}