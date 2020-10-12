//
//  04. Trees and Graphs
//      10. Check Subtree
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// T1 and T2 are two very large binary trees, with T1 much bigger
// than T2. Create an algorithm to determine if T2 is a subtree of T1

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
// We just construct and compare the pre-order
// traversals of both trees
template <typename T>
class Solution{
public:
    
    bool containsTree(Node<T> *root1, Node<T> *root2){
        stringstream string1;
        stringstream string2;
        
        getOrderString(root1, string1);
        getOrderString(root2, string2);
        
        string s1 = string1.str();
        string s2 = string2.str();
        
        return (s1.find(s2) != std::string::npos);
    }
    
    void getOrderString(Node<T> *root, stringstream &s){
        if (!root){
            s << "X";
            return;
        }
        // Add node
        s << root->data;
        getOrderString(root->left, s);
        getOrderString(root->right, s);
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
    
    BSTree<int> tree2;
    
    tree2.insert(10);
    tree2.insert(5);
    tree2.insert(15);
    
    cout << solution.containsTree(tree.root, tree2.root) << endl;

   
    
    return 0;
}

