/*Given a linked list, find and return the length of the 
given linked list recursively.*/

#include <iostream>
using namespace std;
#include "Node.cpp"

int length(Node *head)
{
    //Base Case
   
    if (head == NULL)
    {
        return 0;
    }
    
    return 1 + length(head->next);
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

int main()
{
    Node *head = takeinput();
    cout << length(head) << endl;
}