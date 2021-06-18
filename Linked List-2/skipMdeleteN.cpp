/* You have been given a singly linked list of integers along with
two integers, 'M,' and 'N.' Traverse the linked list such that
you retain the 'M' nodes, then delete the next 'N' nodes. 
Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need 
to delete N nodes after every M nodes. */

#include <iostream>
using namespace std;
#include "Node.cpp"

Node *skipMdeleteN(Node *head, int m, int n){
    if(head == NULL || m == 0){
        return NULL;
    }
    
    if(n == 0){
        return head;
    }

    Node *currNode = head;
    Node *temp = NULL;
    
    while(currNode != NULL){
        int take = 0;
        int skip = 0;

        while(currNode != NULL && take < m){
            if(temp == NULL){
                temp = currNode;
            } else {
                temp->next = currNode;
                temp = currNode;
            }
            currNode = currNode->next;
            take++;
        }

        while(currNode != NULL && skip < n){
            Node *newNode = currNode;
            //delete currNode;
            currNode = newNode->next;
            skip++;
        }
    }
    
    if(temp != NULL){
        temp->next = NULL;
    }
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
    int m, n;
    cin >> m >> n;
    head = skipMdeleteN(head, m, n);
    print(head);
}