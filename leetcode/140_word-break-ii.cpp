//Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.
//
//Return all such possible sentences.
//
//For example, given
//s = "catsanddog",
//dict = ["cat", "cats", "and", "sand", "dog"].
//
//A solution is ["cats and dog", "cat sand dog"].

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution_140 {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        vector<vector<string>> dp(s.size() + 1, vector<string>());
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        dp[0].push_back("");
        for (int i = 1; i <= s.size(); i++)
            for (int j = 0; j < i; j++)
                if (!dp[j].empty() && words.find(s.substr(j, i - j)) != words.end())
                    for (string& ele : dp[j])
                        dp[i].push_back(ele + (ele.empty() ? "" : " ") + s.substr(j, i-j));
        return dp[s.size()];
    }
};