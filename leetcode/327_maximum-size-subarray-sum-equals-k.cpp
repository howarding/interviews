//Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.
//
//Note:
//    The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.
//
//Example 1:
//Given nums = [1, -1, 5, -2, 3], k = 3,
//return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)
//
//Example 2:
//Given nums = [-2, -1, 2, 1], k = 1,
//return 2. (because the subarray [-1, 2] sums to 1 and is the longest)
//
//Follow Up:
//Can you do it in O(n) time?

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_327 {
public:
    // Hashmap
    // Exp: https://discuss.leetcode.com/topic/33259/o-n-super-clean-9-line-java-solution-with-hashmap
    // Time:	O(n)
    // Space:	O(n)
    int maxSubArrayLen(vector<int> &nums, int k) {
        if (nums.empty()) return 0;
        int sum = 0, max_len = 0;
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k) max_len = i + 1;
            if (dict.find(sum - k) != dict.end())
                max_len = max(max_len, i - dict[sum - k]);
            if (dict.find(sum) == dict.end()) dict[sum] = i;
        }
        return max_len;
    }
};