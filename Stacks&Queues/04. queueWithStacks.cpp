//
//  03. Stacks & Queues
//      04. Queue via Stacks
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Implement a Queue class wich implements a
// queue using two stacks

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

using namespace std;

class MyQueue{
public:
    stack<int> stackNewest, stackOldest;
    
    MyQueue(){
        
    }
    
    void push(int value){
        stackNewest.push(value);
    }
    
    int pop(){
        if (empty()){
            return NULL;
        }
        shiftStacks();
        int value = stackOldest.top();
        stackOldest.pop();
        return value;
    }
    
    int peek(){
        if (empty()){
            return NULL;
        }
        shiftStacks();
        return stackOldest.top();
    }
    
    bool empty(){
        return (stackNewest.empty() && stackOldest.empty());
    }
    
    void shiftStacks(){
        if (stackOldest.empty()){
            while(!stackNewest.empty()){
                stackOldest.push(stackNewest.top());
                stackNewest.pop();
            }
        }
    }
};

int main(){

    MyQueue q;
    
    q.peek();
    q.pop();
    
    return 0;
}

