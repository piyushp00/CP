/*
Find the diameter of binary tree.
*/

#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include <cmath>

using namespace std;


int heightOfTree(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }

    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}

//Binary Tree Diameter (O(n*h) - two times height is getting called)
//Not efficient solution
int diameterOfTree(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    int option1 = heightOfTree(root->left) + heightOfTree(root->right);
    int option2 = diameterOfTree(root->left);
    int option3 = diameterOfTree(root->right);

    return max(option1, max(option2, option3));
}

//Efficient Solutions (O(n))
pair<int, int> heightDiameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int lh = leftAns.first; //left height
    int ld = leftAns.second; //left diameter
    int rh = rightAns.first; //right height
    int rd = rightAns.second; // right diameter

    int height = 1 + max(lh, rh); //height of the tree
    int diameter = max(lh + rh, max(ld, rd)); //overall diameter

    pair<int, int> p;
    p.first = height;
    p.second = diameter;

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
    
    pair<int, int> p = heightDiameter(root);
    cout << "Height: " << p.first << endl;
    cout << "Diameter: " << p.second << endl;

    delete root;
}