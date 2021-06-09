#include <iostream>
using namespace std;

class Student{
    static int totalStudents; //total number of students present(same for every obj-we will declare it static)
    public:

    int rollNumber;
    int age;


    Student(){
        totalStudents++; //to increment the value of totalStudents as we create new obj.
    }

    int getRollNumber(){
        return rollNumber;
    }

    static int getTotalStudents(){  //now this fn belong to a class
        return totalStudents;
    }
}; 

int Student :: totalStudents = 0; // initialize static data members