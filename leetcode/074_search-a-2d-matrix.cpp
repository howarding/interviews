//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//    Integers in each row are sorted from left to right.
//    The first integer of each row is greater than the last integer of the previous row.
//
//For example,
//
//    Consider the following matrix:
//
//    [
//        [1,   3,  5,  7],
//        [10, 11, 16, 20],
//        [23, 30, 34, 50]
//    ]
//
//Given target = 3, return true.

#include <iostream>
#include <vector>

using namespace std;

class Solution_074 {
public:
    // Exp: https://discuss.leetcode.com/topic/4846/binary-search-on-an-ordered-matrix
    // Time:	O(log(n))
    // Space:	O(1)
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int i = mid / n;
            int j = mid % n;
            int val = matrix[i][j];
            if (target == val)
                return true;
            else if (target < val)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};