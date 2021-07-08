/*
Largest BST-->
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST 
with maximum height in the given binary tree. You have to return the height of 
largest BST.
*/

#include <iostream>
#include "BinaryTreeNode.h"
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

//Height Of Largest BST SubTree
class bstSubtreeReturn {
public:
    int max;
    int min;
    int height;
    bool isBST;
};

bstSubtreeReturn largestBSTSubtreeHelper(BinaryTreeNode<int> *root){
    if (root == NULL){
        bstSubtreeReturn ans;
        ans.max = INT_MIN;
        ans.min = INT_MAX;
        ans.isBST = true;
        ans.height = 0;
        return ans;
    }

    bstSubtreeReturn left = largestBSTSubtreeHelper(root->left);
    bstSubtreeReturn right = largestBSTSubtreeHelper(root->right);

    if (!(right.isBST && right.min > root->data)){
        right.isBST = false;
    }
    if (!(left.isBST && left.max < root->data)){
        left.isBST = false;
    }

    bstSubtreeReturn ans;
    if (!left.isBST || !right.isBST || root->data < left.max || root->data > right.min){
        if (left.height > right.height){
            left.isBST = false;
            return left;
        }
        else{
            right.isBST = false;
            return right;
        }
    }

    ans.isBST = true;
    ans.min = min(left.min, min(right.min, root->data));
    ans.max = max(left.max, max(right.max, root->data));
    ans.height = max(left.height, right.height) + 1;
    return ans;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) { 
    return largestBSTSubtreeHelper(root).height; 
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
    cout << largestBSTSubtree(root);
    delete root;
}
