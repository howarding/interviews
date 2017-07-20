//Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
//
//For example,
//Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//
//Given word1 = “coding”, word2 = “practice”, return 3.
//Given word1 = "makes", word2 = "coding", return 1.
//
//Note:
//You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

#include <iostream>
#include <vector>

using namespace std;

class Solution_243 {
public:
    // My own
    // Time:	O(n)
    // Space:	O(1)
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int ind1(-1), ind2(-1), result(INT_MAX);
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) ind1 = i;
            if (words[i] == word2) ind2 = i;
            if (ind1 >= 0 && ind2 >= 0)
                result = min(result, abs(ind1 - ind2));
        }
        return result;
    }
};