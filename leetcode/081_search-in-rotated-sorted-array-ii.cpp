//Follow up for "Search in Rotated Sorted Array":
//What if duplicates are allowed?
//
//Would this affect the run-time complexity? How and why?
//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Write a function to determine if a given target is in the array.
//
//The array may contain duplicates.

#include <iostream>
#include <vector>

using namespace std;

class Solution_081 {
public:
    // Exp: https://discuss.leetcode.com/topic/8087/c-concise-log-n-solution
    // Time:	O(n)
    // Space:	O(1)
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) return true;
            if (nums[mid] < nums[right]) {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            } else if (nums[mid] > nums[right]){
                if (nums[left] <= target && target <= nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else
                right--;
        }
        return false;
    }
};