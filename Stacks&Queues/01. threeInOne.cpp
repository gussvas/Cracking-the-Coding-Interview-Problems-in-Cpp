//
//  03. Stacks & Queues
//      01. Three in One
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Describe how oyou could use a single array
// to implement three stacks

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

// Fixed Division Approach
// Divide the vector in three and allocate
// that space to each individual stack
class FixedMultiStack{
public:
    int numberOfStacks = 3;
    int stackCapacity;
    vector<int> values;
    vector<int> sizes;
    
    FixedMultiStack(int stackSize){
        stackCapacity = stackSize;
        values = vector<int>(stackSize*numberOfStacks);
        sizes = vector<int>(numberOfStacks);
    }
    
    // Pushing a value
    void push(int stackNum, int value){
        if (isFull(stackNum)){
            return;
        }
        sizes[stackNum]++;
        values[indexOfTop(stackNum)] = value;
        cout << "The value: " << value << " has been added to the stack number " << stackNum+1 << endl;
    }
    
    // Pop item
    void pop(int stackNum){
        if (isEmpty(stackNum)){
            return;
        }
        
        int topIndex = indexOfTop(stackNum);
        int value = values[topIndex]; // Get top
        values[topIndex] = 0; // clear
        sizes[stackNum]--; // shrink

    }
    
    //Return top element
    int top(int stackNum){
        if (isEmpty(stackNum)){
            return NULL;
        }
        int val = values[indexOfTop(stackNum)];
        cout << "The last value of the stack number " << stackNum+1 << " is: " << val << endl;
        return val;
    }
    
    // Return if stack is empty
    bool isEmpty(int stackNum){
        return (sizes[stackNum] == 0);
    }
    
    // Return if stack is full
    bool isFull(int stackNum){
        return (sizes[stackNum] == stackCapacity);
    }
    
    // Return index of the top of the stack
    int indexOfTop(int stackNum){
        int offset = stackNum * stackCapacity;
        int size = sizes[stackNum];
        return (offset+size)-1;
    }
};

int main(){
    FixedMultiStack stack(9);
    
    stack.push(1,1);
    stack.push(1,2);
    stack.push(0,3);
    stack.push(0,10);
    stack.push(2,20);
    stack.pop(1);
    stack.top(2);
    
    return 0;
}
