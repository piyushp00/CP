/* You have been given a singly linked list of integers where 
the elements are sorted in ascending order. Write a 
function that removes the consecutive duplicate values 
such that the given list only contains unique elements 
and returns the head to the updated list. */

#include <iostream>
using namespace std;
#include "Node.cpp"

Node *removeDuplicates(Node *head){

    if(head == NULL){
        return head;
    }

    Node *temp = head;
    int count = 0;

    while(temp->next != NULL){
        if(temp->data == temp->next->data){
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
}

int main(){
    
    Node *head = takeInput();
    print(head);
    int n;
    cin >> n;
    head = appendLastNToFirst(head, n);
    print(head);
}