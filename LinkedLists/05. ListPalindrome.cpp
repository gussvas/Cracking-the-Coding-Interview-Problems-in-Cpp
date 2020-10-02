//
//  02. Linked Lists
//      05. Palindrome
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Implement a function to check if a linked list is
// a palindrome

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
// We will check if the first half of the linked list
// equals the second half in reverse
// We will use two approaches, by reversing and comparing
// and by using a stack
template <typename T>
class Solution{
public:
    // First approach
    // Reverse and compare
    // We will have three methods, the principal which returns the bool,
    // the one to reverse the list and the other one to compare the list and
    // its reversed version
    bool isPalindrome(Node<T> *head){
        auto reverseList = reverseandClone(head);
        return isEqual(head, reverseList);
    }
    
    // Method to reverse the linked list
    Node<T>* reverseandClone(Node<T> *head){
        Node<T> *node = NULL;
        while (head){
            Node<T> *temp = new Node<T>;
            int data = head->data;
            temp->data = data;
            temp->next = node;
            node = temp;
            head = head->next;
        }
        return node;
    }
    
    //Method to compare both lists
    bool isEqual(Node<T> *first, Node<T> *second){
        while (first && second){
            if (first->data != second->data){
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return (first == NULL && second == NULL);
    }
    
    // Second Approach
    // We use a stack to push the first half
    // of the list and then compare that stack
    // to the remaining half of the list
    bool isPalindromeScnd(Node<T> *head){
        Node<T> *fast = head;
        Node<T> *slow = head;
        
        stack<int> stack;
        
        // Push first half into stack and move
        // the fast pointer to the beggining of the
        // second half
        while (fast && fast->next){
            int value = slow->data;
            stack.push(value);
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // If the number of elements is odd we'll
        // skip the middle element
        if (fast){
            slow = slow->next;
        }
        
        while (slow){
            int top = stack.top();
            stack.pop();
            
            // We compare the stack (first half) with
            // the second half of the list
            if (top != slow->data){
                return false;
            }
            slow = slow->next;
        }
        return true;
    }
};

int main(){
    
    Solution<int> solution;
    List<int> list;
    
    list.addEnd(2);
    list.addEnd(3);
    list.addEnd(9);
    list.addBeggining(2);
    list.addBeggining(3);
    list.addBeggining(9);
    
    // Add extra element in the middle to make the size odd
    list.insert(4,3);
    
    cout << "First approach says: " << solution.isPalindrome(list.head) << endl;
    
    cout << "Second approach says: " << solution.isPalindromeScnd(list.head) << endl;
 
    return 0;
}
