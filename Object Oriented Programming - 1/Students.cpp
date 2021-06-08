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

    //Copy Constructor(important)
    Students(Students const &s){
        this->age = s.age;
        //This is shallow copying we should avoid this.
        //this->name = s.name;  

        //Deep Copy
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }

    void display()
    {
        cout << name << " " << age << endl;
    }
};