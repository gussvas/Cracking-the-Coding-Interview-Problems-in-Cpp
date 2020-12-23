//
//  02. Linked Lists
//      01. Sum Lists II
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Code to add two linked lists in reverse order

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

// Include path of the LinkedList.h file containing the template for a linked list
#include "/Users/alexvasquez/Cracking-the-Coding-Interview-Problems-in-Cpp/LinkedLists/LinkedList.h"

using namespace std;

template <typename T>
class Solution {
public:
    
    Node<T>* addTwoNumbers(Node<T>* l1, Node<T>* l2) {
        int size1 = getSize(l1);
        int size2 = getSize(l2);
        
        if (size1 < size2){
            l1 = padList(l1, size2 - size1);
        }else{
            l2 = padList(l2, size1-size2);
        }
        
        pair<Node<T>*, int> sum = addListHelper(l1,l2);
        if (sum.second == 0){
            return sum.first;
        }
        else{
            Node<T>* r = insertBefore(sum.first, sum.second);
            return r;
        }
    }
    
    pair<Node<T>*,int> addListHelper(Node<T>* l1, Node<T>* l2){
        if (!l1 && !l2){
            pair<Node<T>*,int> sum = {NULL,0};
            return sum;
        }
        
        pair<Node<T>*,int> sum = addListHelper(l1->next,l2->next);
        int val = sum.second + l1->data + l2->data;
        
        Node<T>* result = insertBefore(sum.first, val%10);
        
        sum.first = result;
        sum.second = val/10;
        return sum;
    }
    
    int getSize (Node<T>* head){
        int size = 0;
        while(head){
            size++;
            head = head->next;
        }
        return size;
    }
    
    Node<T>* padList(Node<T>* head, int padding){
        Node<T>* node = head;
        for (int i = 0; i < padding; i++){
            node = insertBefore(node,0);
        }
        return node;
    }
    
    Node<T>* insertBefore(Node<T>* head, int val){
        Node<T>* node = new Node<T>;
        node->data = val;
        if(head){
            node->next = head;
        }
        return node;
    }
};

int main(){
    List<int> list1;
    List<int> list2;
    Solution<int> solution;
    
    list1.addBeggining(6);
    list1.addBeggining(1);
    list1.addBeggining(9);
    
    list2.addBeggining(0);

    
    solution.addTwoNumbers(list1.head, list2.head);
    
    return 0;
}

