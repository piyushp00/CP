/* For a given postorder and inorder traversal of a Binary Tree of type integer 
stored in an array/list, create the binary tree using the given two arrays/lists.
You just need to construct the tree and return the root.

Note:Assume that the Binary Tree contains only unique elements.  */


#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;
#include <queue>

BinaryTreeNode<int> *buildTreeHelper(int *postOrder, int postStart, int postEnd, int *inOrder, int inStart, int inEnd) {
    if (postStart > postEnd || inStart > inEnd) {
        return NULL;
    }

    int rootVal = postOrder[postEnd];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootVal);

    int inOrderRootIndex = 0;
    for (int i = inStart; i <= inEnd; i++) {
        if (inOrder[i] == rootVal) {
            inOrderRootIndex = i;
            break;
        }
    }

    int inOrderLeftLength = inOrderRootIndex - inStart;
    int postOrderLeftEnd = postStart + inOrderLeftLength - 1;

    root->left = buildTreeHelper(postOrder, postStart, postOrderLeftEnd, inOrder, inStart, inOrderRootIndex - 1);
    root->right = buildTreeHelper(postOrder, postOrderLeftEnd + 1, postEnd - 1, inOrder, inOrderRootIndex + 1, inEnd);

    return root;
}

BinaryTreeNode<int>* buildTree(int *postOrder, int postLength, int *inOrder, int inLength) {
    int postStart = 0;
    int postEnd = postLength - 1;
    int inStart = 0;
    int inEnd = inLength - 1;

    return buildTreeHelper(postOrder, postStart, postEnd, inOrder, inStart, inEnd);
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
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *newRoot = buildTree(post, size, in, size);
    printTreeLevelWise(newRoot);

    delete newRoot;
}