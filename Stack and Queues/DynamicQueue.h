#include <iostream>
using namespace std;

template <typename T> 

class Queue{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    //Constructor
    Queue(int s){
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    //Size Function
    int getSize(){
        return size;
    }

    //Empty Function
    bool isEmpty(){
        return size == 0;
    }

    //Insert Element(Dyanmic- no fixed size array)
    void enQueue(T element){
        if(size == capacity){
            T *newData = new T[2 * capacity];
            int j = 0;
            for(int i = firstIndex; i < capacity; i++){
                newData[j] = data[i];
                j++;
            }
            for(int i = 0; i < firstIndex; i++){
                newData[j] = data[i];
                j++;
            }
            delete[] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *=2;
        }
        
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if(firstIndex == -1){
            firstIndex = 0;
        }
        size++;
    }

    //Front function
    T front(){
        if(isEmpty()){
            cout << "Queue Empty!" << endl;
            return 0;
        }
        return data[firstIndex];
    }

    //Delete Element
    T deQueue(){
        if(isEmpty()){
            cout << "Queue Empty!" << endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if(size == 0){
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};