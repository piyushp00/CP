#include <iostream>
#include "TreeNodeClass.h"
#include <queue>
using namespace std;

//Take Input LevelWise
TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter Root Data: " << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData); 

    //Make Queue
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(pendingNodes.size() == 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of childeren of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for(int i = 0; i < numChild; i++){
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
}

//Take Input
TreeNode<int>* takeInput(){
    int rootData;
    cout << "Enter Data: " << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter num of children of " << rootData << endl;
    cin >> n;
    for(int i = 0; i < n; i++){
       TreeNode<int>* child = takeInput();
       root->children.push_back(child);
    }
    return root;
}

//Print Tree
void printTree(TreeNode<int>* root) {
    //edge case(not base case)
    if(root == NULL){
        return;
    }

    cout << root->data << ":";
    for(int i = 0; i < root->children.size(); i++){
        cout << root->children[i]->data << ",";
    }
    cout << endl;

    for(int i = 0; i < root->children.size(); i++){
        printTree(root->children[i]);
    }
}

int main() {
    /* TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2); */

    TreeNode<int>* root = takeInput();
    printTree(root);
    //TODO delete
}