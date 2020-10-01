//
//  02. Linked Lists
//      04. Sum two Lists
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// You have two numbers represented by a linked list, where each node
// contains a single digit. The digits are stores in reverse order, such that
// the 1st digit is at the head of the list. This is a function that
// adds the two numbers and returns the sum as a linked list

// EXAMPLE:
// Input: (7->1->6) + (5->9->2). That is 617 + 295
// Output: 2->1->9. That is, 912

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
// We just traverse both lists while adding their
// values, we add a carry number when needed, we create
// two nodes for the result, on pointing at the beggining
// and another one at the end, then we just start adding the same
// of the digits to the end and return the beggining of our
// result
template <typename T>
class Solution{
public:
    Node<T> *addTwoLists(Node<T> *head1, Node<T> *head2){
        Node<T> *result = NULL;
        Node<T> *resultEnd = NULL;
        
        int carry = 0;
        while (head1 || head2){
            int value1 = (head1 ? head1->data : 0);
            int value2 = (head2 ? head2->data : 0);
            
            int sum = value1 + value2 + carry;
            carry = sum / 10;
            int digit = sum % 10;
            
            Node<T> *node = new Node<T>;
            node -> data = digit;
            if (result == NULL){
                result = node;
                resultEnd = result;
            }
            else{
                resultEnd->next = node;
                resultEnd = node;
            }
            
            if (head1){
                head1 = head1->next;
            }
            if (head2){
                head2 = head2->next;
            }
            node = node->next;
        }
        
        if (carry > 0){
            Node<T> *extra = new Node<T>;
            extra -> data = 1;
            resultEnd->next = extra;
        }
        
        return result;
    }
};

int main(){
    List<int> list1;
    List<int> list2;
    Solution<int> solution;
    
    list1.addEnd(9);
    list1.addEnd(1);
    list1.addEnd(8);
    
    list2.addEnd(5);
    list2.addEnd(9);
    list2.addEnd(6);
    
    auto Sum = solution.addTwoLists(list1.head, list2.head);
    
    cout << "The new list is: " << endl;
    while(Sum->next){
        cout << Sum->data << " -> ";
        Sum = Sum->next;
    }
    cout <<Sum->data << endl;
 
    return 0;
}
