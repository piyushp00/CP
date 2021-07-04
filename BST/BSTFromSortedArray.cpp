/* Given a sorted integer array A of size n, which contains all unique elements. 
You need to construct a balanced BST from this input array. Return the root 
of constructed BST.
Note: If array size is even, take first mid as root. */

/* Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). 
If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree. */
 

#include <iostream>
#include "BinaryTreeNode.h"
#include "Node.h"
#include <vector>
#include <climits>
#include <queue>
using namespace std;

//Construct BST from Array Helper
BinaryTreeNode<int>* constructBSTHelper(int *arr, int si, int ei){
    
    if(si > ei){
        return NULL;
    }

    int mid = (si + ei)/2;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(arr[mid]);

    BinaryTreeNode<int>* leftTree = constructBSTHelper(arr, si, mid - 1);
    BinaryTreeNode<int>* rightTree = constructBSTHelper(arr, mid + 1, ei);

    root->left = leftTree;
    root->right = rightTree;
    return root;
}

//BST From Sorted Array
BinaryTreeNode<int>* constructBST(int *arr, int size){
    
    int si = 0;
    int ei = size - 1;
    return constructBSTHelper(arr, si, ei);
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

void preOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

// 1 2 3 4 5 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
    int size;
    cin >> size;
    int* input = new int[size];

    for (int i = 0; i < size; i++) cin >> input[i];

    BinaryTreeNode<int>* root = constructBST(input, size);
    preOrder(root);
    delete[] input;
}
