//Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
//
//Example 1:
//    Input: "abab"
//
//    Output: True
//
//    Explanation: It's the substring "ab" twice.
//
//Example 2:
//    Input: "aba"
//
//    Output: False
//
//Example 3:
//    Input: "abcabcabcabc"
//
//    Output: True
//
//    Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

#include <iostream>
#include <vector>

using namespace std;

class Solution_459 {
public:
    // Fastest
    // Exp:     https://discuss.leetcode.com/topic/67590/java-o-n
    // Time:	O(n)
    // Space:	O(n)
    bool repeatedSubstringPattern(string str) {
        // This is the kmp issue
        vector<int> prefix = kmp(str);
        int n = str.size();
        int len = prefix[n - 1];
        return (len > 0 && n % (n - len) == 0);
    }

    vector<int> kmp(string s) {
        int len = s.size();
        vector<int> res(len);
        int i = 0, j = 1;
        res[0] = 0;
        while (i < len && j < len) {
            if (s[j] == s[i]) {
                res[j] = i + 1;
                i++;
                j++;
            } else {
                if (i == 0) {
                    res[j] = 0;
                    j++;
                } else
                    i = res[i - 1];
            }
        }
        return res;
    }

    // My own
    bool repeatedSubstringPattern2(string s) {
        if (s.size() < 1) return false;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[0]) continue;
            if (s.size() % i != 0) continue;
            int j = i;
            while (j < s.size() && s.substr(0, i) == s.substr(j, i)) j += i;
            if (j == s.size()) return true;
        }
        return false;
};