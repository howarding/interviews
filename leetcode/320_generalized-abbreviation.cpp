//Write a function to generate the generalized abbreviations of a word.
//
//Example:
//    Given word = "word", return the following list (order does not matter):
//    ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]

#include <iostream>
#include <vector>

using namespace std;

class Solution_320 {
public:
    // Backtrack  极难理解
    // Exp: https://discuss.leetcode.com/topic/32270/java-backtracking-solution
    // Time:	O(2^n)
    // Space:	O(2^n)
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        dfs(word, result, 0, "", 0);
        return result;
    }

    void dfs(string &word, vector<string> &result, int point, string cur, int count) {
        if (point == word.size()) {
            if (count > 0)
                cur += to_string(count);
            result.push_back(cur);
            return;
        }
        // abbreviate current letter at word[point]
        dfs(word, result, point + 1, cur, count + 1);
        // keep current letter at word[point]
        dfs(word, result, point + 1, cur + (count > 0 ? to_string(count) : "") + word[point], 0);
    }
};


//int main() {
//    Solution_320 sol;
//    string word("word");
//    vector<string> result = sol.generateAbbreviations(word);
//    for (const string& str: result)
//        cout << str << "\t";
//    cout << endl;
//}