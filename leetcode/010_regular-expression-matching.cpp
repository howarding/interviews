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
#include <vector>

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

    // Basic: my own
    // DP matrix
    // Time:    O(mn)
    // Space:   O(mn)
    bool isMatch_0(string s, string p) {
        // dp[i][j] means whether s[0 ... i-1] match p[0 ... j-1]
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= s.size(); i++) {
            for (int j = 1; j <= p.size(); j++) {
                if (p[j - 1] == '*') // j > 1
                    dp[i][j] =
                            // * removes previous letter
                            dp[i][j - 2]
                            ||  // * keeps previous letter at least 1 time
                            (i && dp[i - 1][j] && (p[j - 2] == '.' || p[j - 2] == s[i - 1]));
                else
                    // p[j - 1] == '.' || p[j - 1] == s[i - 1]
                    dp[i][j] = i && (p[j - 1] == '.' || p[j - 1] == s[i - 1]) && dp[i - 1][j - 1];
            }
        }
        return dp.back().back();
    }

    // DP 2 vectors
    // Exp: https://leetcode.com/problems/regular-expression-matching/discuss/5684/C%2B%2B-O(n)-space-DP
    // Time:    O(mn)
    // Space:   O(n)
    bool isMatch_1(string s, string p) {
        vector<bool> pre(p.size() + 1, false), cur(p.size() + 1, false);
        cur[0] = true;
        for (int i = 0; i <= s.size(); i++) {
            for (int j = 1; j <= p.size(); j++) {
                if (p[j - 1] == '*')
                    cur[j] =
                            // * removes previous letter
                            cur[j - 2]
                            ||  // * keeps previous letter at least 1 time
                            (i && pre[j] && (p[j - 2] == '.' || p[j - 2] == s[i - 1]));
                else
                    // p[j - 1] == '.' || p[j - 1] == s[i - 1]
                    cur[j] = i && (p[j - 1] == '.' || p[j - 1] == s[i - 1]) && pre[j - 1];
            }
            swap(pre, cur);
            fill(cur.begin(), cur.end(), false);
        }
        return pre.back();
    }
};

//int main() {
//    Solution_010 sol;
//    string s = "ab", p = ".*";
//    cout << sol.isMatch_0(s, p) << endl;
//}