#include <iostream>
using namespace std;
#include "student.cpp"

int main(){
    
    student s1(10, 1001);
    cout << "Address of s1 :" << &s1 << endl;
    
    student s2(20);
    s2.display();
    /* student s1;
    s1.display();

    student s2;

    student *s3 = new student();
    s3->display();

    cout << "Parametrized constructor Demo" << endl;
    student s4(10);

    s4.display();

    student *s5 = new student(30);
    s5->display();

    student s6(20, 1002);
    s6.display(); */
 
}
