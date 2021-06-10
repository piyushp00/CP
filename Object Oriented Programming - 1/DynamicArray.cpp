#include <iostream>
using namespace std;

class DynamicArray
{
    int *data;
    int nextIndex;
    int capacity; // total size

public:
    DynamicArray(){
        data = new int[5];
        nextIndex= 0;
        capacity = 5;
    }

    void addElement(int element){
        if(nextIndex == capacity){
            int *newData = new int[2 * capacity];
            for(int  i = 0; i < capacity; i++){
                newData[i] = data[i];
            }
            delete[] data; //remove the space occupied by old array
            data = newData; //point the address of old array to new array
            capacity  *= capacity; //since capacity is double;

        }
        data[nextIndex] = element;
        nextIndex++;
    }
};
