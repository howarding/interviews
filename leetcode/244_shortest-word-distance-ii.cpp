//This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?
//
//Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.
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
#include <unordered_map>

using namespace std;

// Hash Table (My own)
// Time:	O(n)
// Space:	O(n)
class WordDistance {
    unordered_map<string, vector<int>> dict;
public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); i++)
            dict[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        int result = INT_MAX;
        int ind1(0), ind2(0);
        while (ind1 < dict[word1].size() && ind2 < dict[word2].size()) {
            result = min(result, abs(dict[word1][ind1] - dict[word2][ind2]));
            if (dict[word1][ind1] <= dict[word2][ind2])
                ind1++;
            else
                ind2++;
        }
        return result;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */