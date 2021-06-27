/*
Code : Mirror
For a given Binary Tree of type integer, update it with its corresponding mirror image.
*/

/* 
Code : Height of Binary Tree
For a given Binary Tree of integers, find and return the height of the tree. 
*/

#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;
#include <queue>

//Height of Binary Tree
int height(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    int ans = 1;
    
    int leftTreeHeight = height(root->left);
    int rightTreeHeight = height(root->right);

    if(leftTreeHeight > rightTreeHeight){
        return ans + leftTreeHeight;
    } else {
        return ans + rightTreeHeight;
    }
}

//Mirror Problem
void mirrorImage(BinaryTreeNode<int> *root){
    if(root == NULL){
        return;
    }

    root = root;
    BinaryTreeNode<int>* temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorImage(root->left);
    mirrorImage(root->right);

}

// Alternate Solution
int height(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
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
    printTreeLevelWise(root);
    cout << height(root) << endl;
    delete root;
}