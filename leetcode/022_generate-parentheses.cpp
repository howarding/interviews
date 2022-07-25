//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//For example, given n = 3, a solution set is:
//
//    [
//        "((()))",
//        "(()())",
//        "(())()",
//        "()(())",
//        "()()()"
//    ]

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution_022 {
public:
    // Exp: Backtrack
    // Time:	O(n)
    // Space:	O(n)
    vector<string> generateParenthesis(int n) {
        int left = 0, right = 0;
        vector<string> result;
        string path;
        if (n > 0)
            helper(n, left, right, path, result);
        return result;
    }

    void helper(int n, int left, int right, string& path, vector<string>& result) {
        if (left == n && right == n) {
            result.push_back(path);
            return;
        }
        if (left < n) {
            path.push_back('(');
            helper(n, left + 1, right, path, result);
            path.pop_back();
        }
        if (left > right) {
            path.push_back(')');
            helper(n, left, right + 1, path, result);
            path.pop_back();
        }
    }
};