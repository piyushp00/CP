#include <iostream>
using namespace std;
#include "Node.cpp"

Node *deleteNode(Node *head, int i){

    //Base Case
    if(head == NULL){
        return head;
    }

    //Small Calculation
    if(i == 0){
        head = head->next;
        return head;
    }

    //Recursion Part
    Node *x = deleteNode(head->next, i-1);
    head->next = x;
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