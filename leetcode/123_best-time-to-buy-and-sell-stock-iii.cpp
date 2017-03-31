//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit. You may complete at most two transactions.
//
//Note:
//    You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

#include <iostream>
#include <vector>

using namespace std;

class Solution_123 {
public:
    // DP
    // Exp: https://discuss.leetcode.com/topic/5934/is-it-best-solution-with-o-n-o-1/54
    // Time:	O(n)
    // Space:	O(1)
    int maxProfit(vector<int> &prices) {    // 股票1做法的拓展， 求两次峰值即可
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int prof1 = 0, prof2 = 0;
        for (int price : prices) {
            buy1 = min(buy1, price);
            prof1 = max(prof1, price - buy1);
            buy2 = min(buy2, price - prof1);
            prof2 = max(prof2, price - buy2);
        }
        return prof2;
    }
};