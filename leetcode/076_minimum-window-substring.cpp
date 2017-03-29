//Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
//For example,
//S = "ADOBECODEBANC"
//T = "ABC"
//Minimum window is "BANC".
//
//Note:
//    If there is no such window in S that covers all characters in T, return the empty string "".
//
//If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

#include <iostream>
#include <vector>


using namespace std;

class Solution_076 {
public:
    // Hash Table, 2 Pointers
    // Exp: https://discuss.leetcode.com/topic/30941/here-is-a-10-line-template-that-can-solve-most-substring-problems
    // Time:	O(n)
    // Space:	O(1)
    string minWindow(string s, string t) {
        vector<int> dict(128, 0);
        for (char c : t)
            dict[c]++;
        int count = t.size();
        int start = 0, end = 0;
        int minLen = INT_MAX, minStart = 0;
        while (end < s.size()) {
            if (dict[s[end++]]-- > 0) count--;
            while (!count) {
                if (minLen > end - start) {
                    minLen = end - start;
                    minStart = start;
                }
                if (++dict[s[start++]] > 0) count++;
            }
        }
        return minLen > s.size() ? "" : s.substr(minStart, minLen);
    }
};