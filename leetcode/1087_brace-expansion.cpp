//A string S represents a list of words.
//Each letter in the word has 1 or more options.  If there is one option, the letter is represented as is.  If there is
// more than one option, then curly braces delimit the options.  For example, "{a,b,c}" represents options ["a", "b", "c"].
//For example, "{a,b,c}d{e,f}" represents the list ["ade", "adf", "bde", "bdf", "cde", "cdf"].
//Return all words that can be formed in this manner, in lexicographical order.
//
//Example 1:
//    Input: "{a,b}c{d,e}f"
//    Output: ["acdf","acef","bcdf","bcef"]
//
//Example 2:
//    Input: "abcd"
//    Output: ["abcd"]
//
//
//Note:
//    1 <= S.length <= 50
//    There are no nested curly brackets.
//    All characters inside a pair of consecutive opening and ending curly brackets are different.

#include <iostream>
#include <vector>

using namespace std;

class Solution_1087 {
public:
    // DFS
    vector<string> expand(string S) {
        vector<string> result;
        string path;
        helper(S, 0, path, result);
        return result;
    }

    void helper(string& S, int start, string path, vector<string>& result) {
        if (start == S.size()) {
            result.push_back(path);
            return;
        }
        int end = S[start] == '{' ? S.find('}', start) + 1 : start + 1;
        vector<char> chars;
        for (int i = start; i < end; i++)
            if (isalpha(S[i]))
                chars.push_back(S[i]);
        sort(chars.begin(), chars.end());
        for (char c: chars)
            helper(S, end, path + c, result);
    }
};