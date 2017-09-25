//Given an input string, reverse the string word by word.
//
//For example,
//Given s = "the sky is blue",
//return "blue is sky the".
//
//Update (2015-02-12):
//For C programmers: Try to solve it in-place in O(1) space.
//
//click to show clarification.
//
//Clarification:
//What constitutes a word?
//A sequence of non-space characters constitutes a word.
//Could the input string contain leading or trailing spaces?
//Yes. However, your reversed string should not contain leading or trailing spaces.
//How about multiple spaces between two words?
//Reduce them to a single space in the reversed string.

#include <iostream>

using namespace std;

class Solution_151 {
public:
    // reverse the string, then reverse each word.
    // Time:	O(n)
    // Space:	O(1)
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int start = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] != ' ') {
                if (start) s[start++] = ' ';    // only leave one single space
                int j = i;      // j: end point of current word
                while (j < s.size() && s[j] != ' ') s[start++] = s[j++]; // shift word to the left
                reverse(s.begin() + start - (j - i), s.begin() + start); // reverse
                i = j;
            }
        s.erase(start);
    }
};