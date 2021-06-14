/* You have been given a singly linked list of integers along 
with an integer 'N'. Write a function to append the 
last 'N' nodes towards the front of the singly linked list and 
returns the new head to the list. */

#include <iostream>
using namespace std;
#include "Node.cpp"

Node *appendLastNToFirst(Node *head, int n){
    if(n == 0 || head == NULL){
        return head;
    }
    
    Node *temp = head;
    Node *temp2 = head;
    Node *initialHead = head;
    
    for(int i = 0; i < n; i++){
        temp=temp->next;
    }

	while(temp->next != NULL){
        temp2= temp2->next;
        temp = temp->next;
    }

    Node *a = temp2->next;
    temp2->next = NULL;
    temp->next = head;
    head = a;
    
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
    int n;
    cin >> n;
    head = appendLastN(head, n);
    print(head);
}