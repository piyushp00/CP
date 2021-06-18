/* You have been given a singly linked list of integers along with
 two integers, 'i,' and 'j.' Swap the nodes that are present at
  the 'i-th' and 'j-th' positions. */


#include <iostream>
using namespace std;
#include "Node.cpp"

Node *swapNodes(Node *head, int i, int j){
    if(i == j){
        return head;
    }

    Node *temp = head, *prev = NULL;
    Node *firstNode = NULL, *secondNode = NULL, *firstNodePrev = NULL, *secondNodePrev = NULL;
    int pos = 0;
    while(temp != NULL){
        if(pos == i){
            firstNodePrev = prev;
            firstNode = temp;
        } else if(pos == j){
            secondNodePrev = prev;
            secondNode = temp;
        }
        prev = temp;
        temp = temp->next;
        pos++;
    }

    if(firstNodePrev != NULL){
        firstNodePrev->next = secondNode;
    } else{
        head = secondNode;
    }

    if(secondNodePrev != NULL){
        secondNodePrev->next = firstNode;
    } else {
        head = firstNode;
    }

    Node *currentFirstNode = secondNode->next;
    secondNode->next = firstNode->next;
    firstNode->next = currentFirstNode;

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
    int i, j;
    cin >> i >> j;
    head = swapNodes(head, i, j);
    print(head);
}