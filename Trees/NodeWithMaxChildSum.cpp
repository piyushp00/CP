/* 
Given a generic tree, find and return the node for which sum of its 
data and data of all its child nodes is maximum. In the sum, data 
of the node and data of its immediate child nodes has to be taken.
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

//Node with Maximum Child Sum
TreeNode<int>* getNodeMaxChild(TreeNode<int>* root){

    if(root == NULL){
        return NULL;
    }
    
    TreeNode<int>* ans = root;
    int childSum = 0;
    for(int i = 0; i < root->children.size(); i++){
        childSum = childSum + root->children[i]->data;
    }
    int sum = root->data + childSum;
    
    

    for(int i = 0; i < root->children.size(); i++){
        TreeNode<int>* locAns =  getNodeMaxChild(root->children[i]);
        int currSum = 0;
        for(int j = 0; j < locAns->children.size(); j++){
            currSum = currSum + locAns->children[j]->data;
        }
        int locSum = currSum + locAns->data;
        if(locSum > sum){
            sum = locSum;
            ans = locAns;
        } 
    }
    return ans;
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
    

TreeNode<int>* ans =  getNodeMaxChild(root);
cout << ans->data << endl;
}
