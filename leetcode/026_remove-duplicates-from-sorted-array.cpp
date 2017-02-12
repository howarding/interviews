//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//For example,
//    Given input array nums = [1,1,2],
//
//Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

#include <iostream>
#include <vector>

using namespace std;

class Solution_026 {
public:
    // In-place replace.
    // Exp: https://discuss.leetcode.com/topic/3102/my-solution-time-o-n-space-o-1
    // Time:	O(n)
    // Space:	O(1)
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() < 2) return nums.size();
        int ind = 0;
        for (int i = 1; i < nums.size(); i++)
            if (nums[ind] != nums[i])
                nums[++ind] = nums[i];
        return ind + 1;
    }
};