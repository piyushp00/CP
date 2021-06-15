/* For a given singly linked list of integers, 
find and return the node present at the middle
of the list. */

#include <iostream>
using namespace std;
#include "Node.cpp"

Node *midPoint(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    Node *slow = head;
    Node *fast = head->next;
    if (count % 2 != 0)
    {
        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    else
    {
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    return slow;
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
    Node *mid = midPoint(head);
    if (mid != NULL)
    {
        cout << mid->data;
    }
    cout << endl;
}
