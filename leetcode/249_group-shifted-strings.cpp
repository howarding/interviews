//Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
//
//    "abc" -> "bcd" -> ... -> "xyz"
//Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
//
//For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
//A solution is:
//
//    [
//        ["abc","bcd","xyz"],
//        ["az","ba"],
//        ["acef"],
//        ["a","z"]
//    ]

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_249 {
public:
    // Exp: https://discuss.leetcode.com/topic/20823/4ms-easy-c-solution-with-explanations
    // Time:	O(n)
    // Space:	O(n)
    vector<vector<string>> groupStrings(vector<string> &strings) {
        unordered_map<string, vector<string> > mp;
        for (auto &s : strings)
            mp[shift(s)].push_back(s);
        vector<vector<string>> result;
        for (auto &&ele : mp) {
            sort(ele.second.begin(), ele.second.end());
            result.push_back(ele.second);
        }
        return result;
    }

    string shift(string &s) {
        string t;
        for (int i = 1; i < s.size(); i++) {
            int diff = s[i] - s[i - 1];
            if (diff < 0) diff += 26;
            t += 'a' + diff;
        }
        return t;
    }
};