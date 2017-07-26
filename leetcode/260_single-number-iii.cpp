//Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
//
//For example:
//
//Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
//
//Note:
//    1. The order of the result is not important. So in the above example, [5, 3] is also correct.
//    2. Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

#include <iostream>
#include <vector>

using namespace std;

class Solution_260 {
public:
    // xor
    // Exp: https://discuss.leetcode.com/topic/21605/accepted-c-java-o-n-time-o-1-space-easy-solution-with-detail-explanations
    // Time:	O(n)
    // Space:	O(1)
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result(2, 0);
        int diff = 0;
        for (int num : nums) diff ^= num;
        diff &= -diff;

        for (int num : nums)
            if (diff & num)
                result[0] ^= num;
            else
                result[1] ^= num;
        return result;
    }
};