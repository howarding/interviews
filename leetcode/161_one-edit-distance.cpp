//Given two strings S and T, determine if they are both one edit distance apart.

#include <iostream>
#include <vector>

using namespace std;

class Solution_161 {
public:
    // Exp: https://discuss.leetcode.com/topic/30308/my-clear-java-solution-with-explanation
    // Time:	O(n)
    // Space:	O(1)
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if (m > n) return isOneEditDistance(t, s);
        bool sameLen = m == n;
        for (int i = 0; i < m; i++) {
            if (s[i] != t[i]) {
                if (sameLen)
                    return s.substr(i + 1) == t.substr(i + 1);
                else
                    return s.substr(i) == t.substr(i + 1);
            }
        }
        return n - m == 1;
    }
};