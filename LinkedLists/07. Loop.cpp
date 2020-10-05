//
//  02. Linked Lists
//      07. Loop Detection
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given a circular linked list, the algorithm returns the node
// at the beginning of the loop
// EXAMPLE
// Input: A -> B -> C -> D -> E -> F
// Output: C

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
#include "/Users/alexvasquez/Pictures/Temp LinkedLists/LinkedList.h"

using namespace std;

// Logic:
// If we have a loop, we will use a slow and a fast pointer,
// once they both enter the loop they will eventually meet,
// at the meeting point, we will intialize our slow pointer to the
// beginning of the list and keep the fast one at the meeting point, we then
// will move both of them at the same speed (1) and they will meet
// at the beginning of the loop (2k - k) steps
template <typename T>
class Solution{
public:
    
    Node<T>* findLoop(Node<T> *head){
        Node<T> *slow = head;
        Node<T> *fast = head;
        
        // We will make sure we are in a loop
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            // meeting point
            if(slow == fast){
                break;
            }
        }
        
        // there was no luup
        if (!fast || !fast->next){
            return NULL;
        }
        
        slow = head;
        // move until they both meet at the beginning
        while (slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        // return either slow or fast (they are the same)
        return fast;
    }
};

int main(){
    
    return 0;
}


