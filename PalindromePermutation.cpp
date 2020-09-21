
//  01. Arrays and Strings
//      04. Palindrome Permutation
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given a string, write a function to check if it is
// a permutation of a palindrome. A palindrome is a word or phrase
// that is the same forwards and backwards.

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


// Logic:
// A string permutation will contain a
// palindrome if it has an even number of
// letters and in case, just one odd number
// of a letter

class Solution{
public:
    
    // This function maps the int char values
    // to a map and the count for every char
    unordered_map<int, int> createMap(string s){
        unordered_map<int, int> map;
        ::transform(s.begin(), s.end(), s.begin(), ::toupper);
        for (int i = 0; i < s.size(); i++){
            if (s[i] != ' '){
                map[(int)s[i]]++;
            }
        }
        return map;
    }
    
    // This function checks the logic of the
    // problem and returns false wether there is
    // more than one odd count of a character
    bool isPalindrome(string s){
        unordered_map<int, int> stringMap = createMap(s);
        
        bool foundOdd = false;
        for (auto i : stringMap){
            if (i.second % 2 == 1){
                if (foundOdd){
                    return false;
                }
                    foundOdd = true;
            }
        }
        return true;
    }
};

int main(){
    
    Solution solution;
    
    string s = "Anita lava la tina";
    
    cout << solution.isPalindrome(s) << endl;
    
    return 0;
}
