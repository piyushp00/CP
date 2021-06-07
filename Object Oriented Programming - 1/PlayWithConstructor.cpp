#include <iostream>
using namespace std;
#include "student.cpp";

int main(){
    student s1;  // Constructor 1 called

    student s2(101);  // Constructor 2 called 

    student s3(20, 102);  // Constructor 3 called

    student s4(s3);  // Copy Constructor 

    s1 = s2; //Copy Assignment operator

    // #Note
    student s5 = s4; //Copy Constructor - Internally same as "student s5(s4);""
}