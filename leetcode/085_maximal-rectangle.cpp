//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
//For example, given the following matrix:
//
//    1 0 1 0 0
//    1 0 1 1 1
//    1 1 1 1 1
//    1 0 0 1 0
//Return 6.

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution_085 {
public:
    // DP, stack
    // Exp: https://discuss.leetcode.com/topic/1634/a-o-n-2-solution-based-on-largest-rectangle-in-histogram
    // Time:	O(mn)
    // Space:	O(n)
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty()) return 0;
        int result = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n + 1, 0);

        for (int i = 0; i < m; i++) {
            stack<int> stk;
            for (int j = 0; j < n + 1; j++) {
                if (j < n)
                    height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
                while (!stk.empty() && height[j] < height[stk.top()]) {
                    int top = stk.top();
                    stk.pop();
                    int area = height[top] * (stk.empty() ? j : (j - stk.top() - 1));
                    result = max(result, area);
                }
                stk.push(j);
            }
        }
        return result;
    }
};