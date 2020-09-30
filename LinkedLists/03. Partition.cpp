//
//  02. Linked Lists
//      03. Partition
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Code that partitions a linked list around a value x,
// such that all nodes less than x come before all nodes greater
// or equal to x.

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
// We will use two lists, in first one we will
// insert the elements smaller than x and on the second
// one the elements greater than x, after finishing we will
// "connect" the end of the first list to the beggining
// of the second one to get a unique list
template <typename T>
class Solution{
public:
    Node<T> *partition(Node<T> *head, int x){
        // We will use 4 pointers
        // 2 for the first list (pointing beggining and end)
        // 2 for the second list (pointing beggining and end)
        Node<T> *FirstBeggining = NULL;
        Node<T> *FirstEnd = NULL;
        Node<T> *SecondBeggining = NULL;
        Node<T> *SecondEnd = NULL;
        
        while (head){
            Node<T> *next = head->next;
            head->next = NULL;
            // Element smaller than the partition element
            if (head -> data < x){
                // We initialize our first list
                if (FirstBeggining == NULL){
                    FirstBeggining = head;
                    FirstEnd = FirstBeggining;
                }
                // We already have elements in the first list
                else{
                    FirstEnd->next = head;
                    FirstEnd = head;
                }
            }
            // Element greater than the partition element
            else{
                // We initialize our second list
                if (SecondBeggining == NULL){
                    SecondBeggining = head;
                    SecondEnd = SecondBeggining;
                }
                // We already have elements in the second list
                else{
                    SecondEnd->next = head;
                    SecondEnd = head;
                }
            }
            head = next;
        }
        
        // We only have greater elements than the pivot, hence
        // we only return the second list
        if (!FirstBeggining){
            return SecondBeggining;
        }
        
        // We have both smaller and greater elements
        FirstEnd->next = SecondBeggining;
        return FirstBeggining;
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
    
    auto partitionList = new Node<int>;
    partitionList = solution.partition(list.head, 20);
    
    while(partitionList){
        cout << "Value: " << partitionList->data << endl;
        partitionList = partitionList->next;
    }
 
    return 0;
}

