/*
For a given singly linked list of integers, 
find and return its length. Do it using an iterative method. */

#include <iostream>
using namespace std;
#include "Node.cpp"


int length(Node *head){
    Node *temp = head;
    int length = 0;
    while(temp != NULL){
        temp = temp->next;
        length++;
    }
    return length;
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
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		cout << length(head) << endl;
	}
	return 0;
}
