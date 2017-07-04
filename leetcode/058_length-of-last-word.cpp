//Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a character sequence consists of non-space characters only.
//
//For example,
//Given s = "Hello World",
//return 5.

#include <iostream>

using namespace std;

class Solution_058 {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int end = s.size() - 1;
        while (end >= 0 && s[end] == ' ')
            end--;
        if (end < 0) return 0;
        int start = end;
        while (start >= 0 && s[start] != ' ')
            start--;
        return end - start;
    }
};