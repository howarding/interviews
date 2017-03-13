//Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return [-1, -1].
//
//For example,
//Given [5, 7, 7, 8, 8, 10] and target value 8,
//return [3, 4].

#include <iostream>
#include <vector>

using namespace std;

class Solution_034 {
public:
    // Exp: https://discuss.leetcode.com/topic/5891/clean-iterative-solution-with-two-binary-searches-with-explanation
    // Time:	O(n*logn)
    // Space:	O(1)
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) return {-1, -1};
        int left = 0, right = nums.size() - 1;
        int start;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        start = left;

        left = 0, right = nums.size() - 1;
        int end;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        end = right;
        if (nums[start] == target && nums[end] == target) return {start, end};
        return {-1, -1};
    }
};