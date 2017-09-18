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

class Solution_416 {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num : nums)
            total += num;
        if (total % 2) return false;
        return helper(nums, 0, total / 2);
    }


    bool helper(vector<int>& nums, int start, int target) {
        if (!target) return true;
        if (target < 0 || start == nums.size()) return false;
        return helper(nums, start + 1, target) || helper(nums, start + 1, target - nums[start]);
    }
};