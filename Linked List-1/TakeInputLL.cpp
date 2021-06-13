#include <iostream>
using namespace std;
#include "Node.cpp"

//Better way to take Input(Complexity -  O(n))
Node *takeInputBetter(){
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

//Teke Input (Complexity - n^2(not good))
Node* takeInput1(){
    int data;
    cin >> data;
    Node *head = NULL; //means linked list is empty
    while(data != -1){
        Node *newNode = new Node(data); //we should use dynmic allocation only, else node created will be lost.
        if(head == NULL){
            head = newNode;
        } else {
            Node *temp = head;
            while(temp ->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode; 
        }
         
        cin >> data;  
    }
    return head;
}


//Print Function
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
    //Node *head = takeInput1();
    Node *head = takeInputBetter();
    print(head);
}