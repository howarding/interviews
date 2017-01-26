//Given an array of integers, every element appears twice except for one. Find that single one.
//
//Note:
//    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

#include <iostream>
#include <vector>

using namespace std;

class Solution_136 {
public:
    // Exp: https://discuss.leetcode.com/topic/1916/my-o-n-solution-using-xor
    // Time:	O(n)
    // Space:	O(1)
    int singleNumber(vector<int> &nums) {
        int result = 0;
        for (int num : nums)
            result ^= num;
        return result;
    }
};