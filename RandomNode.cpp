//
//  04. Trees and Graphs
//      11. Random Node
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Implementing a BST from scratch, you create a getRandomNode() method
// which returns a random node from the tree. All nodes should be equally likely
// to be chosen.

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
// The odds of going left should be LEFT_SIZE * 1/N
// Likewise the odds of going right should be RIGHT_SIZE * 1/N
// Since we are building the tree from scratch we can add a size
// count everytime we insert and remove a node

template <typename T>
class Solution{
public:
    private:
        int data;
        int size = 0;
    
    public:
        Node<T>* left;
        Node<T>* right;
        
        void insertInOrder(Node<T> *root, int d){
            if (d <= root->data){
                if (!root->left){
                    Node<T> *node;
                    node->data = d;
                    root->left = node;
                }
                else{
                    insertInOrder(root->left, d);
                }
            }
            else{
                if (!root->right){
                    Node<T> *node;
                    node->data = d;
                    root->right = node;
                }
                else{
                    insertInOrder(root->right, d);
                }
            }
            size++;
        }
        
        Node<T>* find(Node<T> *root, int d){
            if (d == root->data){
                return root;
            }
            else if (d <= root->data){
                return root->left ? find(root->left, d) : NULL;
            }
            else if (d > root->data){
                return root->right ? find(root->right, d) : NULL;
            }
            return NULL;
        }
        
        Node<T>* getRandomNode(Node<T>* root){
            int leftSize = !root->left ? 0 : root->left.size();
            int random = rand();
            int index = random.
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
    
    
    return 0;
}


