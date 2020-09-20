//
//  01. Arrays and Strings
//      02. Is Permutation
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given two strings, write a method to decide if one is a
// permutation of the other

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
public:
    // Method that sorts the string in
    // alphabetical (ASCII value) order
    string sort(string s){
        ::sort(s.begin(),s.end());
        return s;
    }
    
    // Method that will return the bool value wether
    // string1 is a permutation of string2
    // Approach 1. Sorting
    bool isPermutation(string s1, string s2){
        if (s1.size()!=s2.size()){
            return false;
        }
        return (sort(s1) == sort(s2));
    }
    
    // Method that will return the bool value wether
    // string1 is a permutation of string2
    // Approach 2. Character count
    bool isPermutationTwo(string s1, string s2){
        if (s1.size() != s2.size()){
            return false;
        }
        
        int letters [128];
        // Initialize the Letters array values to 0
        for (int i = 0; i < 128; i++){
            letters[i] = 0;
        }
        
        char string [s1.size()+1];
        strcpy(string, s1.c_str());
        for (int i = 0; i < s1.size(); i++){
            // Add 1 to the ASCII value of the string's letter at position i
            letters[string[i]]++;
        }
        
        for (int i = 0; i < s2.size(); i++){
            int c = (int) s2[i];
            letters[c]--;
            if (letters[c] < 0){
                return false;
            }
        }
        // If both strings are a permutation of each other
        // that means that the letters array values must be
        // 0 at the end of the cycle
        return true;
    }
};

int main(){
    
    Solution solution;
    
    string p1 = "cat";
    string p2 = "taco";
    
    cout << solution.isPermutation(p1, p2) << endl;
    cout << solution.isPermutationTwo(p1, p2) << endl;
    
    return 0;
}

