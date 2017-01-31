//You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
//
//Find out how many ways to assign symbols to make sum of integers equal to target S.
//
//Example 1:
//    Input: nums is [1, 1, 1, 1, 1], S is 3.
//    Output: 5
//    Explanation:
//
//    -1+1+1+1+1 = 3
//    +1-1+1+1+1 = 3
//    +1+1-1+1+1 = 3
//    +1+1+1-1+1 = 3
//    +1+1+1+1-1 = 3
//
//    There are 5 ways to assign symbols to make the sum of nums be target 3.
//Note:
//    1. The length of the given array is positive and will not exceed 20.
//    2. The sum of elements in the given array will not exceed 1000.
//    3. Your output answer is guaranteed to be fitted in a 32-bit integer.

#include <iostream>
#include <vector>

using namespace std;

class Solution_494 {
public:
    // Exp: https://discuss.leetcode.com/topic/76201/java-short-dfs-solution/6
    // DFS
    // Time:	O(2^n)
    // Space:	O(1)
    int findTargetSumWays(vector<int> &nums, int S) {
        return dfs(nums, S, 0, 0);
    }

    int dfs(vector<int> &nums, int S, int sum, int i) {
        if (i == nums.size() - 1)
            return (sum + nums[i] == S) + (sum - nums[i] == S);
        return dfs(nums, S, sum + nums[i], i + 1) + dfs(nums, S, sum - nums[i], i + 1);
    }
};