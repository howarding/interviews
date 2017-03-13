//Given two sparse matrices A and B, return the result of AB.
//
//You may assume that A's column number is equal to B's row number.
//
//Example:
//
//    A = [
//    [ 1, 0, 0],
//    [-1, 0, 3]
//    ]
//
//    B = [
//    [ 7, 0, 0 ],
//    [ 0, 0, 0 ],
//    [ 0, 0, 1 ]
//    ]
//
//
//         |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
//    AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
//                      | 0 0 1 |

#include <iostream>
#include <vector>

using namespace std;

class Solution_311 {
public:
    // Exp: https://discuss.leetcode.com/topic/30625/easiest-java-solution
    // Time:	O(mn)
    // Space:	O(mn)
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
        int m = A.size(), l = A[0].size(), n = B[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int k = 0; k < l; k++)
                if (A[i][k])
                    for (int j = 0; j < n; j++)
                        if (B[k][j])
                            result[i][j] += A[i][k] * B[k][j];
        return result;
    }
};