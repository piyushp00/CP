/*
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Note:
1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.
*/

/*
For a given a Binary Tree of type integer, duplicate every node of the tree and attach it 
to the left of itself.
The root will remain the same. So you just need to insert nodes in the given Binary Tree.
*/

#include <iostream>
#include "BinaryTreeNode.h"
#include "Node.h"
#include <vector>
#include <algorithm>
using namespace std;
#include <queue>

void convertToArray(BinaryTreeNode<int> *root, vector<int> &output){
    if (root == NULL){
        return;
    }

    output.push_back(root->data);
    convertToArray(root->left, output);
    convertToArray(root->right, output);
}

//Pair Sum Efficient Solution
void pairSum2(BinaryTreeNode<int> *root, int sum){
    vector<int> output;
    convertToArray(root, output);
    sort(output.begin(), output.end());
    int i = 0, j = output.size() - 1;
    while (i < j) {
        if (output[i] + output[j] == sum){
            cout << output[i] << " " << output[j] << "\n";
            ++i;
            --j;
        }
        else if (output[i] + output[j] > sum) {
            --j;
        } else {
            ++i;
        }
    }
}

//Pair Sum Binary Tree (Corect Soln but TLE in two cases)
void pairSum(BinaryTreeNode<int>* root, int s){
    if(root == NULL){
        return;
    }

    queue<BinaryTreeNode<int>*> pendingNodes;
    vector<int>* a;

    pendingNodes.push(root);
    a->push_back(root->data);

    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* frontNode = pendingNodes.front();
        pendingNodes.pop();

        if(frontNode->left != NULL){
            pendingNodes.push(frontNode->left);
            a->push_back(frontNode->left->data);
        }

        if(frontNode->right != NULL){
            pendingNodes.push(frontNode->right);
            a->push_back(frontNode->right->data);
        }
    }
    
    int n = a->size();

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a->at(i) + a->at(j) == s){
                if(a->at(i) < a->at(j)){
                    cout << a->at(i) << " " << a->at(j) << endl;
                } else {
                    cout << a->at(j) << " " << a->at(i) << endl;
                }
            }
        }
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
    int s;
    cin >> s;
    pairSum2(root, s);
    delete root;
    
}
