//
//  04. Trees and Graphs
//      04. Check Balanced
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Function that checks if a binary tree is balanced. Meaning,
// the heights of the two subtrees of any node never differ
// by more than one

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
// We just need to recurse through the entire tree,
// and for each node compute the heights
template <typename T>
class Solution{
public:
    int getHeight(Node<T> *root){
        // Base case
        if (!root){
            return -1;
        }
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    
    bool isBalanced(Node<T> *root){
        // base case
        if (!root){
            return true;
        }
        
        int difference = getHeight(root->left) - getHeight(root->right);
        // Tree is not balanced
        if (abs(difference) > 1){
            return false;
        }
        // Else recurse
        else{
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }
    
    // Optimization in order to cut out some
    // of the calls to getHeight method
    
    int checkHeight(Node<T> *root){
        if (!root){
            return -1;
        }
        
        int leftHeight = checkHeight(root->left);
        if (leftHeight == INT_MIN) {
            return INT_MIN;
        }
        
        int rightHeight = checkHeight(root->right);
        if (rightHeight == INT_MIN){
            return INT_MIN;
        }
        
        int difference = leftHeight - rightHeight;
        if (abs(difference) > 1){
            return INT_MIN;
        }
        else{
            return max(leftHeight,rightHeight) + 1;
        }
    }
    
    bool isBalancedOp(Node<T> *root){
        return checkHeight(root) != INT_MIN;
    }
};

int main(){
    Solution<int> solution;
    BSTree<int> tree;
    
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);
    
    //
    //tree.insert(8);
    //tree.insert(9);
    
    cout << solution.isBalanced(tree.root) << endl;
    
    cout << solution.isBalancedOp(tree.root) << endl;
    
    return 0;
}

