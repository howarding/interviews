//Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//
//Solve it without division and in O(n).
//
//For example, given [1,2,3,4], return [24,12,8,6].
//
//Follow up:
//Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

#include <iostream>
#include <vector>

using namespace std;

class Solution_238 {
public:
    // DP
    // Exp: https://discuss.leetcode.com/topic/18864/simple-java-solution-in-o-n-without-extra-space
    // Time:	O(n)
    // Space:	O(1)
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> result(nums.size(), 1);
        int product = 1, n = nums.size();
        result[1] = nums[0];
        for (int i = 2; i < n; i++)
            result[i] = result[i - 1] * nums[i - 1];
        for (int i = n - 2; i >= 0; i--) {
            product *= nums[i + 1];
            result[i] *= product;
        }
        return result;
    }
};