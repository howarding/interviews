//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//    Integers in each row are sorted in ascending from left to right.
//    Integers in each column are sorted in ascending from top to bottom.
//
//For example,
//
//    Consider the following matrix:
//
//    [
//        [1,   4,  7, 11, 15],
//        [2,   5,  8, 12, 19],
//        [3,   6,  9, 16, 22],
//        [10, 13, 14, 17, 24],
//        [18, 21, 23, 26, 30]
//    ]
//Given target = 5, return true.
//
//Given target = 20, return false.

#include <iostream>
#include <vector>

using namespace std;

class Solution_240 {
public:
    // Exp: https://leetcode.com/problems/search-a-2d-matrix-ii/
    // Time:	O(m + n)
    // Space:	O(1)
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            int ele = matrix[i][j];
            if (ele == target) return true;
            if (ele < target) i++;
            else j--;
        }
        return false;
    }
};