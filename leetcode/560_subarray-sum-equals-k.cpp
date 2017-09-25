//Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
//
//Example 1:
//    Input:nums = [1,1,1], k = 2
//    Output: 2
//Note:
//    1. The length of the array is in range [1, 20,000].
//    2. The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_560 {
public:
    // DP
    // Exp: https://leetcode.com/problems/subarray-sum-equals-k/solution/
    // Time:    O(n^2)
    // Space:   O(n)
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        if (nums.empty()) return count;
        vector<int> sums(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++)
            sums[i] = sums[i-1] + nums[i-1];
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j <= nums.size(); j++)
                if (sums[j] - sums[i] == k) count++;
        return count;
    }


    // DP + HashMap
    // Time:    O(n)
    // Space:   O(n)
    int subarraySum1(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        int sum = 0, count = 0;
        for (int num : nums) {
            dict[sum]++;
            sum += num;
            if (dict.find(sum - k) != dict.end())
                count += dict[sum - k];
        }
        return count;
    }
};