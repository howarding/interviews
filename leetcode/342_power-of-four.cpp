//Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
//
//Example:
//    Given num = 16, return true. Given num = 5, return false.
//
//Follow up: Could you solve it without loops/recursion?

#include <iostream>

using namespace std;

class Solution_342 {
public:
    // Exp: https://discuss.leetcode.com/topic/42860/java-1-line-cheating-for-the-purpose-of-not-using-loops
    // Time:	O(1)
    // Space:	O(1)
    bool isPowerOfFour(int num) {
        return (num > 0 && (num & (num - 1)) == 0 && (num & 0xaaaaaaaa) == 0);
        //0xaaaaaaaa is to get rid of those power of 2 but not power of 4
        //so that the single 1 bit always appears at the odd position
    }
};