/*
Given a binary tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the 
given two nodes in the binary tree.

LCA->LCA of two nodes A and B is the lowest or deepest node which has both A and B as 
its descendants. 

It is defined that each node is a descendant to itself, so, if there are two nodes X 
and Y and X has a direct connection from Y, then Y is the lowest common ancestor.

Note:
1. If out of 2 nodes only one node is present, return that node. 
2. If both are not present, return -1.
*/

#include <iostream>
#include "BinaryTreeNode.h"
#include "Node.h"
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//Lowest Common Ancestor(LCA)
int getLCA(BinaryTreeNode<int> *root, int val1, int val2){
    if(root == NULL){
        return -1;
    }

    if(root->data == val1 || root->data == val2){
        return root->data;
    }

    int a = getLCA(root->left, val1, val2);
    int b =getLCA(root->right, val1, val2);

    if(a == -1 && b == -1){
        return -1;
    } else if(a == -1){
        return b;
    } else if(b == -1){
        return a;
    } else if(a != -1 && b != -1){
        return root->data;
    }
}

//Print Level at New Line
void printLevelWise(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    
    while(pendingNodes.size() != 0) {
        BinaryTreeNode<int>* frontNode = pendingNodes.front();
        pendingNodes.pop();

        if(frontNode == NULL) {
            cout << endl;
            if(!pendingNodes.empty()) {
                pendingNodes.push(NULL);
            }
        } else {
            cout << frontNode->data << " ";

            if(frontNode->left != NULL) {
                pendingNodes.push(frontNode->left);
            }

            if(frontNode->right != NULL) {
                pendingNodes.push(frontNode->right);
            }
        }
    }
}

//Print Level Wise
void printTreeLevelWise(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return;
    }
    
    queue<BinaryTreeNode<int>*> pendingNode;
    pendingNode.push(root);

    while(pendingNode.size() != 0) {
        BinaryTreeNode<int>* front = pendingNode.front();
        pendingNode.pop();

        cout << front->data << ":";
        if(front->left == NULL) {
            cout<<"L:-1,";
        } else {
            cout << "L:" << front->left->data << ",";
            pendingNode.push(front->left);
        }

        if(front->right == NULL) {
            cout << "R:-1";
        } else {
            cout << "R:" << front->right->data;
            pendingNode.push(front->right);
        }
        cout << endl;
    }
}

//Take Input Level wise
BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter Root Data" << endl;
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter Left Child of " << front->data << endl; 
        int leftChildData;
        cin >> leftChildData;
        if(leftChildData != -1) {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter Right Child of " << front->data << endl; 
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData != -1) {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

// 1 2 3 4 5 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int val1, val2;
    cin >> val1 >> val2;
    cout << getLCA(root, val1, val2);
    delete root;
}
