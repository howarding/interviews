//Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.
//
//For example, given
//s = "leetcode",
//dict = ["leet", "code"].
//
//Return true because "leetcode" can be segmented as "leet code".

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution_wb {
public:
    // DP
    // Time:	O(n^2)
    // Space:	O(n)
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> f(s.size() + 1, false);
        f[0] = true;
        for (int i = 1; i <= s.size(); i++)
            for (int j = i - 1; j >= 0; j--)
                // for any j < i, if f[j] is true and s[j to i] in wordDict, f[i] is true
                if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    f[i] = true;
                    break;
                }
        return f.back();
    }


    bool wordBreak1(string s, vector<string>& wordDict) {



    }
};