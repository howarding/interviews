//Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.
//
//Example 1:
//    Input: 12
//    Output: 21
//Example 2:
//    Input: 21
//    Output: -1

#include <iostream>

using namespace std;

class Solution_556 {
public:
    // LC 31: Next Permutation
    // Exp: https://discuss.leetcode.com/topic/85787/c-solution-with-explanation
    // Time:	O(n)
    // Space:	O(1)
    int nextGreaterElement(int n) {
        if (n < 10) return -1;
        string s(to_string(n));
        int i = s.size() - 1,j;
        while (i > 0 && s[i - 1] >= s[i])
            i--;
        if (i == 0) return -1;
        for (j = i; j < s.size() && s[i-1] < s[j]; j++);
        swap(s[i-1], s[j-1]);
        reverse(s.begin() + i, s.end());
        long num = stol(s);
        return num > INT_MAX ? -1 : num;
    }
};