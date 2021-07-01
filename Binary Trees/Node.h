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
/*
    Node *takeInput(){
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL && tail == NULL){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next; //or // tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head){
    Node *temp = head;
    while(temp !=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    temp = head;
}*/
};