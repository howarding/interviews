//You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
//
//Example 1:
//coins = [1, 2, 5], amount = 11
//return 3 (11 = 5 + 5 + 1)
//
//Example 2:
//coins = [2], amount = 3
//return -1.
//
//Note:
//You may assume that you have an infinite number of each kind of coin.

#include <iostream>
#include <vector>

using namespace std;

class Solution_322 {
public:
    // DP
    // Exp: https://discuss.leetcode.com/topic/32475/c-o-n-amount-time-o-amount-space-dp-solution
    // Time:	O(n * amount)
    // Space:	O(amount)
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty()) return -1;
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int value = 1; value <= amount; value++)
            for (int i = 0; i < coins.size(); i++)
                if (coins[i] <= value && dp[value - coins[i]] >= 0)
                    dp[value] = dp[value] == -1 ?
                                dp[value - coins[i]] + 1 :
                                min(dp[value], dp[value - coins[i]] + 1);
        return dp[amount];
    }


    // Recursion (My own)
    // TLE
    int coinChange1(vector<int>& coins, int amount) {
        if (coins.empty()) return -1;
        int result = INT_MAX;
        sort(coins.begin(), coins.end(), greater<int>());
        helper(coins, amount, 0, 0, result);
        return result == INT_MAX ? -1 : result;
    }

    void helper(vector<int>& coins, int remainder, int start, int count, int& result) {
        if (remainder == 0) {
            result = min(result, count);
            return;
        }
        for (int i = start; i < coins.size(); i++)
            if (remainder >= coins[i])
                helper(coins, remainder - coins[i], i, count+1, result);
    }
};


//int main() {
//    Solution_322 sol;
//    vector<int> coins({431,62,88,428});
//    int amount = 9084;
//    cout << sol.coinChange(coins, amount) << endl;
//}