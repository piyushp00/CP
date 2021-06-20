template<typename T> 

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

    //Insert Element
    void enQueue(T element){
        if(size == capacity){
            cout << "Queue Full!" << endl;
            return; 
        }
        data[nextIndex] == element;
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
        return ans;
    }
};