#include "BST.h"
#include <iostream>
using namespace std;

int main(){
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.printTree();
}
