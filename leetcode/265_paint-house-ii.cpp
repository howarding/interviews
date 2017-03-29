//There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
//
//The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.
//
//Note:
//All costs are positive integers.
//
//Follow up:
//Could you solve it in O(nk) runtime?

#include <iostream>
#include <vector>

using namespace std;

class Solution_265 {
public:
    // DP
    // Exp: https://discuss.leetcode.com/topic/25489/fast-dp-java-solution-runtime-o-nk-space-o-1
    // Time:	O(nk)
    // Space:	O(1)
    int minCostII(vector<vector<int>> &costs) {
        if (costs.empty()) return 0;
        int n = costs.size(), k = costs[0].size();
        int min1, min2, min1_j;
        int min1_pre = 0, min2_pre = 0, min1_j_pre = -1;
        for (int i = 0; i < n; i++) {
            min1 = min2 = INT_MAX, min1_j = 0;
            for (int j = 0; j < k; j++) {
                int cost = costs[i][j] + (j == min1_j_pre ? min2_pre : min1_pre);
                if (cost < min1) {
                    min2 = min1;
                    min1 = cost;
                    min1_j = j;
                } else if (cost < min2)
                    min2 = cost;
            }
            min1_pre = min1;
            min2_pre = min2;
            min1_j_pre = min1_j;
        }
        return min1;
    }
};


//int main() {
//    vector<vector<int>> costs({{4,16},{15,5},{18,17},{10,12},{14,10},{3,10},{2,11},{18,14},{9,1},{14,13}});
//    Solution_265 sol;
//    cout << sol.minCostII(costs) << endl;
//}