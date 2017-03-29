//A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
//    'A' -> 1
//    'B' -> 2
//    ...
//    'Z' -> 26
//Given an encoded message containing digits, determine the total number of ways to decode it.
//
//For example,
//    Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//
//The number of ways decoding "12" is 2.

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution_091 {
public:
    // DP, Iterative    BEST
    // Exp: https://discuss.leetcode.com/topic/7025/a-concise-dp-solution
    // Time:    O(n)
    // Space:    O(1)
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int curr = 1, prev = 1;
        for (int i = 1; i < s.size(); i++) {
            int tmp = curr;
            if (s[i] == '0') curr = 0;
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
                curr += prev;
            prev = tmp;
        }
        return curr;
    }


    // Recursive, HashTable to avoid duplicate computations
    // Time:    O(n)
    // Space:    O(n)
    int numDecodings1(string s) {
        if (s.empty() || s[0] == '0') return 0;
        unordered_map<int, int> dict;
        dict[0] = 1;
        return helper(s, s.size() - 1, dict);
    }

    int helper(string &s, int ind, unordered_map<int, int> &dict) {
        if (dict.find(ind) != dict.end()) return dict[ind];
        int result = s[ind] == '0' ? 0 : helper(s, ind - 1, dict);
        if (s[ind - 1] == '1' || (s[ind - 1] == '2' && s[ind] <= '6'))
            result += ind == 1 ? 1 : helper(s, ind - 2, dict);
        dict[ind] = result;
        return result;
    }


    // 把input的string里面加上一些*符号，这些*符号可以代表0~9之间任意一个数字，求此时的decode ways
    // 2* 可以decode成 ‘2’+‘0’ ~ ‘9’ （共九种）或者 ‘20’ ~‘26’ （共七种, 返回16
    // DP, Iterative
    // Time:    O(n)
    // Space:    O(1)
    int numDecodings_fbfu2(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int curr = 1, prev = 1;
        for (int i = 1; i < s.size(); i++) {
            int tmp = curr;
            // s[i] as a single number
            if (s[i] == '0') curr = 0;
                // * means s[i] can be 9 diff numbers.
            else if (s[i] == '*') curr *= 9;
            curr += prev * numTwoChars(s[i - 1], s[i]); // s[i-1], s[i] together as 1 number
            prev = tmp;
        }
        return curr;
    }

    // compute #ways to decode 'ab' as one number
    int numTwoChars(char a, char b) {
        if (a == '*') return numTwoChars('1', b) + numTwoChars('2', b);
        if (b == '*') {
            if (a == '1') return 10;
            if (a == '2') return 7;
        }
        if (a == '1' || (a == '2' && b <= '6')) return 1;
        return 0;
    }
};