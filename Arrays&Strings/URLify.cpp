//
//  01. Arrays and Strings
//      03. URLify
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Method to replace all spaces in a string with %20

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
    void URLify (string s){
        int spaceCount = 0;
        long index = 0;
        
        //Count the number of spaces
        for (int i = 0; i<s.size(); i++){
            if (s[i] == ' '){
                spaceCount++;
            }
        }
        
        // New length of the string given n spaces
        // Because %20 takes two extra spaces
        index = s.size() + (spaceCount*2);
        string result[index];
        
        for (long i = s.size()-1; i>= 0; i--){
            if (s[i] == ' '){
                // Insert the %20 instead of the space
                result[index - 1] = '0';
                result[index - 2] = '2';
                result[index - 3] = '%';
                index -= 3;
            }
            else{
                result[index-1] = s[i];
                index--;
            }
        }
        
        // Print result
        for (int i = 0; i < s.size() + (spaceCount*2); i++){
            cout << result[i];
        }
        cout << endl;
    }
    
};

int main(){
    
    Solution solution;
    
    string s = "Dear Doctor John Smith I appreciate you a lot";
    
    solution.URLify(s);
    
    return 0;
}





