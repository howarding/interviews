//Given an integer, write a function to determine if it is a power of two.

#include <iostream>
#include <cmath>

using namespace std;

class Solution_231 {
public:
    // Exp: https://discuss.leetcode.com/topic/17857/using-n-n-1-trick
    // Time:	O(1)
    // Space:	O(1)
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }


    // 类似 power of 3
    // Time:    O(1)
    // Space:   O(1)
    bool isPowerOfTwo2(int n) {
        if (n <= 0) return false;
        double power = log2(n);
        return power == floor(power);
    }


    // Recursion
    // Time:    O(n)
    // Space:   O(1)
    bool isPowerOfTwo3(int n) {
        if (n <= 0) return false;
        return n < 2 ? n == 1 : (n % 2 == 0 && isPowerOfTwo3(n / 2));
    }
};