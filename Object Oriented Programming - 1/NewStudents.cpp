#include <iostream>
using namespace std;

class NewStudents
{
public:
    int age;
    const int rollNumber;
    int &x;  //age reference variable

    //we can also initialise non const data member  
    //outer "this" is this->age and inner "this" is argument
    NewStudents(int r, int age) : rollNumber(r), age(age), x(this->age)  //can do this also but will be useless NewStudents() : rollNumber(101)
    {
        //rollNumber = r; will give error bcz of const data member.
    }
};