/* Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). 
If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree. */
 

#include <iostream>
#include "BinaryTreeNode.h"
#include "Node.h"
#include <vector>
#include <climits>
using namespace std;
#include <queue>

//Alternalte Solutions
bool isBST2(BinaryTreeNode<int> *root,int min=INT_MIN,int max=INT_MAX){

    //Base Case   
    if(root == NULL) {
        return true;
    }

    //Small Calculation
    if(root->data < min || root->data > max) {
        return false;
    }

    //Recursion Call
    bool leftAns = isBST2(root->left, min, root->data);
    bool rightAns = isBST2(root->right, root->data, max);

    return leftAns && rightAns;
}

//Check BST Helper (not efficient- O(n*h))
bool isBSTHelper(BinaryTreeNode<int>* root, int min, int max){
    
    //Base Case
    if(root == NULL){
        return true;
    }

    //Small Calculation
    if(root->data < min || root->data > max){
        return false;
    }

    //Recursion Call
    bool leftAns = isBSTHelper(root->left, min, root->data);
    bool rightAns = isBSTHelper(root->right, root->data, max);
    
    return leftAns & rightAns;
}

//Check BST
bool isBST(BinaryTreeNode<int>* root){
    return isBSTHelper(root, INT_MIN, INT_MAX);
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
    
    cout << ((isBST(root)) ? "true" : "false");
    delete root;
}
