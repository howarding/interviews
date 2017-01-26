//Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.
//
//A string such as "word" contains only the following valid abbreviations:
//
//    ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
//Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".
//
//Note:
//    Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.
//
//Example 1:
//    Given s = "internationalization", abbr = "i12iz4n":
//
//    Return true.
//Example 2:
//    Given s = "apple", abbr = "a2e":
//
//    Return false.

#include <iostream>

using namespace std;

class Solution_408 {
public:
    // Exp: https://discuss.leetcode.com/topic/61348/short-and-easy-to-understand-java-solution
    // Time:	O(n)
    // Space:	O(1)
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < word.size() && j < abbr.size()) {
            if (word[i] == abbr[j]) {
                i++;
                j++;
                continue;
            }
            if (abbr[j] < '0' || abbr[j] > '9')
                return false;
            int start = j;
            while (j < abbr.size() && abbr[j] >= '0' && abbr[j] <= '9')
                j++;
            string num_str = abbr.substr(start, j - start);
            if (num_str[0] == '0')
                return false;
            i += stoi(num_str);
        }
        return (i == word.size() && j == abbr.size());
    }
};