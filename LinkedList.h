//
//  Linked List Template
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// This is a template for the creation of a linked list
// and its simple methods such as insert, remove, print, etc

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <iostream>

using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node<T> *next = nullptr;
};

template <typename T>
class List{
public:
    Node<T> *head, *tail;
    
    List(){
        head = NULL;
    }
    
    ~List(){
        Node<T> *node = new Node<T>;
        while (node != NULL){
                head = head->next;
                delete node;
                node = head;
        }
    }
    
    // Method that returns wether a linked list
    // is empty or not
    bool isEmpty(){
        return !head;
    }
    
    // Method that returns the size (as an integer)
    // of the linked list (number of nodes)
     int size() {
           int count = 0;
           auto actual = head;
           while(actual) {
               count++;
               actual = actual->next;
           }
           return count;
       }
    
    // Method that inserts a new node
    // to the beggining of the list
    void addBeggining(T data){
        auto node = new Node<T>;
        node->data = data;
        node->next = head;
        head = node;
    }
    
    // Method that inserts a new node
    // to the end of the list
    void addEnd(T data){
        if (isEmpty()){
            head = new Node <T>;
            head->data = data;
            return;
        }
        auto actual = head;
        while (actual->next != nullptr){
            actual = actual->next;
        }
        auto newNode = new Node<T>;
        newNode->data = data;
        actual->next = newNode;
    }
    
    // Method that inserts a new node
    // to the linked list in n position
    void insert(T data, int position){
        if (isEmpty()){
            head = new Node<T>;
            head->data = data;
            return;
        }
        
        if (position == 0){
            addBeggining(data);
            return;
        }
        
        if (position >= size()){
            addEnd(data);
            return;
        }
        
        auto newNode = new Node<T>;
        auto actual = head;
        int count = 0;
        while (count < position-1){
            actual = actual->next;
            count++;
        }
        newNode->data = data;
        newNode->next = actual->next;
        actual->next = newNode;
    }
    
    // Method that removes the beggining node
    // of the linked list
    T removeBeggining(){
        if (isEmpty()){
            return T();
        }
        auto oldHead = head;
        auto result = oldHead->data;
        head = oldHead->next;
        delete oldHead;
        return result;
    }
    
    // Method that temoves the end node
    // of the linked list
    T removeEnd(){
        if(isEmpty()){
            return T();
        }
        if (!head->next){
            auto oldHead = head;
            head = nullptr;
            auto value = head->data;
            delete oldHead;
            return value;
        }
        auto actual = head;
        while (actual->next->next != nullptr){
            actual = actual->next;
        }
        auto beforelast = actual;
        auto last = beforelast->next;
        beforelast->next = nullptr;
        auto value = last->data;
        delete last;
        return value;
    }
    
    // Method that removes a node
    // from the linked list given n position
    T remove(int position){
        if (isEmpty()){
            return T();
        }
        if (position == 0){
            removeBeggining();
        }
        
        int count = 0;
        auto actual = head;
        while(count < position-1){
            actual = actual->next;
            count++;
        }
        auto previous = actual;
        auto toRemove = actual->next;
        previous->next = toRemove->next;
        auto value = toRemove->data;
        delete toRemove;
        return value;
    }
    
    // Method that prints the values of the
    // linked list starting from the head node
    void print(){
        auto actual = head;
        while (actual){
            cout << "Value: " << actual->data << endl;
            actual = actual->next;
        }
    }
    
    // Method that searches for the value
    // of a node given n position
    T search(int position){
        if (isEmpty()){
            return T();
        }
        
        if (position < 0){
            position = 0;
        }
        int t = size();
        if (position > t){
            position = t-1;
        }
        int count = 0;
        auto actual = head;
        while (count < position-1){
            actual = actual->next;
            count++;
        }
        auto node = actual->next;
        return node->data;
    }
    
    // Method that reverses the linked list
    // making the head node the last node
    void reverse(){
        if (isEmpty()){
            return;
        }
        if (head->next == nullptr){
            return;
        }
        auto p = head;
        auto c = p->next;
        while(c){
            auto n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        head = p;
    }
};

#endif

