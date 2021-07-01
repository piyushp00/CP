/*
//LEVEL WISE LINKED LIST
Given a binary tree, write code to create a separate linked list for each level. 
You need to return the array which contains head of each level linked list.
*/

#include <iostream>
#include "BinaryTreeNode.h"
#include "Node.h"
#include <vector>
using namespace std;
#include <queue>

//Level Wise Linked List
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int>* root){
    vector<Node<int>*> arr;

    if(root == NULL){
        return arr;
    }

    Node<int>* head = NULL;
    Node<int>* tail =  NULL;

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while(!pendingNodes.empty()){

        if(pendingNodes.front() == NULL){
            arr.push_back(head);
            pendingNodes.pop();

            if(pendingNodes.empty()){
                break;
            }
            pendingNodes.push(NULL);
            head = NULL;
            tail =  NULL;

        } else {

            BinaryTreeNode<int>* frontNode = pendingNodes.front();
            pendingNodes.pop();
            Node<int>* n = new Node<int>(frontNode->data);
            if(head == NULL){
                head = n;
                tail = n;
            } else {
                tail->next = n;
                tail = tail->next;
            }

            if(frontNode->left != NULL){
                pendingNodes.push(frontNode->left);
            }

            if(frontNode->right != NULL){
                pendingNodes.push(frontNode->right);
            }
            
        }
    }
    return arr;
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


void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// 1 2 3 4 5 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int> *root = takeInputLevelWise();
    
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
    
}


    
    

