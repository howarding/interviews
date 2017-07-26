//Given a pattern and a string str, find if str follows the same pattern.
//
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
//
//Examples:
//    1. pattern = "abba", str = "dog cat cat dog" should return true.
//    2. pattern = "abba", str = "dog cat cat fish" should return false.
//    3. pattern = "aaaa", str = "dog cat cat dog" should return false.
//    4. pattern = "abba", str = "dog dog dog dog" should return false.
//Notes:
//You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution_290 {
public:
    // Hashmap
    // Time:	O(m+n)
    // Space:	O(m+n)
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> dict1;
        unordered_map<string, char> dict2;
        int start = 0, end = 0;
        for (char c : pattern) {
            if (start == str.size()) return false;
            if (start > 0) start++;
            for (end = start; end < str.size() && str[end] != ' '; end++);
            string word = str.substr(start, end - start);
            if (dict1.count(c) && dict1[c] != word) return false;
            if (dict2.count(word) && dict2[word] != c) return false;
            dict1[c] = word;
            dict2[word] = c;
            start = end;
        }
        return start == str.size();
    }
};