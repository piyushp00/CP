#include "BinaryTreeNode.h"
#include <iostream>
#include <climits>

class BST{
    BinaryTreeNode<int>* root;

public:

    //Constructor
    BST(){
        root = NULL;
    }
    
    //Destructor
    ~BST(){
        delete root;
    }

BinaryTreeNode<int>* minimum(BinaryTreeNode<int>* node){
    if(node == NULL){
        return node; 
    }

    BinaryTreeNode<int>* min = node;
    if(node->data > INT_MAX){
    
    }
}

private:
    BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node){
        if(node == NULL){
            return NULL;
        }

        if(node->data < data){
            node->right = deleteData(data, node->right);
        } else if(node->data > data) {
            node->left = deleteData(data, node->left);
        } else {
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            } else if(node->left == NULL) {
                BinaryTreeNode<int>* newRoot = node->right;
                node->right = NULL;
                delete node;
                return newRoot;
            } else if(node->right == NULL){
                BinaryTreeNode<int>* newRoot = node->left;
                node->left = NULL;
                delete node;
                return newRoot;
            } else {
                BinaryTreeNode<int>* minNode=node->right;
                while(minNode->left !=NULL) {
                    minNode=minNode->left;
                }

                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(rightMin, node->right);
                return node;
            }
        } 
    }
    
public:
    //Delete
    void deleteData(int data){
        this->root = deleteData(data, this->root);
    }

private:
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node){
        if(node == NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }

        BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);

        if(data < node->data)  {
           node->left = insert(data, root->left);
        } else {
            node->right= insert(data, root->right);
        }
        return node;
    }

public:
    //Insert
    void insert(int data){
       this->root = insert(data, this->root);
    }

private:
    bool hasData(int data, BinaryTreeNode<int>* node){
        
        if(node == NULL){
            return false;
        }

        if(node->data == data){
            return true;
        } else if(data < node->data){
            return hasData(data, node->left);
        } else {
            return hasData(data, node->right);
        }
    }

public:
    //Has Data or Not
    bool hasData(int data){
        return hasData(data, root);
    }
};