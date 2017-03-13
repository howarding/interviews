//Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
//
//Example 1:
//    Input: [0,1]
//    Output: 2
//    Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
//Example 2:
//    Input: [0,1,0]
//    Output: 2
//    Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
//Note: The length of the given binary array will not exceed 50,000.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_525 {
public:
    // Hashmap
    // Exp: https://discuss.leetcode.com/topic/79906/easy-java-o-n-solution-presum-hashmap
    // Time:	O(n)
    // Space:	O(n)
    int findMaxLength(vector<int> &nums) {
        if (nums.size() < 2) return 0;
        int n = nums.size();
        unordered_map<int, vector<int>> dict;
        dict[0].push_back(-1);
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i] == 1 ? 1 : -1;
            dict[total].push_back(i);

        }
        int result = 0;
        for (auto &pair : dict) {
            if (pair.second.size() == 1)
                continue;
            result = max(result, pair.second.back() - pair.second[0]);
        }
        return result;
    }
};