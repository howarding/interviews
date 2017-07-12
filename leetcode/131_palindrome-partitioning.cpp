//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return all possible palindrome partitioning of s.
//
//For example, given s = "aab",
//Return
//
//    [
//      ["aa","b"],
//      ["a","a","b"]
//    ]

#include <iostream>
#include <vector>

using namespace std;

class Solution_131 {
public:
    // Backtracking
    // Exp: https://discuss.leetcode.com/topic/6186/java-backtracking-solution
    // Time:	O(2^n)
    // Space:	O(2^n)
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if (s.empty()) return result;
        vector<string> path;
        helper(s, 0, path, result);
        return result;
    }

    void helper(string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++)
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i-start+1));
                helper(s, i+1, path, result);
                path.pop_back();
            }
    }

    bool isPalindrome(string& s, int start, int end) {
        while (start <= end)
            if (s[start++] != s[end--]) return false;
        return true;
    }
};