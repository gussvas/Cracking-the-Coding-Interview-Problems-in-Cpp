//
//  03. Stacks & Queues
//      05. Sort Stack
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Implement a method to sort a stack
// such that smallest items are on top. You can only
// use an additional temporary stack

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
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
public:
    void sortStack(stack<int>& s){
        stack<int> r;
        while (!s.empty()){
            int temp = s.top();
            s.pop();
            while (!r.empty() && r.top() > temp){
                s.push(r.top());
                r.pop();
            }
            r.push(temp);
        }
        
        while(!r.empty()){
            s.push(r.top());
            r.pop();
        }
    }
};

int main(){
    Solution sol;
    stack<int> s;
    s.push(2);
    s.push(6);
    s.push(8);
    s.push(10);
    s.push(4);
    
    sol.sortStack(s);

    return 0;
}

