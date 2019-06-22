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
        return num > 0 && (num & (num - 1)) == 0 && (num & 0xaaaaaaaa) == 0;
        //0xaaaaaaaa is to get rid of those power of 2 but not power of 4
        //0xaaaaaaaa = 10101010101010101010101010101010
        //so that the single 1 bit always appears at the odd position
    }

    // Exp: https://discuss.leetcode.com/topic/42914/1-line-c-solution-without-confusing-bit-manipulations
    // Time:	O(1)
    // Space:	O(1)
    bool isPowerOfFour3(int num) {
        return (num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0);
        //(1) 4^n - 1 = (2^n + 1) * (2^n - 1)
        //(2) among any 3 consecutive numbers, there must be one that is a multiple of 3
        // among (2^n-1), (2^n), (2^n+1), one of them must be a multiple of 3, and (2^n)
        // cannot be the one, therefore either (2^n-1) or (2^n+1) must be a multiple of
        // 3, and 4^n-1 must be a multiple of 3 as well.
    }


    // Recursive
    bool isPowerOfFour1(int num) {
        if (num == 0) return false;
        if (num == 1) return true;
        return num % 4 == 0 && isPowerOfFour1(num / 4);
    }


    // Iterative
    bool isPowerOfFour2(int num) {
        while (num > 1) {
            if (num % 4) return false;
            num /= 4;
        }
        return num == 1;
    }
};