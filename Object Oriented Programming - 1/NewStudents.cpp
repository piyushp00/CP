#include <iostream>
using namespace std;

class NewStudents
{
public:
    int age;
    const int rollNumber;

    NewStudents(int r) : rollNumber(r)
    {
        //rollNumber = r; will give error bcz of const data member.
    }
};