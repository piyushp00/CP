/* Given a generic tree, count and return the number 
of leaf nodes present in the given tree. */

#include <iostream>
#include <queue>
#include "TreeNodeClass.h"
using namespace std;

//Count Leaf Nodes
int numLeafNodes(TreeNode<int> * root){
    //Edge Case
    if(root == NULL){
        return 0;
    }

    if(root->children.size() == 0){
        return 1;
    }

    int num = 0;
    for(int i = 0; i < root->children.size(); i++){
        num = num +  numLeafNodes(root->children[i]);
    }
    return num;
}



//Take Input LevelWise
TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter Root Data: " << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData); 

    //Make Queue
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
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
    return root;
}

//Print Level Wise
void printLevelWise(TreeNode<int>* root){
    if(root == NULL){
        return;
    }

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ": ";
        int i;
        for(i = 0; i < front->children.size(); i++){
            cout << front->children[i]->data;
            if(i != front->children.size() - 1){
                cout << ", ";
            }
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

int main() {
    TreeNode<int>* root = takeInputLevelWise() ;
    printLevelWise(root);
    //TODO delete
    int n = numLeafNodes(root);
    cout << n << endl;
}
