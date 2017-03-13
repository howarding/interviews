//The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//
//Given two integers x and y, calculate the Hamming distance.
//
//Note:
//0 ≤ x, y < 2^31.
//
//Example:
//
//    Input: x = 1, y = 4
//
//    Output: 2
//
//    Explanation:
//    1   (0 0 0 1)
//    4   (0 1 0 0)
//           ↑   ↑
//
//    The above arrows point to positions where the corresponding bits are different.

#include <iostream>

using namespace std;

class Solution_461 {
public:
    // faster
    // Exp: https://discuss.leetcode.com/topic/72236/my-c-solution-using-bit-manipulation
    // Time:	O(n)
    // Space:	O(1)
    int hammingDistance(int x, int y) {
        int result = 0, n = x ^y;
        while (n) {
            result++;
            n &= n - 1;
        }
        return result;
    }


    // my own
    // Time:	O(n)
    // Space:	O(1)
    int hammingDistance1(int x, int y) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int mask = 1 << i;
            result += (x & mask) != (y & mask);
        }
        return result;
    }
};