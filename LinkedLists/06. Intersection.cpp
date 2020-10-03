//
//  02. Linked Lists
//      06. Intersection
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given two singly linked lists, determine if the two lists
// intersect. Return the insersecting node.

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
// If we have one list longer than the other one,
// we first will get the Kth node from the start of
// the larger list and equal its length to the lenth of the
// shorter list, after that we just traverse both until
// we found the node they are sharing and return it, by
// definition we have an intersection when we merge the two
// lists into one at some point
template <typename T>
class Solution{
public:
    class Result{
    public:
        Node<T> *tail;
        int size;
    };
    
    // Method that returns the direction of the
    // last node of each list and their size (n of nodes)
    Result getTail(Node<T> *head){
        if (!head){
            return NULL;
        }
        int size = 1;
        Node<T> *current = head;
        
        while(current->next){
            size++;
            current = current->next;
        }
        return new Result(current,size);
    }
    
    // Method that sets the beggining of the longer list
    // to the kth position
    Node<T> *equalSize(Node<T> *head, int k){
        Node<T>* current = head;
        while (k>0 && current){
            current = current->next;
            k--;
        }
        return current;
    }
    
    // Method that returns the node where both
    // lists intersect
    Node<T> *findIntersection(Node<T> *h1, Node<T> *h2){
        Result tail1 = getTail(h1);
        Result tail2 = getTail(h2);
        
        // If the tails are not equal then we have no intersection
        if(tail1->tail != tail2->tail){
            return NULL;
        }
        
        Node<T> *shorter = tail1->size < tail2->size ? h1 : h2;
        Node<T> *longer = tail1->size < tail2->size ? h2 : h1;
        
        // We set the beggining of longer to the equal length of the shorter list
        longer = equalSize(longer, abs(tail1->size - tail2->size));
        
        // We move every list until they intersect
        while (shorter!=longer){
            shorter = shorter->next;
            longer = longer->next;
        }
        return longer;
    }
    
};

int main(){
    
    return 0;
}
