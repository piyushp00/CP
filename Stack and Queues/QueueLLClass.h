#include <iostream>
using namespace std;

template <typename T>
class Node{
public:    
    T data;
    Node<T> *next;

    Node(T data){
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Queue{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    //Constructor
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    //Size Function
    int getSize(){
        return size;
    }

    //isEmpty Function
    bool isEmpty(){
        return size == 0;
    }

    //Insert Element;
    void enQueue(T element){
        Node<T> *newNode = new Node<T>(element);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    //Front Function
    T front(){
        if(size == 0){
            cout << "Queue Empty!" << endl;
            return 0;
        }
        return head->data;
    }

    //Delete Element
    T deQueue(){
        if(isEmpty()){
            cout << "Queue Empty!" << endl;
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
};