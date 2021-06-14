#include <iostream>
using namespace std;
#include "Node.cpp"


// Insert Node Recursively
Node *insertNode(Node *head, int i, int data){

    //Base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    //Small Calculation
    Node *newNode = new Node(data);
    if(i == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }

    //Recursion Part
    Node *x = insertNode(head->next, i-1, data);
    head->next = x;
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