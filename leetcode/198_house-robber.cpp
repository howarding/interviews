//You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
//Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

#include <iostream>
#include <vector>

using namespace std;

class Solution_198 {
public:
    // DP (My own)
    // Time:	O(n)
    // Space:	O(1)
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int rob_max(nums[0]), noRob_max(0);
        for (int i = 1; i < nums.size(); i++) {
            int tmp = rob_max;
            rob_max = noRob_max + nums[i];
            noRob_max = max(tmp, noRob_max);
        }
        return max(rob_max, noRob_max);
    }




    // DP
    // Time:	O(n)
    // Space:	O(1)
    int rob1(vector<int>& nums) {
        if (nums.size() < 2) return nums.size() ? nums[0] : 0;
        int previous(0), current(0);
        for (int i = 0; i < nums.size(); i++) {
            int tmp = current;
            current = max(previous + nums[i], current);
            previous = tmp;
        }
        return max(previous, current);
    }
};