// Given two generic trees, return true if they are structurally 
// identical. Otherwise return false.

#include <iostream>
#include <queue>
#include "TreeNodeClass.h"
using namespace std;

//Structurally Identical
bool areIdentical(TreeNode<int>* root1, TreeNode<int>* root2){
   if(root1 == NULL && root2 == NULL){
        return true;
    }
    
    if(root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL){
        return false;
    }

    if(root1->data != root2->data || root1->children.size() != root2->children.size()){
        return false;
    }
	
    for(int i = 0; i < root1->children.size(); i++){
        bool ans = areIdentical(root1->children[i], root2->children[i]);
        if(!ans){
            return false;
        }
    }
    return true;
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

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main() {
    TreeNode<int>* root1 = takeInputLevelWise() ;
    TreeNode<int>* root2 = takeInputLevelWise() ;
    printLevelWise(root1);
    printLevelWise(root2);
    
    cout << areIdentical(root1, root2) << endl;
    delete root1;
    delete root2;
}
