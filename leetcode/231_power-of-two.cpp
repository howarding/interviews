//Given an integer, write a function to determine if it is a power of two.

#include <iostream>

using namespace std;

class Solution_231 {
public:
    // Exp: https://discuss.leetcode.com/topic/17857/using-n-n-1-trick
    // Time:	O(1)
    // Space:	O(1)
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return !(n & (n - 1));
    }
};