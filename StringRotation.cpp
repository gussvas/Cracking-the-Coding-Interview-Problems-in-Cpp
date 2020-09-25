//
//  01. Arrays and Strings
//      08. String Rotation
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given two strings, s1 and s2, write a code to check if s2
// is a rotation of s1

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

// Logic
// If we concatenate the first string
// with itself (duplicate it), then we just
// have to check wether the second string is
// in the new string (s1s1)

class Solution{
public:
    bool isRotation(string s1, string s2){
        if (s1.size() == s2.size() && s1.size() > 0){
            string s1s1 = s1 + s1;
            if (s1s1.find(s2) != string::npos){
                return true;
            }
        }
        return false;
    }
    
};

int main(){
    Solution solution;
    
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    
    cout << solution.isRotation(s1, s2) << endl;
    
    return 0;
}
