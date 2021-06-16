#include <iostream>
using namespace std;
#include "Node.cpp"

//Recursive Approach
Node* merge(Node *head1, Node *head2) {
   if(head1 == NULL) {
     return head2;
   }

    if(head2 == NULL) {
     return head1;
    }

    Node *h1 = head1;
    Node *h2 = head2;

    if(h1->data <= h2->data) {
        h1->next = merge(h1->next, h2);
        return h1;
    }
    else {
        h2->next = merge(h1, h2->next);
        return h2;  
    }
}

Node *mergeSort(Node *head){
    //Base Case
    if(head == NULL || head->next == NULL){
        return head;
    }

    //Small Calculation
    Node *slow = head;
    Node *fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    //Recursion
    mergeSort(head);
    mergeSort(slow->next);
    Node *fH = merge(head, slow->next);
    return fH;
}

//Iterative Approach
/*
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
}*/

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
    head = mergeSort(head);
    print(head);
}