/* 
Given a tree and an integer x, find and return the number 
of nodes which contains data greater than x. 
*/

#include <iostream>
#include <queue>
#include "TreeNodeClass.h"
using namespace std;

//Greater than x
int greaterThanX(TreeNode<int>* root, int x){
    
    int count = 0;
    if(root->data > x){
        count++;
    }

    for(int  i = 0; i < root->children.size(); i++){
        count  = count + greaterThanX(root->children[i], x);
    }
    return count;
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
    TreeNode<int>* root = takeInputLevelWise() ;
    printLevelWise(root);
    //TODO delete
    int n;
    cin >> n;

    cout << greaterThanX(root, n) << endl;
}
