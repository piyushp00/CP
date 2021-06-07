#include <iostream>
using namespace std;
#include "student.cpp"

int main(){
    student s1(10, 1001);
    cout << "S1 : ";
    s1.display();

    student s2(s1);
    cout << "S2 : ";
    s2.display();

}