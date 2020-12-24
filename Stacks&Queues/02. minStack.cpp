//
//  03. Stacks & Queues
//      02. StackMin
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Design a stack, which, in addition to push and pop, has a function
// which returns the minimum element? They should all operate in O(1) time

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

// We will use an additional stack which
// keepts track of the mins
class StackMin{
public:
    vector<int> stack;
    vector<int> stackMin;
    
    StackMin(){
        
    }
    
    void push(int value){
        if (stackMin.empty() || value <= stackMin.back()){
            stackMin.push_back(value);
        }
        stack.push_back(value);
    }
    
    void pop(){
        if (stack.back() == stackMin.back()){
            stackMin.pop_back();
        }
        stack.pop_back();
    }
    
    int top(){
        return stack.back();
    }
    
    int getMin(){
        return stackMin.back();
    }
};

int main(){
    StackMin s;
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(2);
    s.pop();
    s.pop();
    s.push(1);
    
    return 0;
}

