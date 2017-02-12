//Implement regular expression matching with support for '.' and '*'.
//
//    '.' Matches any single character.
//    '*' Matches zero or more of the preceding element.
//
//    The matching should cover the entire input string (not partial).
//
//    The function prototype should be:
//    bool isMatch(const char *s, const char *p)
//
//    Some examples:
//    isMatch("aa","a") → false
//    isMatch("aa","aa") → true
//    isMatch("aaa","aa") → false
//    isMatch("aa", "a*") → true
//    isMatch("aa", ".*") → true
//    isMatch("ab", ".*") → true
//    isMatch("aab", "c*a*b") → true

#include <iostream>

using namespace std;

class Solution_010 {
public:
    // Backtracking
    // Exp: http://www.cnblogs.com/grandyang/p/4461713.html
    // Time:    O(n)
    // Space:   O(1)
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.size() == 1)
            return s.size() == 1 && (p[0] == s[0] || p[0] == '.');
        if (p[1] != '*')
            return !s.empty() && (p[0] == s[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        while (!s.empty() && (p[0] == s[0] || p[0] == '.')) {
            if (isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));
    }


    // DP
    bool isMatch_1(string s, string p) {

    }
};