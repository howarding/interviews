//Given two strings s and t, determine if they are isomorphic.
//
//Two strings are isomorphic if the characters in s can be replaced to get t.
//
//All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
//
//For example,
//Given "egg", "add", return true.
//
//Given "foo", "bar", return false.
//
//Given "paper", "title", return true.
//
//Note:
//You may assume both s and t have the same length.

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution_205 {
public:
    // Hash table
    // Time:	O(n)
    // Space:	O(n)
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> dict1, dict2;
        for (int i = 0; i < s.size(); i++) {
            if (dict1.find(s[i]) != dict1.end() && dict1[s[i]] != t[i])
                return false;
            if (dict2.find(t[i]) != dict2.end() && dict2[t[i]] != s[i])
                return false;
            dict1[s[i]] = t[i];
            dict2[t[i]] = s[i];
        }
        return true;
    }
};