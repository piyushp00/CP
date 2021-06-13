#include <iostream>
using namespace std;
#include "Node.cpp"

//Insert Node at ith positon
Node *insertNode(Node *head, int i, int data){
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;

    if(i == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }

    while(temp != NULL && count < i-1){
        temp = temp->next;
        count++;
    }
    if(temp != NULL){
    newNode->next = temp->next; //newNode->next = a;
    temp->next = newNode;
    //or
    /* Node *a = temp->next;
    temp->next = newNode;
    newNode->next = a; */
    }
    return head;   
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
    int i, data;
    cin >> i >> data;
    head = insertNode(head, i, data);
    print(head);
}

