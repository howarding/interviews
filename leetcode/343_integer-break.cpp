//Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
//
//For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
//
//Note: You may assume that n is not less than 2 and not larger than 58.

#include <iostream>
#include <vector>

using namespace std;

class Solution_343 {
public:
    // DP (My own)
    // Time:	O(n)
    // Space:	O(n)
    int integerBreak(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; i++)
            for (int j = i - 1; j >= 0; j--)
                dp[i] = max(dp[i], max(dp[j], j + 1) * max(dp[i - j - 1], i - j));
        return dp[n - 1];
    }
};