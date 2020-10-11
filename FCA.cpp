//
//  04. Trees and Graphs
//      08. First Common Ancestor
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Algorithm that finds the first common ancestor of two
// nodes in a binary tree. Avoid using additional data structures

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <list>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

// Include path of the BST.h file containing the template for a Binary Search Tree
#include "BST.h"

using namespace std;

// Logic:
// If p and q are on the same left side, we will branch left and look for
// the common ancestor. If they are on the same right side we will branc right. When
// p and q are no longer on the same side, you must have found the first common ancestor
template <typename T>
class Solution{
public:
    
    // Method to check if the nodes are
    // in the tree
    bool covers(Node<T> *root, Node<T> *p){
        if (!root){
            return false;
        }
        if (root == p){
            return true;
        }
        return covers(root->left, p) || covers(root->right, p);
    }
    
    // Method to get the first common ancestor of
    // both nodes
    Node<T>* ancestorHelper(Node<T> *root, Node<T> *p, Node<T> *q){
        if (!root || root == p || root == q){
            return root;
        }
        
        bool pOnLeft = covers(root->left, p);
        bool qOnLeft = covers(root->left, q);
        // Nodes are on different size
        if (pOnLeft != qOnLeft){
            return root;
        }
        Node<T> *childSide = pOnLeft ? root->left : root->right;
        return ancestorHelper(childSide, p, q);
    }
    
    // Method to get the first common ancestor
    Node<T>* commonAncestor(Node<T> *root, Node<T> *p, Node<T> *q){
        // Error check
        if (!covers(root,p) || !covers(root,q)){
            return NULL;
        }
        
        return ancestorHelper(root,p,q);
    }
};

int main(){
    Solution<int> solution;
    BSTree<int> tree;
    
    tree.insert(30);
    tree.insert(20);
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(17);
    tree.insert(7);
    tree.insert(3);
    tree.insert(40);
    tree.insert(35);
    tree.insert(50);
    

    Node<int> *ancestor = solution.commonAncestor(tree.root, tree.root->right->left, tree.root->right->right);
    
    return 0;
}


