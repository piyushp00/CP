#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include "DynamicStack.cpp"
using namespace std;

int main() {
    DynamicStack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.size() << endl;

    cout << s.isEmpty() << endl;
}