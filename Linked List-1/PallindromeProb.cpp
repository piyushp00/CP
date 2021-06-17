/* You have been given a head to a singly linked list of integers. Write a 
function check to whether the list given is a 'Palindrome' or not. */

#include <iostream>
using namespace std;
#include "Node.cpp"

Node *reverseLL(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    Node *smallAns = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallAns;
}

//Time Complexity - O(n) Space Complexity- O(1) 
bool isPalindrome(Node *head){
    
    if(head == NULL || head->next == NULL){
        return true;
    }

    //find center of the list
    Node *slow = head;
    Node *fast=  head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    //Divide the List
    Node *revHead  = slow->next;
    slow->next = NULL;
    revHead = reverseLL(revHead);  //Reverse the second half
    
    //Compare the two sublist
    Node *firstList = head;
    Node *secondList = revHead;
    
    bool ans = true;
    while(secondList != NULL){
        if(firstList->data != secondList->data){
            ans = false;
            break;
         } 
        firstList = firstList->next;
        secondList = secondList->next;
    }
    
    //Rejoin the two sublist
    firstList= head;
    secondList= reverseLL(revHead);;
    
    while(firstList->next != NULL){
        firstList = firstList->next;
    }
    firstList->next = secondList;
    return ans;
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
    
    cout << isPalindrome(head) << endl;
}