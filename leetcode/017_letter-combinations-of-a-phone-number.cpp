//Given a digit string, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters (just like on the telephone buttons) is given below.
//
//
//    Input:Digit string "23"
//    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
//Note:
//    Although the above answer is in lexicographical order, your answer could be in any order you want.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution_017 {
public:
    // Exp: DFS     My own method
    // Time:	O(2^n)
    // Space:	O(n)
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        vector<string> dict = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string path = "";
        int ind = 0;
        dfs(digits, dict, ind, path, result);
        return result;
    }

    void dfs(string &digits, vector<string> &dict, int ind, string path, vector<string> &result) {
        if (ind == digits.size()) {
            result.push_back(path);
            return;
        }
        int len = dict[digits[ind] - '0'].size();
        for (int i = 0; i < len; i++)
            dfs(digits, dict, ind + 1, path + dict[digits[ind] - '0'][i], result);
    }


    // Exp: BFS
    // Exp: https://discuss.leetcode.com/topic/8465/my-java-solution-with-fifo-queue
    // Time:	O(2^n)
    // Space:	O(n)
    vector<string> letterCombinations_1(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        queue<string> q;
        vector<string> dict = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        q.push("");
        for (int i = 0; i < digits.size(); i++)
            while (q.front().size() == i) {
                string &a = q.front();
                q.pop();
                for (char c : dict[digits[i] - '0'])
                    q.push(a + c);
            }
        while (!q.empty()) {
            string &s = q.front();
            result.push_back(s);
            q.pop();
        }
        return result;
    }


    // 电话本扩展，最后只输出有效地组合，有效组合会给出来，用trie做就可以了
    vector<string> letterCombinations_fb_fu1(string digits) {

    }
};