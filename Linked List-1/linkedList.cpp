#include <iostream>
using namespace std;
#include "Node.cpp"

int main(){

   //Staticlly
   Node n1(1);
   // Storing the address of 1st node or head
   Node *head = &n1; //Its not a new node..Its just a poiinter variable.
   Node n2(2);

   n1.next = &n2;
   cout << n1.data << " " << n2.data << endl;
   cout << head << endl;
}