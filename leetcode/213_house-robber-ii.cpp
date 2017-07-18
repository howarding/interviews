//Note: This is an extension of House Robber.
//
//After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.
//
//Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

#include <iostream>
#include <vector>

using namespace std;

class Solution_213 {
public:
    // Exp: https://discuss.leetcode.com/topic/14504/9-lines-0ms-o-1-space-c-solution
    // Time:	O(n)
    // Space:	O(1)
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n< 2) return n ? nums[0] : 0;
        return max(subRob(nums, 0, n - 2), subRob(nums, 1, n - 1));
    }

    int subRob(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        int previous(0), current(0);
        for (int i = left; i <= right; i++) {
            int tmp = current;
            current = max(previous + nums[i], current);
            previous = tmp;
        }
        return current;
    }
};