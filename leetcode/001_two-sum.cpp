//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution.
//
//Example:
//    Given nums = [2, 7, 11, 15], target = 9,
//
//    Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].
//UPDATE (2016/2/13):
//The return format had been changed to zero-based indices. Please read the above updated description carefully.

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution_001 {
public:
    // Exp: https://discuss.leetcode.com/topic/3294/accepted-c-o-n-solution
    // Time:	O(n)
    // Space:	O(n)
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> index;
        for (int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i];
            if (index.find(remain) != index.end())
                return {index[remain], i};
            index[nums[i]] = i;
        }
        return {};
    }
};