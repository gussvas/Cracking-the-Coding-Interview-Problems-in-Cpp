//
//  01. Arrays and Strings
//      05. One Away
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// There are three types of edits that can be performed
// on strings: insert a character, remove a character or replace
// a character. Given two strings, write a function to check if they
// are one edit (or zero edits) away

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
    // Method to check wether we have to compare based on the
    // difference of sizes in both strings if they have a difference
    // in one character (same size) or they have one character more or less
    // (difference of size in 1)
    bool oneEditAway (string first, string second){
          if (first.size() == second.size()){
              return oneEditReplace(first, second);
          }
          else if (first.size()+1 == second.size()){
              return oneEditInsert(first, second);
          }
          else if (first.size()-1 == second.size()){
              return oneEditInsert(second, first);
          }
          return false;
      }
      
    // If both strings have the same size they should
    // only have a difference of a character
      bool oneEditReplace(string s1, string s2){
          bool difference = false;
          for (int i = 0; i < s1.size(); i++){
              if (s1[i] != s2[i]){
                  if (difference){
                      return false;
                  }
                  difference = true;
              }
          }
          return true;
      }
      
    // If they strigns have a difference of size of 1
    // they should have one extra character or one
    // missing character
      bool oneEditInsert (string s1, string s2){
          int index1 = 0;
          int index2 = 0;
          while (index1 < s1.size() && index2 < s2.size()){
              if (s1[index1] != s2[index2]){
                  if (index1 != index2){
                      return false;
                  }
                  index2++;
              }
              else {
                  index1++;
                  index2++;
              }
          }
          return true;
      }
};

int main(){
    
    Solution solution;
    
    string s1 = "Doctor";
    string s2 = "Doctors";
    
    cout << solution.oneEditAway(s1, s2);
    
    return 0;
}
