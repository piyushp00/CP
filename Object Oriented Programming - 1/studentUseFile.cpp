#include <iostream>
using namespace std;
#include "Students.cpp"

int main() {
    char name[] = "abcd";
    Students s1(20, name);
    s1.display();

    Students s2(s1);
    s2.name[0] = 'x';
    s1.display();
    s2.display();

    /* name[3] = 'e';
    Students s2(24, name);
    s2.display();

    s1.display(); */
}