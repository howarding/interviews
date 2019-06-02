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
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;
        for (auto &s : strings)
            mp[shift(s)].push_back(s);
        vector<vector<string>> result;
        for (auto&& ele : mp)
            result.push_back(ele.second);
        return result;
    }

    string shift(string &s) {
        string result;
        int diff = s[0] - 'a';
        for (const char c: s)
            result.push_back(c - diff < 'a' ? c - diff + 26 : c - diff);
        return result;
    }
};