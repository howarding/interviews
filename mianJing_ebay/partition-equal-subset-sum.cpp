//Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//
//Note:
//    1. Each of the array element will not exceed 100.
//    2. The array size will not exceed 200.
//Example 1:
//
//    Input: [1, 5, 11, 5]
//
//    Output: true
//
//    Explanation: The array can be partitioned as [1, 5, 5] and [11].
//Example 2:
//
//    Input: [1, 2, 3, 5]
//
//    Output: false
//
//    Explanation: The array cannot be partitioned into equal sum subsets.

#include <iostream>
#include <vector>

using namespace std;

class Solution_pess {
public:
    // 1D DP
    // Time:	O(n*sum)
    // Space:	O(sum)
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num : nums)
            total += num;
        if (total % 2) return false;
        int sum = total / 2, n = nums.size();
//        vector<vector<bool>> dp(n + 1, vector<bool>(sum+1, false));
//        for (int i = 0; i < n + 1; i++)
//            dp[i][0] = true;
//        for (int i = 1; i <= n; i++)
//            for (int j = 1; j <= sum; j++)
//                dp[i][j] = dp[i-1][j] || j < nums[i-1] ? false : dp[i-1][j-nums[i-1]];
//        return dp[n][sum];
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int num : nums)
            for (int j = sum; j > 0; j--)
                if (j >= num)
                    dp[j] = dp[j] || dp[j - num];
        return dp[sum];
    }



    // 2D DP
    // Time:	O(n*sum)
    // Space:	O(n*sum)
    bool canPartition1(vector<int>& nums) {
        int total = 0;
        for (int num : nums)
            total += num;
        if (total % 2) return false;
        int sum = total / 2, n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum+1, false));
        for (int i = 0; i < n + 1; i++)
            dp[i][0] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= sum; j++)
                dp[i][j] = dp[i-1][j] || j < nums[i-1] ? false : dp[i-1][j-nums[i-1]];
        return dp[n][sum];
    }



    // Recursive
    // Time:	O(2^n)
    // Space:	O(1)
    bool canPartition2(vector<int>& nums) {
        int total = 0;
        for (int num : nums)
            total += num;
        if (total % 2) return false;
        int sum = total / 2, n = nums.size();
        return isSubsetSum(nums, n-1, sum);
    }


    bool isSubsetSum(vector<int>& nums, int i, int sum) {
        if (sum == 0) return true;
        if (i < 0) return false;
        bool result = isSubsetSum(nums, i-1, sum);
        if (nums[i] > sum) return result;
        else return result || isSubsetSum(nums, i-1, sum - nums[i]);
    }
};


//int main()
//{
//    Solution_pess sol;
//    vector<int> nums({3, 1, 5, 9, 12});
//    cout << sol.canPartition2(nums) << endl;
//}