#include <bits/stdc++.h>
#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray{
private:
    int *data;
    int nextIndex;
    int capacity;  
public:
    //Constructor
    StackUsingArray(int totalSize){
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    //Return no of elements present in stack
    int size(){
        return nextIndex;
    }

    //To check if Stack is Empty or not
    bool isEmpty(){
        /* if(nextIndex == 0){
            return true;
        } else {
            return false;
        } */
        //or
        return nextIndex == 0;
    }

    //Insert Element
    void push(int element){
        if(nextIndex == capacity){
            cout << "Stack is Full" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    //Delete Element
    int pop(){
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    //To find top
    int top(){
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
};
