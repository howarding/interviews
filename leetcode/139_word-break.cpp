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

class Solution_139 {
public:
    // 1D DP
    // Exp: https://discuss.leetcode.com/topic/6156/java-implementation-using-dp-in-two-ways
    // Time:	O(n^2)
    // Space:	O(n)
    bool wordBreak(string s, vector<string> &wordDict) {
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


    // Trie
    bool wordBreak_fb_fu(string s, vector<string> &wordDict) {
        int n = 128;
        TrieNode *root = new TrieNode(n);
        for (string &word : wordDict) {
            TrieNode *node = root;
            for (char c : word) {
                if (!node->child[c])
                    node->child[c] = new TrieNode(n);
                node = node->child[c];
            }
            node->isEnd = true;
        }
        return helper(root, s, 0);
    }

    struct TrieNode {
        bool isEnd;
        vector<TrieNode *> child;

        TrieNode(int N) : child(N), isEnd(false) {};
    };

    bool helper(TrieNode *root, string &s, int start) {
        if (start == s.size()) return true;
        TrieNode *node = root;
        for (int i = start; i < s.size(); i++) {
            if (!node->child[s[i]])
                return false;
            node = node->child[s[i]];
            if (node->isEnd && helper(root, s, i + 1)) return true;
        }
        return false;
    }

};


//int main() {
//    Solution_139 sol;
//    vector<string> wordDict({"leet", "code"});
//    string s("leetcode");
//    vector<string> wordDict({"aaaa", "aaa"});
//    string s("aaaaaaa");
//    cout << sol.wordBreak_fb_fu(s, wordDict) << endl;
//}