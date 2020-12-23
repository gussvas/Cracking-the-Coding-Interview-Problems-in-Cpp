//
//  02. Linked Lists
//      01. Remove Duplicates
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Code to remove duplicates from an
// unsorted linked list

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
#include "LinkedList.h"

using namespace std;


// Logic:
// We create a set where we store the values of each
// node, if we find a duplicate we proceed to eliminate that
// node, by positioning us in the node before the duplicate node and
// setting its next node to be the node following our duplicate and then
// deleting the duplicate
template <typename T>
class Solution{
public:
    
    Node<T>* removeDups(Node<T> *head){
        auto node = new Node<T>;
        node = head;
        unordered_set<T> set;
        
        while (node->next){
            set.insert(node->data);
            if (set.count(node->next->data)){
                node->next = node->next->next;
                continue;
            }
            node = node->next;
        }
        return head;
    }
};

int main(){
    List<int> list;
    Solution<int> solution;
    
    list.addBeggining(3);
    list.addBeggining(3);
    list.addBeggining(2);
    list.addBeggining(1);
    list.addBeggining(1);
    
    //Print before we eliminate the duplicate
    list.print();
    cout << endl;
    
    solution.removeDups(list.head);
    cout << endl;
    
    //Print after we eliminate the duplicate
    list.print();
    
    return 0;
}
