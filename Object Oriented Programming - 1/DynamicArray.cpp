#include <iostream>
using namespace std;

class DynamicArray
{
    int *data;
    int nextIndex;
    int capacity; // total size

public:
    DynamicArray()
    {
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    //our own Copy Constructor to get rid of shallow copying
    DynamicArray(DynamicArray const &d){
        //how internal copy constructor work.
        /* this->data = d.data;  //shallow copying,
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity; */

        //our own copy constructor
        //It will do Deep Copy
        this->data = new int[d.capacity];
        for(int i = 0; i < d.nextIndex; i++){
            this->data[i] = d.data[i];
        }
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }

    //own copy assignement operator
    void operator=(DynamicArray const &d){
        
        //will be same as copy constructor code.
        this->data = new int[d.capacity];
        for(int i = 0; i < d.nextIndex; i++){
            this->data[i] = d.data[i];
        }
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }

    void addElement(int element)
    {
        if (nextIndex == capacity)
        {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;  //remove the space occupied by old array
            data = newData; //point the address of old array to new array
            capacity *= 2;  //since capacity is double;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int getElement(int i) const
    {
        if (i < nextIndex)
        {
            return data[i];
        }
        else
        {
            return -1;
        }
    }

    void add(int i, int element)
    {
        if (i < nextIndex)
        {
            data[i] = element;
        }
        else if (i == nextIndex)
        {
            addElement(element);
        }
        else
        {
            return;
        }
    }

    void print() const
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
