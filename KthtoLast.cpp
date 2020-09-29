//
//  02. Linked Lists
//      02. Return Kth to Last
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Algorithm that finds the kth to last
// element of a singly linked list

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


template <typename T>
class Solution{
public:
    // Iterative solution
    // We use two pointers, we move the first one n
    // positions, once we get there we start moving the other
    // one, once the first one reaches the end of the list it means
    // that the second one is in the Kth to last position
    Node<T> *KthtoLast(Node<T> *head, int k){
        auto p1 = new Node<T>;
        auto p2 = new Node<T>;
        p1 = head;
        p2 = head;
        
        for (int i = 0; i < k; i++){
            if (!p1){
                return NULL;
            }
            p1 = p1->next;
        }
        
        while (p1->next){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
    
    //Recursive solution
    // We use recursion to get to the end
    // of the list and start traversing it
    // backward until we reach the n position (kth)
    Node<T> *KthtoLastRec(Node<T> *head, int k){
        static int i = 0;
        if (!head->next){
            return NULL;
        }
        auto node = KthtoLastRec(head->next, k);
        i++;
        if (i == k){
            return head;
        }
        return node;
    }
};

int main(){
    List<int> list;
    Solution<int> solution;
    
    list.addEnd(30);
    list.addBeggining(20);
    list.addBeggining(10);
    list.addEnd(10);
    list.addEnd(100);
    list.insert(50, 2);
    
    list.print();
    cout << endl;
    
    auto Kth = new Node<int>;
    Kth = solution.KthtoLast(list.head, 3);
    cout << "Iterative solution says: " << Kth->data << endl;
    
    auto KthRec = new Node<int>;
    KthRec = solution.KthtoLastRec(list.head, 3);
    cout << "Recursive solution says: " << KthRec->data << endl;
 
    return 0;
}
