#include <iostream>
#include "TreeNodeClass.h"
#include <queue>
using namespace std;

//max data node
TreeNode<int>* maxDataNode(TreeNode<int>* root){
    if(root == NULL){
        return NULL;
    }

    TreeNode<int>* max = root;
    for(int i = 0; i < root->children.size(); i++){
        TreeNode<int>* locMax = maxDataNode(root->children[i]);
        
        if(max->data < locMax->data){
            max = locMax;
        }
    }
    return max;
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
    root = maxDataNode(root);
    cout << root->data << endl;
}