#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include "stackUsingArrays.cpp"
using namespace std;

int main(){
    
    StackUsingArray s(4);
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
    /* cout<<"1) Push in stack"<<endl;
    cout<<"2) Pop from stack"<<endl;
    cout<<"3) Display stack"<<endl;
    cout<<"4) Top Stack"<<endl;
    cout<<"5) Stack Size"<<endl;
    cout<<"6) Is Stack Empty? "<<endl;
    cout<<"7) Exit"<<endl;
    

    

    do {
        cout << "Enter choice: "<<endl;
        cin >> ch;
        switch(ch) {
            case 1: {
                cout<<"Enter value to be pushed:"<<endl;
                cin>>val;
                s.push(val);
                break;
            }
            case 2: {
                s.pop();
                break;
            }
            case 3: {
                s.display();
                break;
            }
            case 4: {
                s.top();
                break;
            }
            case 5: {
                s.size();
                break;
            }
            case 6: {
                s.isEmpty();
                break;
            }
            case 7: {
                cout<<"Exit"<<endl;
                break;
            }
            default: {
                cout<<"Invalid Choice"<<endl;
            }
        }
    }   while(ch != 7); */
     

}
