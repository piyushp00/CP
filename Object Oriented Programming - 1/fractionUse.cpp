#include <iostream>
using namespace std;
#include "fraction.cpp"

int main(){
    fraction f1(20, 30);
    fraction f2(10, 40);
    f1.print();
    f2.print();

    f1.add(f2);
    f1.print();
    
}