#include <bits/stdc++.h>
#include <iostream>
#include <climits>
using namespace std;

template <typename T>

class DynamicStack{
private:
    T *data;
    int nextIndex;
    int capacity;  
public:
    //Dynamic Array Constructor
    DynamicStack(){
        data = new T[4];
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
    void push(T element){
        if(nextIndex == capacity){
            T *newData = new T[2 * capacity];
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
    T pop(){
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    //To find top
    T top(){
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return 0;
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
