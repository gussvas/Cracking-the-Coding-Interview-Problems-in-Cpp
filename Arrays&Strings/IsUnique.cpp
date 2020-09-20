//
//  01. Arrays and Strings
//      01. Is Unique
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?

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
    bool isUnique(string str){
        // There are 128 ASCII characters
        if (str.size() > 128) return false;
        
        bool chars [128];
        // Initialize chars array with false values to avoid
        // false true values
        for (int i = 0; i<128; i++){
            chars[i] = false;
        }
        
        for (int i = 0; i<str.size(); i++){
            int value = str[i];
            if (chars[value]){ // Already found this char in string
                return false;
            }
            chars[value] = true;
        }
        return true;
    }
};

int main(){
    
    Solution solution;
    
    string temp1 = "Doctor";
    string temp2 = "Glass";
    string temp3 = "Flask";
    string temp4 = "Curtains";
    
    cout << solution.isUnique(temp1) << endl;
    cout << solution.isUnique(temp2) << endl;
    cout << solution.isUnique(temp3) << endl;
    cout << solution.isUnique(temp4) << endl;
    
    return 0;
}




