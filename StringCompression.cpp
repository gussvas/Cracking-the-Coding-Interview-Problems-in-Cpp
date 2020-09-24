//
//  01. Arrays and Strings
//      06. String Compression
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Method that performs basic string compression using the counts
// of repeated characters. For example, the string aabccccaaa would
// become a2b1c5a3

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
    
    string compressString(string s){
        stringstream ss;
        int count = 0;
        for (int i = 0; i < s.size(); i++){
            count++;
            
            // If the next character is different than the current one
            if (i+1 >= s.size() || s[i] != s[i+1]){
                ss << s[i];
                ss << count;
                count = 0;
            }
        }
        return ss.str();
    }
};

int main(){
    
    Solution solution;
    
    string s = "aaabbbbbcdeefff";
    
    cout << solution.compressString(s) << endl;
    
    return 0;
}
