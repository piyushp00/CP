/*
For a given a Binary Tree of type integer, find and return the minimum 
and the maximum data values.
Return the output as an object of Pair class, which is already created.

Note: All the node data will be unique and hence there will always 
exist a minimum and maximum node data.
*/

#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include <climits>
using namespace std;

// Minimum and Maximum values
pair<int, int> minMax(BinaryTreeNode<int>* root){
    //make pair p using make_pair syntax
    pair<int, int> p = make_pair(INT_MAX, INT_MIN); 
    
    if(root == NULL){
        return p;
    }

    pair<int, int> leftAns = minMax(root->left);
    pair<int, int> rightAns = minMax(root->right);
    
    p.first = min(min(leftAns.first, rightAns.first), root->data);
    p.second = max(max(leftAns.second, rightAns.second), root->data);

    return p;
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
// 1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    
    pair<int, int> p = minMax(root);
    cout << "Min: " << p.first << endl;
    cout << "Max: " << p.second << endl;

    delete root;
}