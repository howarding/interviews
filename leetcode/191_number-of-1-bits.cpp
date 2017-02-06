//Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
//
//For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

#include <iostream>

using namespace std;

class Solution_191 {
public:
    // Exp: https://discuss.leetcode.com/topic/9915/short-code-of-c-o-m-by-time-m-is-the-count-of-1-s-and-another-several-method-of-o-1-time
    // Time:	O(m)    m: # 1's
    // Space:	O(1)
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= n - 1;
            count++;
        }
        return count;
    }
};