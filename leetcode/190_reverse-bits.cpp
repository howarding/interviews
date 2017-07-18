//Reverse bits of a given 32 bits unsigned integer.
//
//For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
//
//Follow up:
//If this function is called many times, how would you optimize it?
//
//Related problem: Reverse Integer

#include <iostream>

using namespace std;

class Solution_190 {
public:
    // My own
    // Time:	O(n)
    // Space:	O(1)
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0, count = 0;
        while (count++ < 32) {
            result = (result << 1) | (n & 1);
            n >>= 1;
        }
        return result;
    }
};