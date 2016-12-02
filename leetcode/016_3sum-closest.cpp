//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
//For example, given array S = {-1 2 1 -4}, and target = 1.
//
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution_016 {
public:
    // Exp: https://discuss.leetcode.com/topic/1978/a-n-2-solution-can-we-do-better
    // Time:	O(n^2)
    // Space:	O(1)
    int threeSumClosest(vector<int> &nums, int target) {
        if (nums.size() < 3)
            return accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        int diff_min = target - nums[0] - nums[1] - nums[2];
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int remain = target - nums[i] - nums[left] - nums[right];
                if (remain == 0)
                    return target;
                if (abs(remain) < abs(diff_min))
                    diff_min = remain;
                remain > 0 ? left++ : right--;
            }
        }
        return target - diff_min;
    }
};