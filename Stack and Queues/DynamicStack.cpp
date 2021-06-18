#include <bits/stdc++.h>
#include <iostream>
#include <climits>
using namespace std;

class DynamicStack{
private:
    int *data;
    int nextIndex;
    int capacity;  
public:
    //Dynamic Array Constructor
    DynamicStack(){
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
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
            int *newData = new int[2 * capacity];
            for(int i = 0; i < capacity; i++){
                newData[i] = data[i];
            }
            capacity = capacity * 2;
            delete[] data;
            data = newData;
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

    void display() {
        if(nextIndex >= 0) {
            cout<<"Stack elements are:";
            for(int i = nextIndex; i >= 0; i--)
            cout << data[i] << " ";
            cout << endl;
        } else {
        cout << "Stack is empty";
        }
    }
};
