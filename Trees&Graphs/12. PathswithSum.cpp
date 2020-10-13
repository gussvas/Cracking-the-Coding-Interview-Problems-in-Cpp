//
//  04. Trees and Graphs
//      12. Paths with Sum
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Algorithm that counts the number of paths
// that sum to a given value. The path must go downwards

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
// In this problem we won't use it since we are building the tree from scratch
#include "/Users/alexvasquez/Pictures/Temp Trees/BST.h"

using namespace std;

// Logic:
// We traverse through the tree using DFS. As we visit each node:
// We track its runningSum
// Look up runningSum - targetSum in the hash map, the value indicates the
// total number
// If runningSum == targetSum there is an additional path that starts at the root
// Add runningSum to the hash map
// Recurse left and right counting the number of paths
// After recursing document the value of RunningSum in the hash map

template <typename T>
class Solution{
public:
    
    int countPathswithSum(Node<T> *root, int targetSum){
        if (!root){
            return 0;
        }
        
        int pathsFromRoot = countPathsWithSumFromNode(root, targetSum, 0);
        
        int pathsLeft = countPathswithSum(root->left, targetSum);
        int pathsRight = countPathswithSum(root->right, targetSum);
        
        return pathsFromRoot + pathsLeft + pathsRight;
    }
    
    int countPathsWithSumFromNode(Node<T> *root, int targetSum, int currentSum){
        if (!root){
            return 0;
        }
        
        currentSum += root->data;
        int totalPaths = 0;
        
        if (currentSum == targetSum){
            totalPaths++;
        }
        
        totalPaths += countPathsWithSumFromNode(root->left, targetSum, currentSum);
        totalPaths += countPathsWithSumFromNode(root->right, targetSum, currentSum);
        return totalPaths;
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
    
    // 30 20 10 5 15 17 7 3 40 35 50
    // 15
    // 10 5
    // Should return 2
    
    int Paths = solution.countPathswithSum(tree.root, 15);
    cout << Paths << endl;
    
    return 0;
}

