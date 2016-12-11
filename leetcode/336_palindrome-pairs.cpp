//Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
//
//Example 1:
//Given words = ["bat", "tab", "cat"]
//Return [[0, 1], [1, 0]]
//The palindromes are ["battab", "tabbat"]
//
//Example 2:
//Given words = ["abcd", "dcba", "lls", "s", "sssll"]
//Return [[0, 1], [1, 0], [3, 2], [2, 4]]
//The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_336 {
public:
    // Exp: https://discuss.leetcode.com/topic/40654/easy-to-understand-ac-c-solution-o-n-k-2-using-map
    // Time:	O(n * k^2)
    // Space:	O(n)
    vector<vector<int>> palindromePairs(vector<string> &words) {
        vector<vector<int>> result;
        if (words.size() < 2) return result;
        unordered_map<string, int> dict;
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            reverse(word.begin(), word.end());
            dict[word] = i;
        }
        if (dict.find("") != dict.end())
            for (int i = 0; i < words.size(); i++) {
                if (dict[""] == i) continue;
                if (isPalindrome(words[i]))
                    result.push_back({dict[""], i});
            }

        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < words[i].size(); j++) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j, words.size() - j);
                if (dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i)
                    result.push_back({i, dict[left]});
                if (dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i)
                    result.push_back({dict[right], i});
            }
        return result;
    }

    bool isPalindrome(string &s) {
        int left = 0, right = s.size() - 1;
        while (left < right)
            if (s[left++] != s[right--])
                return false;
        return true;
    }
};