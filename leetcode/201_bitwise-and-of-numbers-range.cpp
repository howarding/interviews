//Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
//
//For example, given the range [5, 7], you should return 4.

#include <iostream>

using namespace std;

class Solution_201 {
public:
    // Iterative (My own)
    // Time:	O(log(n))
    // Space:	O(1)
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while (m && m != n) {
            m >>= 1;
            n >>= 1;
            count++;
        }
        return m << count;
    }




    // Recursive
    // Exp: https://discuss.leetcode.com/topic/13508/one-line-c-solution
    // Time:	O(log(n))
    // Space:	O(1)
    int rangeBitwiseAnd1(int m, int n) {
        return m < n ? (rangeBitwiseAnd1(m / 2, n / 2) * 2) : m;
    }
};