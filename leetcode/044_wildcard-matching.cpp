//Implement wildcard pattern matching with support for '?' and '*'.
//
//    '?' Matches any single character.
//    '*' Matches any sequence of characters (including the empty sequence).
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
//    isMatch("aa", "*") → true
//    isMatch("aa", "a*") → true
//    isMatch("ab", "?*") → true
//    isMatch("aab", "c*a*b") → false

#include <iostream>
#include <vector>

using namespace std;

class Solution_044 {
public:
    // Exp: https://discuss.leetcode.com/topic/17901/accepted-c-dp-solution-with-a-trick
    // 2D DP
    // Time:	O(mn)
    // Space:	O(n)
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        bool pre_up;
        for (int i = 0; i < m; i++) {
            pre_up = dp[0];
            dp[0] = dp[0] && p[i] == '*';
            bool row_result = false;
            for (int j = 1; j <= n; j++) {
                bool result;
                if (p[i] == '*')
                    result = dp[j - 1] || dp[j];
                else
                    result = pre_up && (p[i] == '?' || p[i] == s[j - 1]);
                pre_up = dp[j];
                dp[j] = result;
                row_result |= dp[j];
            }
            if (!row_result) return false;
        }
        return dp[n];
    }
};


//int main() {
//    string s = "zacabz";
//    string p = "*a?b*";
//    Solution_044 sol;
//    cout << sol.isMatch(s, p) << endl;
//}