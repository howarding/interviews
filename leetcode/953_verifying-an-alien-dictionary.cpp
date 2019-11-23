//In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The
// order of the alphabet is some permutation of lowercase letters.
//
//Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if
// the given words are sorted lexicographicaly in this alien language.
//
//
//
//Example 1:
//
//    Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
//    Output: true
//    Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
//Example 2:
//
//    Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
//    Output: false
//    Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
//Example 3:
//
//    Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
//    Output: false
//    Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to
//    lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is
//    less than any other character (More info).
//
//
//Note:
//
//    1. 1 <= words.length <= 100
//    2. 1 <= words[i].length <= 20
//    3. order.length == 26
//    4. All characters in words[i] and order are english lowercase letters.

#include <iostream>
#include <vector>

using namespace std;

class Solution_953 {
public:
    // HashMap (Array)
    // https://leetcode.com/articles/verifying-an-alien-dictionary/
    // Time:    O(C)    C: total content of words
    // Space:   O(1)
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() < 2) return true;
        vector<int> index(26, 0);
        for (int i = 0; i < order.size(); i++)
            index[order[i] - 'a'] = i;
        for (int i = 1; i < words.size(); i++) {
            int m = words[i - 1].size(), n = words[i].size(), j = 0;
            while (j < min(m, n)) {
                if (index[words[i - 1][j] - 'a'] > index[words[i][j] - 'a']) return false;
                if (index[words[i - 1][j] - 'a'] < index[words[i][j] - 'a']) break;
                j++;
            }
            if (j == min(m, n) && m > n) return false;
        }
        return true;
    }
};


//int main() {
//    Solution_953 sol;
//    vector<string> words{"hello","leetcode"};
//    string order = "hlabcdefgijkmnopqrstuvwxyz";
//    cout << sol.isAlienSorted(words, order) << endl;
//}