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
    // HashMap
    // Time:	O(n)
    // Space:	O(1)
    string reverseVowels(string s) {
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            if (vowels.find(s[i]) == vowels.end()) i++;
            else if (vowels.find(s[j]) == vowels.end()) j--;
            else swap(s[i++], s[j--]);
        }
        return s;
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