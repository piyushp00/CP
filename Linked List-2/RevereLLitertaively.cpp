#include <iostream>
using namespace std;
#include "Node.cpp"


Node *reverseLLIteratively(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;
    while(curr != NULL){
        Node *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
       }

    head = prev;
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
            tail = tail->next;
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

    //head = reverseLLrecursive(head);
    head = reverseLLIteratively(head);
    print(head);
}
