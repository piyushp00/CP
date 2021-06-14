/* You have been given a singly linked list of integers. 
Write a function that returns the index/position 
of an integer data denoted by 'N' (if it exists). Return -1 otherwise. */

#include <iostream>
using namespace std;
#include "Node.cpp"


int findNode(Node *head, int num){
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        if(temp->data == num){
            return count;
        } 
        temp = temp->next;
        count++;
    
    }
    return -1;
}   
 

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
}

int main(){
    
    Node *head = takeInput();
    print(head);
    int data;
    cin >> data;
    int index = findNode(head, data);
    cout << index << endl;
}