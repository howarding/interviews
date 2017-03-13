//Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
//For example, given the following matrix:
//
//    1 0 1 0 0
//    1 0 1 1 1
//    1 1 1 1 1
//    1 0 0 1 0
//Return 4.

#include <iostream>
#include <vector>

using namespace std;

class Solution_221 {
public:
    // 2D DP, use 1 vector.
    // Exp: https://discuss.leetcode.com/topic/15328/easy-dp-solution-in-c-with-detailed-explanations-8ms-o-n-2-time-and-o-n-space
    // Time:	O(mn)
    // Space:	O(n)
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n, 0);
        int result = 0;
        for (int j = 0; j < n; j++) {
            dp[j] = matrix[0][j] - '0';
            result = max(result, dp[j]);
        }

        for (int i = 1; i < m; i++) {
            int pre = dp[0];
            dp[0] = matrix[i][0] - '0';
            result = max(result, dp[0]);
            for (int j = 1; j < n; j++) {
                int tmp = dp[j];
                dp[j] = matrix[i][j] == '0' ? 0 : min(dp[j], min(dp[j - 1], pre)) + 1;
                pre = tmp;
                result = max(result, dp[j]);
            }
        }
        return result * result;
    }
};


//int main() {
//    vector<vector<char>> matrix(
//        {{'1','0','1','0','0'},
//         {'1','0','1','1','1'},
//         {'1','1','1','1','1'},
//         {'1','0','0','1','0'}});
//    Solution_221 sol;
//    cout << sol.maximalSquare(matrix) << endl;
//}