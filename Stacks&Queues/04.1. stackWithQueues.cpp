//
//  03. Stacks & Queues
//      04.1. Stack via Queues
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Implement a Stack class wich implements a
// stack using two queues

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

class MyStack{
public:
    queue<int> q1, q2;
    
    MyStack(){
        
    }
    
    void shiftToq2(){
        while (q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
    }
    
    void shiftToq1(){
        while (!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    void push(int value){
        q1.push(value);
    }
    
    int pop(){
        shiftToq2();
        int val = q1.front();
        q1.pop();
        shiftToq1();
        return val;
    }
    
    int top(){
        return q1.back();
    }
    
    bool empty(){
        return (q1.empty() && q2.empty());
    }
    
};

int main(){

    MyStack s;

    return 0;
}

