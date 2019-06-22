//Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
//
//This is case sensitive, for example "Aa" is not considered a palindrome here.
//
//Note:
//    Assume the length of given string will not exceed 1,010.
//
//Example:
//
//    Input:
//    "abccccdd"
//
//    Output:
//    7
//
//    Explanation:
//    One longest palindrome that can be built is "dccaccd", whose length is 7.

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution_409 {
public:
    // 偶数个字符的数量，有奇数字符就加1
    // Time:	O(n)
    // Space:	O(1)
    int longestPalindrome(string s) {
        vector<int> count(256);
        for (const char c: s)
            count[c]++;
        int result = 0;
        for (int num: count)
            result += num / 2 * 2;
        return result == s.size() ? result : result + 1;
    }

    // 难理解
    // Exp: https://discuss.leetcode.com/topic/61338/what-are-the-odds-python-c/6
    // Time:	O(n)
    // Space:	O(n)
    int longestPalindrome1(string s) {
        unordered_map<char, int> char_map;
        for (char c : s)
            char_map[c] ^= 1;
        int odds = 0;
        for (auto &ele : char_map)
            odds += ele.second == 1;
        return s.size() - odds + (odds > 0);
    }
};