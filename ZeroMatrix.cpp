//
//  01. Arrays and Strings
//      07. Zero Matrix
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Write an algorithm such that if an element in an
// MXN matrix is 0, its entire row and column are set to 0

// Example:
// 3 4 5 2 0
// 1 2 3 4 5
// 4 2 8 0 2
// Output:
// 0 0 0 0 0
// 1 2 3 0 0
// 0 0 0 0 0

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
    // Method that sets the entire row and column to 0
    // if an element of value 0 is found
    void setZeros(vector<vector<int>> &M){
        bool row[M.size()];
        bool column[M[0].size()];
        
        // Initialize both arrays to false
        for (int i = 0; i < M.size(); i++){
            row[i] = false;
        }
        for (int i = 0; i < M[0].size(); i++){
            column[i] = false;
        }
        
        // Set to true the values of the arrays where
        // the value in the matrix is 0
        for (int i = 0; i < M.size(); i++){
            for (int j = 0; j < M[0].size(); j++){
                if (M[i][j] == 0){
                    row[i] = true;
                    column[j] = true;
                }
            }
        }
        
        // Set to 0 the rows with a value of 0
        for (int i = 0; i < M.size(); i++){
            if (row[i]){
                setRowtoZero(M, i);
            }
        }
        
        // Set to 0 the columns with a value of 0
        for (int i = 0; i < M[0].size(); i++){
            if (column[i]){
                setColumntoZero(M, i);
            }
        }
    }
    
    // Method that sets the values of the row to 0
    void setRowtoZero(vector<vector<int>> &M, int row){
        for (int i = 0; i < M[0].size(); i++){
            M[row][i] = 0;
        }
    }

    // Method that sets the values of the column to 0
    void setColumntoZero(vector<vector<int>> &M, int column){
        for (int i = 0; i < M.size(); i++){
            M[i][column] = 0;
        }
    }
};

int main(){
    Solution solution;
    
    int row, col;
    vector<vector<int>> Matrix;
    cin >> row >> col;
    
    for (int i = 0; i < row; i++){
        vector<int> v;
        for (int j = 0; j < col; j++){
            int k;
            cin >> k;
            v.push_back(k);
        }
        Matrix.push_back(v);
    }
    
    solution.setZeros(Matrix);
    
    // Print new matrix
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout << Matrix[i][j] << "  ";
        }
        cout << endl;
    }
    
    return 0;
}
