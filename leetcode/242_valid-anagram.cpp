//Given two strings s and t, write a function to determine if t is an anagram of s.
//
//For example,
//        s = "anagram", t = "nagaram", return true.
//s = "rat", t = "car", return false.
//
//Note:
//        You may assume the string contains only lowercase alphabets.
//
//Follow up:
//What if the inputs contain unicode characters? How would you adapt your solution to such case?

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_242 {
public:
    // Array
    // Time:	O(n)
    // Space:	O(1)
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> chars(26, 0);
        for (char c : s)
            chars[c - 'a']++;
        for (char c : t)
            if (chars[c - 'a']-- == 0) return false;
        return true;
    }



    // Hash Table
    // Time:	O(n)
    // Space:	O(n)
    bool isAnagram1(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<wchar_t, int> dict;   // handles unicode characters
        for (wchar_t c : s)
            dict[c]++;
        for (wchar_t c : t)
            if (dict[c]-- == 0) return false;
        return true;
    }



    // sort
    // Time:	O(nlog(n))
    // Space:	O(1)
    bool isAnagram2(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};