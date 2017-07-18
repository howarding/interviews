//Rotate an array of n elements to the right by k steps.
//
//For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
//
//Note:
//        Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
//
//[show hint]
//
//Hint:
//Could you do it in-place with O(1) extra space?
//Related problem: Reverse Words in a String II

#include <iostream>
#include <vector>

using namespace std;

class Solution_189 {
public:
    // Exp: https://discuss.leetcode.com/topic/14341/easy-to-read-java-solution
    // Time:	O(n)
    // Space:	O(1)
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return;
        int residual = k % n;
        if (!residual) return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + residual);
        reverse(nums.begin() + residual, nums.end());
    }



    // My own
    // Time:	O(n)
    // Space:	O(k)
    void rotate1(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return;
        int residual = k % n;
        if (!residual) return;
        vector<int> tmp(nums.end() - residual, nums.end());
        for (int i = n - 1; i >= 0; i--)
            nums[i] = i < residual ? tmp[i] : nums[i - residual];
    }



    void rotate2(vector<int>& nums, int k) {

    }



    void rotate3(vector<int>& nums, int k) {

    }
};