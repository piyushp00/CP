#include <iostream>
using namespace std;
#include "fraction.cpp"

int main(){
    fraction f1(10, 2);
    fraction f2(15, 4);
    f1.print();
    f2.print();

    fraction const f3;
    cout << f3.getNumerator() << " " << f3.getDenominator() << endl;
}