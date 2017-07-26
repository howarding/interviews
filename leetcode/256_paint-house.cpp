//There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
//
//The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.
//
//Note:
//All costs are positive integers.

#include <iostream>
#include <vector>

using namespace std;

class Solution_256 {
public:
    // DP
    // Time:	O(n)
    // Space:	O(1)
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int n = costs[0].size();
        vector<int> pre(n, 0), cur(n, 0);
        for (auto&& cost : costs) {
            for (int i = 0; i < cost.size(); i++) {
                int low = INT_MAX;
                for (int j = 0; j < cost.size(); j++) {
                    if (j == i) continue;
                    low = min(low, pre[j]);
                }
                cur[i] = low + cost[i];
            }
            pre = cur;
        }
        int result = INT_MAX;
        for (int cost : cur)
            result = min(result, cost);
        return result;
    }
};