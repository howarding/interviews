//Implement strStr().
//
//Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

#include <iostream>

using namespace std;

class Solution_028 {
public:
    // KMP  faster
    // Exp: https://discuss.leetcode.com/topic/15569/explained-4ms-easy-c-solution
    // https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
    // Time:	O(m+n)
    // Space:	O(1)
    int strStr(string haystack, string needle) {

    }


    // Brute Force
    // Exp: https://discuss.leetcode.com/topic/15569/explained-4ms-easy-c-solution
    // Time:	O(mn)
    // Space:	O(1)
    int strStr_1(string haystack, string needle) {
        if (needle.empty()) return 0;
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            while (j < n && haystack[i + j] == needle[j]) j++;
            if (j == n) return i;
        }
        return -1;
    }
};