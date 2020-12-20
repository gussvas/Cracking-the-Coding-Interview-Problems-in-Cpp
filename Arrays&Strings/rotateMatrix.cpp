//
//  01. Arrays and Strings
//      08. Rotate Matrix
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Write an algorithm that rotates a squared matrix
// by 90 degrees

// Example:
// 1 2 3
// 4 5 6
// 7 8 9
// Output:
// 7 4 1
// 8 5 2
// 9 6 3

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
    
    // the approach is to save the corner values and start
    // changing them, by storing a first value and just start
    // changing the four corners
    // From the outer layer to the inside
    bool rotateMatrix(vector<vector<int>>& matrix){
        
        if (matrix.size() == 0 || matrix.size() != matrix[0].size()){
            return false;
        }
        
        int n = matrix.size();
        for (int layer = 0; layer < n/2; layer++){
            int first = layer;
            int last = n - 1 - layer;
            
            for (int i = first; i < last; i++){
                int offset = i - first;
                int top = matrix[first][i]; // save top
                // left->top
                matrix[first][i] = matrix[last-offset][first];
                
                // bottom->left
                matrix[last-offset][first] = matrix[last][last-offset];
                
                // right->bottom
                matrix[last][last-offset] = matrix[i][last];
                
                // top->right
                matrix[i][last] = top;
            }
        }
        
        return true;
    }
    
};

int main(){
    Solution solution;
    
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    solution.rotateMatrix(matrix);
    
    return 0;
}

