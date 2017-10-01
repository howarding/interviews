//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//
//Example 1:
//    Input: [7, 1, 5, 3, 6, 4]
//    Output: 5
//
//    max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
//Example 2:
//    Input: [7, 6, 4, 3, 1]
//    Output: 0
//
//    In this case, no transaction is done, i.e. max profit = 0.

#include <iostream>
#include <vector>

using namespace std;

class Solution_121 {
public:
    // Normal DP
    // Exp: https://discuss.leetcode.com/topic/5863/sharing-my-simple-and-clear-c-solution
    // Time:	O(n)
    // Space:	O(1)
    int maxProfit(vector<int> &prices) {
        int maxPro = 0, minPri = INT_MAX;
        for (int price : prices) {
            minPri = min(minPri, price);
            maxPro = max(maxPro, price - minPri);
        }
        return maxPro;
    }

    // 053: Maximum Subarray
    // Exp: https://discuss.leetcode.com/topic/19853/kadane-s-algorithm-since-no-one-has-mentioned-about-this-so-far-in-case-if-interviewer-twists-the-input
    // Time:	O(n)
    // Space:	O(1)
    int maxProfit_1(vector<int> &prices) {
        int local_max = 0, global_max = 0;
        for (int i = 1; i < prices.size(); i++) {
            local_max = max(local_max + prices[i] - prices[i - 1], 0);
            global_max = max(global_max, local_max);
        }
        return global_max;
    }
};