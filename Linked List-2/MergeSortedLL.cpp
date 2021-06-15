/* You have been given two sorted(in ascending order) singly linked lists
of integers.Write a function to merge them in such 
a way that the resulting singly linked list 
is also sorted(in ascending order) and return the new head to the list. */

#include <iostream>
using namespace std;
#include "Node.cpp"

//Iterative Approach
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
    if(head1 == NULL){
        return head2; 
    }
    
    if(head2 == NULL){
        return head1;
    }
    Node *fH = NULL;
    Node *fT = NULL;

    Node *h1 = head1;
    Node *h2 = head2;

    if(h1->data <= h2->data){
            fH = h1;
            fT = h1;
            h1 = h1->next;
            
    } else {
            fH = h2;
            fT = h2;
            h2 = h2->next;
           
    }

    while(h1 != NULL && h2 != NULL){
        if(h1->data < h2->data){
            fT->next = h1;
            fT = fT->next;
            h1 = h1->next;
        } else {
            fT->next = h2;
            fT = fT->next;
            h2 = h2->next;
           
        }
    }

    if(h1 != NULL){
        fT->next = h1;
    }

    if(h2 != NULL){
        fT->next = h2;
    }

    return fH;
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

    Node *head1 = takeInput();
    Node *head2 = takeInput();
    Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
    print(head3);
}