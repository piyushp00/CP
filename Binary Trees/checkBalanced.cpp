/* 
Given a binary tree, check if it is balanced. 
Return true if given binary tree is balanced, 
false otherwise.
*/

#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;
#include <queue>

// Alternate Solution
int height(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

//Balanced Binary Tree (approch 1- not efficient)
bool isBalanced(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return true;
    }

    bool leftTree = isBalanced(root->left);
    bool rightTree = isBalanced(root->right);
    
    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh - rh) <= 1 && leftTree == true && rightTree == true){
        return true;
    } else {
        return false;
    }
}

//Approach 2 (efficent)
pair<int, bool> isBalancedHelper(BinaryTreeNode<int>* root) {
    pair<int, bool> ans;
    if(root == NULL){
        ans.first = 0;
        ans.second = true;
        return ans;
    }

    pair<int, bool> leftAns = isBalancedHelper(root->left);
    pair<int, bool> rightAns = isBalancedHelper(root->right);

    int lh = leftAns.first;
    int rh = rightAns.first;

    if(abs(lh - rh) > 1 || !(leftAns.second) || !(rightAns.second)) {
        ans.first = 1 + max(lh, rh);
        ans.second = false;
    } else {
        ans.first = 1 + max(lh, rh);
        ans.second = true;
    }

    return ans;
}

bool isBalancedBetter(BinaryTreeNode<int>* root){
    if(root == NULL){
        return true;
    }
    pair<int, bool> ans = isBalancedHelper(root);
    return ans.second;
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
    cout << isBalancedBetter(root) << endl;
    delete root;
}