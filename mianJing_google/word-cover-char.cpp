//给两个set，一个里面是word，一个里面是characters，判断是不是每个word都cover character set里面的任意一个character
//    比如 char_set = {a,b,c} word_set1 = {apple, big, because} word_set2 = {apple, big, because, google}。word_set1就满足，word_set2就不行因为google里面不含有char_set里面的值

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution_wcc {
    // Time:    word_set: M words, k length of word
    //          char_set: N chars
    //          O(M*k+N)
    bool wordCoverChar(unordered_set<string> &word_set, unordered_set<char> &char_set) {
        unordered_set<char> word_char_set;
        for (string word : word_set)
            for (char c : word)
                word_char_set.insert(c);
        if (word_char_set.size() < char_set.size()) return false;
        for (char c : char_set)
            if (word_char_set.find(c) == word_char_set.end())
                return false;
        return true;
    }
};