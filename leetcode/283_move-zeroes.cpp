//Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//
//For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
//
//Note:
//    You must do this in-place without making a copy of the array.
//    Minimize the total number of operations.

#include <iostream>
#include <vector>

using namespace std;

class Solution_283 {
public:
    // 2Pointers
    // Exp: https://discuss.leetcode.com/topic/24716/simple-o-n-java-solution-using-insert-index
    // Time:	O(n)
    // Space:	O(1)
    void moveZeroes(vector<int> &nums) {
        int n = nums.size();
        if (nums.empty()) return;
        int insertPos = 0;
        for (int num : nums)
            if (num) nums[insertPos++] = num;
        while (insertPos < n)
            nums[insertPos++] = 0;
    }
};