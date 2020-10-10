//
//  04. Trees and Graphs
//      05. Validate BST
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Function that checks if a binary tree is a BST

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
// We have different approahces, we can build an array by
// traversing the tree with inorder and later check if the array
// is sorted. However an optimal solution (with no extra space) is by
// using a range of values, where the nodes on the left cannot be less or greater
// than the range and the same on the right side
template <typename T>
class Solution{
public:

    bool check(Node<T> *root, int min, int max){
        if (!root){
            return true;
        }
        
        if ((min && root->data <= min) || (max && root->data > max)){
            return false;
        }
        
        if (!check(root->left, min, root->data) || !check(root->right, root->data, max)){
            return false;
        }
        return true;
    }
    
    bool checkBST(Node<T> *root){
        return check(root, NULL, NULL);
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
    
    cout << solution.checkBST(tree.root) << endl;
    
    return 0;
}

