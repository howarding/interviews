//Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
//
//Note:
//    1. You must not modify the array (assume the array is read only).
//    2. You must use only constant, O(1) extra space.
//    3. Your runtime complexity should be less than O(n^2).
//    4. There is only one duplicate number in the array, but it could be repeated more than once.

#include <iostream>
#include <vector>

using namespace std;

class Solution_287 {
public:
    // Binary Search
    // Exp: https://discuss.leetcode.com/topic/25580/two-solutions-with-explanation-o-nlog-n-and-o-n-time-o-1-space-without-changing-the-input-array
    // Time:	O(nlog(n))
    // Space:	O(1)
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        while (left < right) {
            int count = 0, mid = (left + right) / 2;
            for (int num : nums)
                if (num <= mid)
                    count++;
            if (count <= mid)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};