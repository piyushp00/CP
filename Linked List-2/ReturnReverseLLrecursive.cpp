/* Given a singly linked list of integers, reverse it using
recursion and return the head to the modified list. You 
have to do this in O(N) time complexity where N is the 
size of the linked list.
 */
#include <iostream>
using namespace std;
#include "Node.cpp"

class Pair {
public:
    Node *head;
    Node *tail;
};

//Double Node Approach (O(n))
Pair reverseLLrecursive_2(Node *head){
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = reverseLLrecursive_2(head->next);
    smallAns.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

Node *reverseLLrecursiveBetter(Node *head){
    return reverseLLrecursive_2(head).head;
}


//Complexity(O(n^2))
Node *reverseLLrecursive(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *smallHead = reverseLLrecursive(head->next);
    //or
    //head->next->next = head;
    Node *temp = smallHead;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallHead;
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
    head = reverseLLrecursive(head);
    print(head);
}