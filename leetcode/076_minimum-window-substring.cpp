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
        int start = 0, end = 0; // window的起止点
        int minLen = INT_MAX, minStart = 0; // 记录最小的window长度和起始点
        while (end < s.size()) {
            if (dict[s[end++]]-- > 0) count--;  //s[end]是t里的字符
            while (!count) {    // t中所有字符都搜到
                if (minLen > end - start) {
                    minLen = end - start;
                    minStart = start;
                }
                if (++dict[s[start++]] > 0) count++;    // s[start]如果是t里的字符，则count++
            }
        }
        return minLen > s.size() ? "" : s.substr(minStart, minLen);
    }
};