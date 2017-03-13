//Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
//Note:
//    You are not suppose to use the library's sort function for this problem.
//
//click to show follow up.
//
//Follow up:
//A rather straight forward solution is a two-pass algorithm using counting sort.
//First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
//
//Could you come up with an one-pass algorithm using only constant space?

#include <iostream>
#include <vector>

using namespace std;

class Solution_075 {
public:
    // 2 Pointers, better
    // One pass in-place
    // Time:	O(n)
    // Space:	O(1)
    void sortColors(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        for (int i = 0; i < right; i++) {
            if (nums[i] == 0 && i != left)
                swap(nums[i--], nums[left++]);
            else if (nums[i] == 2 && i != right)
                swap(nums[i--], nums[right--]);
        }
    }


    // Exp: https://discuss.leetcode.com/topic/6968/four-different-solutions
    // One pass in-place
    // Time:	O(n)
    // Space:	O(1)
    void sortColors_1(vector<int> &nums) {
        int n0 = 0, n1 = 0, n2 = 0;
        for (int num : nums) {
            nums[n2++] = 2;
            if (num < 2)
                nums[n1++] = 1;
            if (num < 1)
                nums[n0++] = 0;
        }
    }
};