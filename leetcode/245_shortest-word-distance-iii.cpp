//This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.
//
//Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
//
//word1 and word2 may be the same and they represent two individual words in the list.
//
//For example,
//Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//
//Given word1 = “makes”, word2 = “coding”, return 1.
//Given word1 = "makes", word2 = "makes", return 3.
//
//Note:
//You may assume word1 and word2 are both in the list.

#include <iostream>
#include <vector>

using namespace std;

class Solution_245 {
public:
    // My own
    // Time:	O(n)
    // Space:	O(1)
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int ind1(-1), ind2(-1), pre(-1), result(INT_MAX);
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) ind1 = i;
            if (words[i] == word2) ind2 = i;
            if (word1 != word2 && ind1 >= 0 && ind2 >= 0)
                result = min(result, abs(ind1 - ind2));
            if (word1 == word2 && pre >= 0 && ind1 > pre)
                result = min(result, ind1 - pre);
            pre = ind1;
        }
        return result;
    }
};