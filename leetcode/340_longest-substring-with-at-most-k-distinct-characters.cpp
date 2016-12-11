//Given a string, find the length of the longest substring T that contains at most k distinct characters.
//
//For example, Given s = “eceba” and k = 2,
//
//T is "ece" which its length is 3.

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution_340 {
public:
    // Exp: https://discuss.leetcode.com/topic/41711/8-lines-c-o-n-8ms

    // 1. Array (faster)
    // Time:	O(n^2)
    // Space:	O(1)
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ctr[256] = {}, j = -1, distinct = 0, max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            distinct += ctr[s[i]]++ == 0;
            while (distinct > k)
                distinct -= --ctr[s[++j]] == 0;
            max_len = max(max_len, i - j);
        }
        return max_len;
    }


    // 2. Hash Table
    // Time:	O(n^2)
    // Space:	O(1)
    int lengthOfLongestSubstringKDistinct_1(string s, int k) {
        unordered_map<char, int> ctr;
        int j = -1, max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            ctr[s[i]]++;
            while (ctr.size() > k)
                if (--ctr[s[++j]] == 0)
                    ctr.erase(s[j]);
            max_len = max(max_len, i - j);
        }
        return max_len;
    }
};