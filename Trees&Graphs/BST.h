//
//  Binary Search Tree Template
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// This is a template for the creation of a BST
// and some methods such as

#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include <iostream>

using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;
};

template <typename T>
class BSTree{
public:
    Node<T>* root = nullptr;
    
    BSTree(){
        root = NULL;
    }
    
    ~BSTree(){
        delete root;
    }
    
    // Method to insert a node in the BST
    void insert(T data){
        if(!root){
            root = new Node<T>;
            root->data = data;
            return;
        }
        insertTree(root, data);
    }
    
    // Method to search for a value in the BST
    bool search(T data){
        return searchTree(root, data);
    }
    
    // Method to print the BST (preorder)
    void print(){
        return printTree(root);
    }
    
    // Method to invert the BST
    void invert(){
        return invertTree(root);
    }
    
    // Method to remove a node
    void removeNode(T data){
        removeTree(root, data);
    }
    
    // Method to find minimum value
    T findMin(){
        return findMinTree(root)->data;
    }
    
    // Method to find max value
    T findMax(){
        return findMaxTree(root)->data;
    }
    
private:
    // Method to insert a node using recursion
    void insertTree(Node<T>* root, T data){
        if (root->data == data){
            return;
        }
        if (data < root->data){
            if(!root->left){
                root->left = new Node<T>;
                root->left->data = data;
                return;
            }
            else
                insertTree(root->left, data);
        }
        else {
            if (!root -> right){
                root->right = new Node<T>;
                root->right->data = data;
                return;
            }
            else
                insertTree(root->right, data);
        }
    }
    
    // Method to search for a node using
    // recursion
    bool searchTree(Node<T>* root, T data){
        if(!root){
            cout << "Value was not found" << endl;
            return false;
        }
        if (root->data == data){
            cout << "Value was found" << endl;
            return true;
        }
        if (data < root->data){
            return searchTree(root->left,data);
        }
        else
            return searchTree(root->right,data);
    }
    
    // Method to print the BST (preorder)
    void printTree(Node<T>* root){
        if (root != NULL){
            cout << root->data << endl;
            printTree(root->left);
            printTree(root->right);
        }
    }
    
    // Method to find the minimun value of a BST
    Node<T>* findMinTree(Node<T>* root){
           if (root->left == NULL){
               return root;
           }
           else{
               return findMinTree(root->left);
           }
       }
       
    // Method to find the maximum value of a BST
       Node<T>* findMaxTree(Node<T>* root){
           if (root->right == NULL){
               return root;
           }
           else{
               return findMaxTree(root->right);
           }
       }
    
    // Method to invert the BST
    void invertTree(Node<T>* root){
        if (!root){
            return;
        }
        invertTree(root->left);
        invertTree(root->right);
        
        auto node = new Node<T>;
        node = root->left;
        root->left = root->right;
        root->right = node;
    }
    
    // Method to remove a node using 3 scenarios,
    // a node with no children, a node with one child
    // or a node with two children, where we must replace
    // the current value with our minimum value
    Node<T>* removeTree(Node<T>* root, T data){
        if(!root){
            return root;
        }
        else if (data < root->data){
            root->left = removeTree (root->left, data);
        }
        else if(data > root->data){
            root->right = removeTree (root->right, data);
        }
        else {
            // Case 1: No children
            if (root->left == NULL && root->right == NULL){
                delete root;
                root = NULL;
            }
            // Case 2: One child
            else if (root -> left == NULL){
                auto node = new Node<T>;
                node = root->right;
                delete root;
                return node;
            }
            else if (root -> right == NULL){
                auto node = new Node<T>;
                node = root->left;
                delete root;
                return node;
            }
            // Case 3: 2 Children
            else{
                auto node = new Node<T>;
                node = findMinTree(root->right);
                root->data = node->data;
                root->right = removeTree(root->right,node->data);
            }
        }
     return root;
    }
};

#endif

