//
//  Queue Implementation Template
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// This is a template for the creation of a queue
// and some of its most used methods

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
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
class Queue{
public:
    Node<T> first;
    Node<T> last;
    
    void add(T item){
        Node<T> t = new Node<T>(item);
        if (last){
            last->next = t;
        }
        last = t;
        if (!first){
            first = last;
        }
    }
    
    T front(){
        if (!first){
            return NULL;
        }
        T data = first->data;
        return data;
    }
    
    void pop(){
        if (!first){
            return;
        }
        first = first->next;
        if (!first){
            last = NULL;
        }
    }
    
    bool isEmpty(){
        return (first == NULL);
    }
};

#endif

