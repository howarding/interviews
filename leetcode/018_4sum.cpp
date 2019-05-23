//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
//Note: The solution set must not contain duplicate quadruplets.
//
//For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
//
//A solution set is:
//[
//[-1,  0, 0, 1],
//[-2, -1, 1, 2],
//[-2,  0, 0, 2]
//]

#include <iostream>
#include <vector>

using namespace std;

class Solution_018 {
public:
    // sort + 2sum II - Input array is sorted
    // Exp: https://discuss.leetcode.com/topic/28641/my-16ms-c-code
    // Time:	O(n^3)
    // Space:	O(n)
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            for (int j = i + 1; j < nums.size() - 2; j++) {
                int remain = target - nums[i] - nums[j];
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    int sum = nums[left] + nums[right];
                    if (remain < sum)
                        right--;
                    else if (remain > sum)
                        left++;
                    else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left+1]) left++;
                        while (left < right && nums[right-1] == nums[right]) right--;
                        left++;
                    }
                }
                while (j < nums.size() - 2 && nums[j] == nums[j + 1]) j++;
            }
            while (i < nums.size() - 3 && nums[i] == nums[i + 1]) i++;
        }
        return result;
    }
};