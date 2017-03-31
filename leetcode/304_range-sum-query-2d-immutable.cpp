//Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
//
//Range Sum Query 2D
//The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.
//
//Example:
//    Given matrix = [
//        [3, 0, 1, 4, 2],
//        [5, 6, 3, 2, 1],
//        [1, 2, 0, 1, 5],
//        [4, 1, 0, 1, 7],
//        [1, 0, 3, 0, 5]
//    ]
//
//    sumRegion(2, 1, 4, 3) -> 8
//    sumRegion(1, 1, 2, 2) -> 11
//    sumRegion(1, 2, 2, 4) -> 12
//Note:
//    1. You may assume that the matrix does not change.
//    2. There are many calls to sumRegion function.
//    3. You may assume that row1 ≤ row2 and col1 ≤ col2.

#include <iostream>
#include <vector>

using namespace std;

// 2D DP matrix
// Time:	O(1)
// Space:	O(mn)
class NumMatrix {
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> pre(n, 0);
        for (vector<int> &row : matrix) {
            int total = 0;
            for (int j = 0; j < n; j++) {
                total += row[j];
                pre[j] += total;
            }
            sums.push_back(pre);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (sums.empty()) return 0;
        if (!row1 && !col1) return sums[row2][col2];
        if (!row1) return sums[row2][col2] - sums[row2][col1 - 1];
        if (!col1) return sums[row2][col2] - sums[row1 - 1][col2];
        return sums[row2][col2] - sums[row2][col1 - 1] - sums[row1 - 1][col2] + sums[row1 - 1][col1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */