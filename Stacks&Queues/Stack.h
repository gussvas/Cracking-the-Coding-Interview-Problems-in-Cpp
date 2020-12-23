//
//  Stack Implementation Template
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// This is a template for the creation of a stack
// and some of its most used methods

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>

using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node<T>* next;
    Node(T data) : data(data), next(NULL) {
        
    }
};

template <typename T>
class Stack{
public:
    Node<T>* top;
    
    T pop(){
        if (!top){
            return NULL;
        }
        
        T item = top->data;
        top = top->next;
        return item;
    }
    
    void push(T item){
        Node<T> t = new Node<T>(item);
        t->next = top;
        top = t;
    }
    
    T getTop(){
        if (!top){
            return NULL;
        }
        return top->data;
    }
    
    bool isEmpty(){
        return (top == NULL);
    }
};

#endif

