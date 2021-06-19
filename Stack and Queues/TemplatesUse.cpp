#include <bits/stdc++.h>
#include <iostream>
#include "Templates.cpp"
using namespace std;

int main(){

    Pair<Pair<int,int>, int> p2;
    p2.setY(10);
    Pair<int, int> p4;
    p4.setX(5);
    p4.setY(16);

    p2.setX(p4);
    cout << p2.getX().getX() << " " << p2.getX().getY() << " " <<  p2.getY() << endl;

    /* Pair<int, double> p1;
    p1.setX(100.34);
    p1.setY(100.34);
    cout << p1.getX() << " " << p1.getY() << endl; */

    /* Pair<int> p1;
    p1.setX(10);
    p1.setY(20);

    cout << p1.getX() << " " << p1.getY() << endl;
    
    Pair<double> p2;
    p2.setX(34.25);
    p2.setY(100.25);
    cout << p2.getX() << " " << p2.getY() << endl; */
}