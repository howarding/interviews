//Given a positive integer n and you can do operations as follow:
//
//    1. If n is even, replace n with n/2.
//    2. If n is odd, you can replace n with either n + 1 or n - 1.
//
//What is the minimum number of replacements needed for n to become 1?
//
//Example 1:
//
//    Input:
//    8
//
//    Output:
//    3
//
//    Explanation:
//    8 -> 4 -> 2 -> 1
//
//Example 2:
//
//    Input:
//    7
//
//    Output:
//    4
//
//    Explanation:
//    7 -> 8 -> 4 -> 2 -> 1
//    or
//    7 -> 6 -> 3 -> 2 -> 1

#include <iostream>

using namespace std;

class Solution_397 {
public:
    // Exp: https://discuss.leetcode.com/topic/58425/java-12-line-4-5-ms-iterative-solution-with-explanations-no-other-data-structures
    // Time:	O(log(n))
    // Space:	O(1)
    int integerReplacement(int n) {
        if (n == INT_MAX) return 32;
        int count = 0;
        while (n > 1) {
            if (n % 2 == 0) n /= 2;
            else {
                if ((n + 1) % 4 == 0 && ((n - 1) != 2)) n += 1;
                else n -= 1;
            }
            count++;
        }
        return count;
    }
};