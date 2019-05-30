//Given an unsorted array of integers, find the length of longest increasing subsequence.
//
//For example,
//Given [10, 9, 2, 5, 3, 7, 101, 18],
//The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
//
//Your algorithm should run in O(n^2) complexity.
//
//Follow up: Could you improve it to O(n log n) time complexity?

#include <iostream>
#include <vector>

using namespace std;

class Solution_300 {
public:
    // BEST: DP + Binary Search (My own)
    // Exp: https://www.cnblogs.com/grandyang/p/4938187.html
    // Time:	O(nlog(n))
    // Space:	O(n)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int num : nums) {
            int left = 0, right = dp.size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (num <= dp[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            if (left == dp.size())
                dp.push_back(num);
            else
                dp[left] = num;
        }
        return dp.size();
    }

    // DP
    // Time:    O(n^2)
    // Space:   O(n)
    int lengthOfLIS2(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size(), 1);
        int result = 0;
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            result = max(result, dp[i]);
        }
        return result;
    }
};