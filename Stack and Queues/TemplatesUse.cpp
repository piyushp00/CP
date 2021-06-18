#include <bits/stdc++.h>
#include <iostream>
#include "Templates.cpp"
using namespace std;

int main(){
    Pair<int> p1;
    p1.setX(10);
    p1.setY(20);

    cout << p1.getX() << " " << p1.getY() << endl;
    
    Pair<double> p2;
    p2.setX(34.25);
    p2.setY(100.25);
    cout << p2.getX() << " " << p2.getY() << endl;
}