#include <bits/stdc++.h>
#include <iostream>
#include <climits>
//#include "LLStack.h"
#include <stack>
using namespace std;

int main(){
    
    //For internal stack
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    
    cout << s.size() << endl;

    cout << s.empty() << endl;

    //For our own stack
    /* Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.getSize() << endl;

    cout << s.isEmpty() << endl; */
}