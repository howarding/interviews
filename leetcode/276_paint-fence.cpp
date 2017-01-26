//There is a fence with n posts, each post can be painted with one of the k colors.
//
//You have to paint all the posts such that no more than two adjacent fence posts have the same color.
//
//Return the total number of ways you can paint the fence.
//
//Note:
//    n and k are non-negative integers.

#include <iostream>

using namespace std;

class Solution_276 {
public:
    // Exp: https://discuss.leetcode.com/topic/23426/o-n-time-java-solution-o-1-space
    // Time:	O(n)
    // Space:	O(1)
    int numWays(int n, int k) {
        if (n <= 1) return k * n;
        if (n == 2) return k * k;
        int same = k, diff = k * (k - 1);
        for (int i = 3; i <= n; i++) {
            int same_now = diff;
            int diff_now = (same + diff) * (k - 1);
            same = same_now;
            diff = diff_now;
        }
        return same + diff;
    }
};