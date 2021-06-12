#include <iostream>
using namespace std;
#include "Node.cpp"


void print(Node *head){
    //We should not travel on head bcz we can loose its address. we should use a temp pointer
   //Node *temp = head;
    while(head != NULL){
        cout << head->data << " "; 
        head = head->next;
    }
    cout << endl;

    /*
    temp = head;
    while(temp != NULL){
        cout << temp->data << " "; 
        temp = temp->next;
    }*/
}    

int main()
{

    //Staticlly LinkedList Creation
    Node n1(1);
    // Storing the address of 1st node or head
    Node *head = &n1; //Its not a new node..Its just a pointer variable.
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    //Connecting Nodes
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    
    print(head);
    print(head);
    /* n1.next = &n2;
   cout << n1.data << " " << n2.data << endl;
   cout << head << endl;
   cout << head->data << endl; //cout << (*head).data << endl;

   //Dynamically LinkedList Creation
   Node *n3 = new Node(10);
   Node *head = n3;

   Node *n4 = new Node(20);
   n3->next = n4;  */
}