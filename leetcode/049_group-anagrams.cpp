//Given an array of strings, group anagrams together.
//
//For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
//Return:
//
//    [
//        ["ate", "eat","tea"],
//        ["nat","tan"],
//        ["bat"]
//    ]

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_049 {
public:
    // Sort each string and make dictionary
    // Count Sort, FASTER
    // Exp: https://discuss.leetcode.com/topic/21038/10-lines-76ms-easy-c-solution-updated-function-signature
    // Time:	O(m * n)  m: size of strs. n: max_length of str in strs
    // Space:	O(m)
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> dict;
        for (string &str : strs) {
            string s = countSort(str);
            dict[s].push_back(str);
        }

        vector<vector<string>> result;
        for (auto &element: dict)
            result.push_back(vector<string>(element.second.begin(), element.second.end()));
        return result;
    }

    string countSort(string& str) {
        vector<int> chars(26, 0);
        for (char c : str)
            chars[c - 'a']++;
        string s(str.size(), 'a');
        int ind = 0;
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < chars[i]; j++)
                s[ind++] += i;
        return s;
    }



    // Time:	O(m * nlog(n))  m: size of strs. n: max_length of str in strs
    // Space:	O(m)
    vector<vector<string>> groupAnagrams1(vector<string> &strs) {
        unordered_map<string, vector<string>> dict;
        for (string &str : strs) {
//            string s = str;
//            sort(s.begin(), s.end());
            string s = countSort(str);
            dict[s].push_back(str);
        }

        vector<vector<string>> result;
        for (auto &element: dict)
            result.push_back(vector<string>(element.second.begin(), element.second.end()));
        return result;
    }
};