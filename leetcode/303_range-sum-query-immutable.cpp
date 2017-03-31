//Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
//
//Example:
//    Given nums = [-2, 0, 3, -5, 2, -1]
//
//    sumRange(0, 2) -> 1
//    sumRange(2, 5) -> -1
//    sumRange(0, 5) -> -3
//Note:
//    1. You may assume that the array does not change.
//    2. There are many calls to sumRange function.

#include <iostream>
#include <vector>

using namespace std;

// 1D DP vector
// Time:	O(1)
// Space:	O(n)
class NumArray {
    vector<int> sums;
public:
    NumArray(vector<int> nums) {
        int total = 0;
        for (int num : nums) {
            total += num;
            sums.push_back(total);
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) return sums[j];
        return sums[j] - sums[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */