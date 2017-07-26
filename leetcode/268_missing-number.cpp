//Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
//
//For example,
//Given nums = [0, 1, 3] return 2.
//
//Note:
//Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

#include <iostream>
#include <vector>

using namespace std;

class Solution_268 {
public:
    // xor
    // Exp: https://discuss.leetcode.com/topic/24535/4-line-simple-java-bit-manipulate-solution-with-explaination
    // Time:	O(n)
    // Space:	O(1)
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), result = 0;
        for (int i = 0; i < n; i++)
            result = result ^ i ^ nums[i];
        return result ^ n;
    }



    // sum (My own)
    // Time:	O(n)
    // Space:	O(1)
    int missingNumber1(vector<int>& nums) {
        int n = nums.size();
        long result = 0;    // avoid overflow
        for (int i = 0; i < n; i++) {
            result += i + 1 - nums[i];
        }
        return int(result);
    }
};