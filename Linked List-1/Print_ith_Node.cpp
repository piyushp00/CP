/* For a given a singly linked list of integers and a position 'i', print the node data at the 'i-th' position. */

#include <iostream>
using namespace std;
#include "Node.cpp"

void printIthNode(Node *head, int i)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }

    temp = head;

    if (i > (length - 1))
    {
        cout << "" << endl;
    }

    int k = 0;
    while (temp != NULL)
    {
        if (i == k)
        {
            cout << temp->data << endl;
        }
        temp = temp->next;
        k++;
    }
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
		int pos;
		cin >> pos;
		printIthNode(head, pos);
		cout << endl;
	}
	return 0;
}