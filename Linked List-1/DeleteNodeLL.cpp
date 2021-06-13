#include <iostream>
using namespace std;
#include "Node.cpp"

// Delete Node

Node *deleteNode(Node *head, int i)
{
    if (head == NULL)
    {
        return head;
    }

    if (i == 0)
    {
        head = head->next;
        return head;
    }

    Node *temp = head;
    int count = 0;
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL)
    {
        return head;
    }

    temp->next = temp->next->next;
    //or
    /* Node *a = temp->next;
    temp->next = a->next;
    delete a; */

    return head;
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
    int i;
    cin >> i;
    head = deleteNode(head, i);
    print(head);
}