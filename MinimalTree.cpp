//
//  04. Trees and Graphs
//      02. Minimal Tree
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given a sorted (increasing order) array with unique elements, write
// an algorithm to create a binary search tree with minimal height

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
// We will insert the middle element of the array, then insert
// the left subarray and then the right by recursing
template <typename T>
class Solution{
public:
    Node<int>* createMinimal(vector<int> v, int start, int end){
        if (end < start){
            return NULL;
        }
        
        int mid = (start + end)/2;
        Node<int> *node = new Node<T>;
        node->data = v[mid];
        // We start inserting on the left side
        node->left = createMinimal(v, start, mid-1);
        // We start inserting on the right side
        node->right = createMinimal(v,mid+1,end);
        return node;
    }
    
    Node<int>* createMinimalBST(vector<int> v){
        return createMinimal(v, 0, v.size() -1);
    }
};

int main(){
    Solution<int> solution;
    BSTree<int> tree;
    
    vector<int> vec = {1,2,3,4,5,6,7,8};
    Node<int> *minimalTree = solution.createMinimalBST(vec);
    
    return 0;
}

