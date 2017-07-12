//Given an integer n, return the number of trailing zeroes in n!.
//
//Note: Your solution should be in logarithmic time complexity.

#include <iostream>

using namespace std;

class Solution_172 {
public:
    // Exp: https://discuss.leetcode.com/topic/6516/my-one-line-solutions-in-3-languages
    // Time:	O(log(n))
    // Space:	O(1)
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};