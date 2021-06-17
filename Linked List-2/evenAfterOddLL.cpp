/* For a given singly linked list of integers, 
arrange the elements such that all the even 
numbers are placed after the odd numbers. 
The relative order of the odd and even terms 
should remain unchanged. */

#include <iostream>
using namespace std;
#include "Node.cpp"

Node *evenAfterOdd(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *oddHead = NULL;
    Node *oddTail = NULL;
    Node *evenHead = NULL;
    Node *evenTail = NULL;

    Node *temp = head;
    while(temp != NULL){
        if(temp->data % 2 != 0){
            if(oddHead == NULL){
                oddHead = temp;
                oddTail = temp;
            } else {
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
        }  else{
             if(evenHead == NULL){
                evenHead = temp;
                evenTail = temp;
            } else {
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
        }
        temp = temp->next;
    }
    if(oddHead == NULL){
        evenTail->next = NULL;
        return evenHead;
    }

    if(evenHead == NULL){
        oddTail->next = NULL;
        return oddHead;
    }

    oddTail->next = evenHead;
    evenTail->next = NULL;
    return oddHead;
}

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL && tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next; //or // tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    temp = head;
}

int main()
{
    Node *head = takeInput();
    print(head);
    
    head = evenAfterOdd(head);
    print(head);
}