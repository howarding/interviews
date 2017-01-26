//Given an integer, write a function to determine if it is a power of three.
//
//Follow up:
//Could you do it without using any loop / recursion?

#include <iostream>
#include <cmath>

using namespace std;

class Solution_326 {
public:
    // Exp: https://leetcode.com/submissions/detail/87907753/
    // Time:	O(1)
    // Space:	O(1)
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        double power = log10(n) / log10(3);
        return power == floor(power);
    }
};