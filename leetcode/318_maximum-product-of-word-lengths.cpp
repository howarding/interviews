//Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
//
//Example 1:
//Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
//Return 16
//The two words can be "abcw", "xtfn".
//
//Example 2:
//Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
//Return 4
//The two words can be "ab", "cd".
//
//Example 3:
//Given ["a", "aa", "aaa", "aaaa"]
//Return 0
//No such pair of words.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_318 {
public:
    // Exp: https://discuss.leetcode.com/topic/31766/bit-shorter-c
    // Time:	O(n^2)
    // Space:	O(n)
    int maxProduct(vector<string> &words) {
        int result = 0;
        vector<int> bits(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            for (char c : words[i])
                bits[i] |= 1 << (c - 'a');
            for (int j = i - 1; j >= 0; j--)
                if (!(bits[i] & bits[j]))
                    result = max(result, int(words[i].size() * words[j].size()));
        }
        return result;
    }


    // faster
    // Exp: https://discuss.leetcode.com/topic/31766/bit-shorter-c
    // Time:	O(n + N)
    // Space:	O(n)
    int maxProduct1(vector<string> &words) {
        int result = 0;
        unordered_map<int, int> dict;
        for (string& word : words) {
            int mask = 0;
            for (char c : word)
                mask |= 1 << (c - 'a');
            dict[mask] = max(dict[mask], int(word.size()));
            for (auto& pair : dict)
                if (!(mask & pair.first))
                    result = max(result, dict[mask] * pair.second);
        }
        return result;
    }
};