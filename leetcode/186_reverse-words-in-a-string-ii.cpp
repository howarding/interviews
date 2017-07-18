//Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
//
//The input string does not contain leading or trailing spaces and the words are always separated by a single space.
//
//For example,
//        Given s = "the sky is blue",
//return "blue is sky the".
//
//Could you do it in-place without allocating extra space?
//
//Related problem: Rotate Array

#include <iostream>

using namespace std;

class Solution_186 {
public:
    // reverse whole string, then reverse each word.
    // LC 151
    // Time:	O(n)
    // Space:	O(1)
    void reverseWords(string &s) {
        if (s.empty()) return;
        reverse(s.begin(), s.end());
        int start = 0;
        for (int i = 1; i < s.size(); i++) {
            while (i < s.size() && s[i] != ' ') i++;
            reverse(s.begin()+start, s.begin() + i);
            start = i + 1;
        }
    }
};