/* For a given preorder and inorder traversal of a Binary Tree 
of type integer stored in an array/list, create the binary 
tree using the given two arrays/lists. You just need to 
construct the tree and return the root.

Note:Assume that the Binary Tree contains only unique elements.  */
/* 
Code : Height of Binary Tree
For a given Binary Tree of integers, find and return the height of the tree. 
*/

#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;
#include <queue>

BinaryTreeNode<int> *buildTreeHelper(int *preOrder, int preStart, int preEnd, int *inOrder, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) {
        return NULL;
    }

    int rootVal = preOrder[preStart];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootVal);

    int inOrderRootIndex = 0;
    for (int i = inStart; i <= inEnd; i++) {
        if (inOrder[i] == rootVal) {
            inOrderRootIndex = i;
            break;
        }
    }

    int inOrderLeftLength = inOrderRootIndex - inStart;
    int preOrderLeftEnd = (preStart + 1) + inOrderLeftLength - 1;

    root->left = buildTreeHelper(preOrder, preStart + 1, preOrderLeftEnd, inOrder, inStart, inOrderRootIndex - 1);
    root->right = buildTreeHelper(preOrder, preOrderLeftEnd + 1, preEnd, inOrder, inOrderRootIndex + 1, inEnd);

    return root;
}

BinaryTreeNode<int>* buildTree(int *preOrder, int preLength, int *inOrder, int inLength) {
    int preStart = 0;
    int preEnd = preLength - 1;
    int inStart = 0;
    int inEnd = inLength - 1;

    return buildTreeHelper(preOrder, preStart, preEnd, inOrder, inStart, inEnd);
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
    //BinaryTreeNode<int> *root = takeInputLevelWise();
    //printTreeLevelWise(root);
    
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *newRoot = buildTree(pre, size, in, size);
    printTreeLevelWise(newRoot);

    delete newRoot;
}