//Write a function that takes a string as input and reverse only the vowels of a string.
//
//Example 1:
//    Given s = "hello", return "holle".
//
//Example 2:
//    Given s = "leetcode", return "leotcede".
//
//Note:
//    The vowels does not include the letter "y".

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // Exp: My own method, takes time. 56ms
    // Time:	O(n)
    // Space:	O(n)
    string reverseVowels(string s) {
        string result;
        if (s.empty()) return result;
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        vector<char> chars;
        for (char c : s)
            chars.push_back(c);
        int i = 0, j = chars.size() - 1;
        while (i <= j) {
            if (vowels.find(chars[i]) != vowels.end() && vowels.find(chars[j]) != vowels.end()) {
                swap(chars[i++], chars[j--]);
                continue;
            }
            if (vowels.find(chars[i]) == vowels.end())
                i++;
            if (vowels.find(chars[j]) == vowels.end())
                j--;
        }
        for (char c : chars)
            result += c;
        return result;
    }


    // Exp: https://discuss.leetcode.com/topic/43418/c-easy-understanding-solution
    // Time:	O(n) 12ms
    // Space:	O(1)
    string reverseVowels_1(string s) {
        int dict[256] = {0};
        dict['a'] = 1, dict['A'] = 1;
        dict['e'] = 1, dict['E'] = 1;
        dict['i'] = 1, dict['I'] = 1;
        dict['o'] = 1, dict['O'] = 1;
        dict['u'] = 1, dict['U'] = 1;
        int start = 0, end = (int) s.size() - 1;
        while (start < end) {
            while (start < end && dict[s[start]] == 0) start++;
            while (start < end && dict[s[end]] == 0) end--;
            swap(s[start], s[end]);
            start++;
            end--;
        }
        return s;
    }
};