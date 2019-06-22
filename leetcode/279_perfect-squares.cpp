//Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
//
//For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

#include <iostream>
#include <vector>

using namespace std;

class Solution_279 {
public:
    // DP
    // Exp: https://discuss.leetcode.com/topic/24255/summary-of-4-different-solutions-bfs-dp-static-dp-and-mathematics
    // Time:	O(n^3/2)
    // Space:	O(n)
    int numSquares(int n) {
        if (n <= 0) return 0;
        // cntPerfectSquares[i]: the least # perfect square numbers which sum to i
        vector<int> cntPerfectSquares(n + 1, INT_MAX);
        cntPerfectSquares[0] = 0;
        for (int i = 1; i <= n; i++)
            // For each i, it must be the sum of some number (i-j*j) and
            // a perfect square number (j*j)
            for (int j = 1; j * j <= i; j++)
                cntPerfectSquares[i] = min(cntPerfectSquares[i], cntPerfectSquares[i - j * j] + 1);
        return cntPerfectSquares[n];
    }
};