#include <iostream>
using namespace std;
#include <cstring>

class Students
{
    int age;

public:
    char *name;

    Students(int age, char *name)
    {
        this->age = age;

        //Shallow copy- only address a[0] will pe copied.
        //this->name= name;

        //Deep copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void display()
    {
        cout << name << " " << age << endl;
    }
};