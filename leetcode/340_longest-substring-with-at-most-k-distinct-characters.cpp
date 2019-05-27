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
    // Hash Table + 2P
    // Exp: https://discuss.leetcode.com/topic/41711/8-lines-c-o-n-8ms
    // Time:	O(n)
    // Space:	O(1)
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        unordered_map<char, int> counter;   // 字符的hist
        // start    记录有效字符串的起始位置
        // distinct 记录不重复字符的数量
        int max_len = 0, start = 0, distinct = 0;
        for (int i = 0; i < s.size(); i++) {
            if (counter[i]++ == 0) distinct++;
            while (distinct > k) {
                counter[start]--;
                if (counter[start++] == 0)
                    distinct--;
            }
            max_len = max(max_len, i - start + 1);  // 每次循环都更新有效字符串的最大长度
        }
        return max_len;
    }
};