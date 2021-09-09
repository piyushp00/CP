#include <iostream>
#include "ClassCar.h"
using namespace std;

int main()
{
    Vehicle v;

    v.color = "Blue";
    //    v.numTyres = 4; // protected members are accessible to classses only through derived classes
    //    v.maxSpeed = 100; //private property

    Car c;
    c.color = "Black";
    // c.numTyres = 4; //protected members are accessible to classses only through derived classes
    c.numGears = 5;
}

