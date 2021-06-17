/* Find a node in LL (recursive)

Given a singly linked list of integers and an integer n, 
find and return the index for the first occurrence of 'n' 
in the linked list. -1 otherwise. */

#include <iostream>
using namespace std;
#include "Node.cpp"

int findNode(Node *head, int num){
    // Base Case
    if(head == NULL){
        return -1;
    } else if(head->data == num){
        return 0;
    }

    //Recursion Part
    int smallAns = findNode(head->next, num);

    //Small Calculation
    if(smallAns == -1){
        return -1;
    }

    return smallAns + 1;
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
    int n;
    cin >> n;
    cout << findNode(head, n) << endl;
    
}

