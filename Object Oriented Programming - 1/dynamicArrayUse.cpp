#include <iostream>
using namespace std;
#include "DynamicArray.cpp"

int main()
{
    DynamicArray d1;

    d1.addElement(10);
    d1.addElement(20);
    d1.addElement(30);
    d1.addElement(40);
    d1.addElement(50);
    d1.addElement(60);

    d1.print();
    

    DynamicArray d2(d1); //Copy Constructor gets called; it will shallow copy

    DynamicArray d3;
    d3 = d1;  //it will also shallow copy.Changes will be reflected in d3 //so we have to make own own copy assignment operator
    d1.add(0, 100); //we have made changes in d1 but it will get reflected in d2 bcz of shallow copying// so make own copy constructor
    d2.print();
    d3.print(); 
    
}