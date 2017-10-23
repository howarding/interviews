//Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
//
//Example:
//    Input:
//    [
//        [ 1, 2, 3 ],
//        [ 4, 5, 6 ],
//        [ 7, 8, 9 ]
//    ]
//    Output:  [1,2,4,7,5,3,6,8,9]
//    Explanation:
//
//Note:
//1. The total number of elements of the given matrix will not exceed 10,000.

#include <iostream>
#include <vector>

using namespace std;

class Solution_498 {
public:
    // Exp: https://discuss.leetcode.com/topic/77865/concise-java-solution
    // Time:	O(mn)
    // Space:	O(1)
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = 0, d = 1;
        for (int k = 0; k < m * n; k++) {
            result.push_back(matrix[i][j]);
            i -= d;
            j += d;
            if (i == m) {
                i = m - 1;
                j += 2;
                d *= -1;
            }
            if (j == n) {
                i += 2;
                j = n - 1;
                d *= -1;
            }
            if (i < 0) {
                i = 0;
                d *= -1;
            }
            if (j < 0) {
                j = 0;
                d *= -1;
            }

        }
        return result;
    }
};


//int main() {
//    Solution_498 sol;
//    vector<vector<int>> matrix({{1,2,3}, {4,5,6}, {7,8,9}});
//    vector<int> result(sol.findDiagonalOrder(matrix));
//    for (int num : result)
//        cout << num << "\t";
//}