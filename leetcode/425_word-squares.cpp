//Given a set of words (without duplicates), find all word squares you can build from them.
//
//A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).
//
//For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.
//
//    b a l l
//    a r e a
//    l e a d
//    l a d y
//Note:
//    1. There are at least 1 and at most 1000 words.
//    2. All words will have the exact same length.
//    3. Word length is at least 1 and at most 5.
//    4. Each word contains only lowercase English alphabet a-z.
//Example 1:
//
//    Input:
//    ["area","lead","wall","lady","ball"]
//
//    Output:
//    [
//        [ "wall",
//          "area",
//          "lead",
//          "lady"
//        ],
//        [ "ball",
//          "area",
//          "lead",
//          "lady"
//    ]
//    ]
//
//    Explanation:
//        The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
//Example 2:
//
//    Input:
//    ["abat","baba","atan","atal"]
//
//    Output:
//    [
//        [ "baba",
//          "abat",
//          "baba",
//          "atan"
//        ],
//        [ "baba",
//          "abat",
//          "baba",
//          "atal"
//        ]
//    ]
//
//    Explanation:
//        The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_425 {
public:
    vector<vector<string>> wordSquares(vector<string> &words) {

    }

    // Exp: https://leetcode.com/problems/word-squares/discuss/91344/Short-PythonC%2B%2B-solution
    // Time:    O()
    // Space:   O(kn)
    vector<vector<string>> wordSquares2(vector<string> &words) {
        unordered_map<string, vector<string>> dict;
        for (const string& word: words)
            for (int i = 0; i < word.size(); i++) {
                string str = word.substr(0, i);
                dict[str].push_back(word);
            }

        vector<vector<string>> result;
        vector<string> path;
        int n = words[0].size();
        helper(dict, result, path, 0, n);
        return result;
    }

    void helper(unordered_map<string, vector<string>>& dict, vector<vector<string>>& result, vector<string>& path, int i, int n) {
        if (i == n) {
            result.push_back(path);
            return;
        }
        string pre;
        for (int j = 0; j < i; j++)
            pre += path[j][i];
        for (auto&& word: dict[pre]) {
            path.push_back(word);
            helper(dict, result, path, i+1, n);
            path.pop_back();
        }
    }
};