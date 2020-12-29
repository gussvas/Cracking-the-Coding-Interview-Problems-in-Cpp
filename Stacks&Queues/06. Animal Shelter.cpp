//
//  03. Stacks & Queues
//      06. Animal Shelter
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// People must adopt the oldest (based on arrival time) of
// all animals of the shelter, they can also select if they would
// prefer a dog or a cat. Create the data structure to maintain this
// system implementing enqueue, dequeueAny, dequeueDog and
// dequeueCat.

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

// Create the animal class that will contain the
// order each animal came to the shelter, their type
// (Dog or Cat) and their name
class Animal{
public:
    int order;
    string type;
    string name;
    Animal(){ }
    Animal(string n, string t){
        name = n;
        type = t;
    }
    
    void setOrder(int ord){
        order = ord;
    }
    
    int getOrder(){
        return order;
    }
    
    bool isOlderThan(Animal a){
        return order < a.getOrder();
    }
};

class AnimalQueue{
public:
    list<Animal> dogs;
    list<Animal> cats;
    int order = 0; // acts as timestamp
    
    // Push any animal into the queue
    void enqueue(Animal a){
        a.setOrder(order);
        order++;
        if (a.type == "Dog"){
            dogs.push_back(a);
        }
        else{
            cats.push_back(a);
        }
    }
    
    // Dequeue the older animal (smaller order)
    Animal dequeueAny(){
        if (dogs.size() == 0){
            return dequeueCat();
        }
        else if (cats.size() == 0){
            return dequeueDog();
        }
        Animal a1 = dogs.front();
        Animal a2 = cats.front();
        if (a1.isOlderThan(a2)){
            dogs.pop_front();
            return a1;
        }
        else{
            cats.pop_front();
            return a2;
        }
    }
    
    // Dequeue the older cat (front of the list)
    Animal dequeueCat(){
        if (cats.empty()){
            throw invalid_argument("The list is empty");
        }
        Animal cat = cats.front();
        cats.pop_front();
        return cat;
    }
    
    // Dequeue the older god (front of the list)
    Animal dequeueDog(){
        if (dogs.empty()){
            throw invalid_argument("The list is empty");
        }
        Animal dog = dogs.front();
        dogs.pop_front();
        return dog;
    }
};

int main(){
    AnimalQueue q;
    
    Animal d1("James", "Dog");
    Animal d2("Jordan", "Dog");
    Animal c1("Louis", "Cat");
    Animal d3("Jessi", "Dog");
    Animal c2("Kate", "Cat");
    
    q.enqueue(d1);
    q.enqueue(d2);
    q.enqueue(c1);
    q.enqueue(d3);
    q.enqueue(c2);
    q.dequeueCat();
    q.dequeueDog();
    q.dequeueAny();

    return 0;
}

