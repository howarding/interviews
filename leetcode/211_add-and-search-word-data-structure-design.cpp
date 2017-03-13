//Design a data structure that supports the following two operations:
//
//    void addWord(word)
//    bool search(word)
//search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
//
//For example:
//
//    addWord("bad")
//    addWord("dad")
//    addWord("mad")
//    search("pad") -> false
//    search("bad") -> true
//    search(".ad") -> true
//    search("b..") -> true
//Note:
//You may assume that all words are consist of lowercase letters a-z.
//
//click to show hint.
//
//You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.

#include <iostream>
#include <vector>

using namespace std;

// DFS
// Exp: https://discuss.leetcode.com/topic/15581/80ms-clear-c-code-with-detailed-explanations
// Time:	O(n)
// Space:	O(1)
class WordDictionary {
    struct TrieNode {
        bool isEnd;
        vector<TrieNode *> child;

        TrieNode(int n) : isEnd(false), child(n) {}
    };

    TrieNode *root;
    int N = 26;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode(N);
        root->isEnd = true;
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        if (word.empty()) return;
        if (root->isEnd) root->isEnd = false;
        TrieNode *node = root;
        for (char c : word) {
            if (!node->child[c - 'a'])
                node->child[c - 'a'] = new TrieNode(N);
            node = node->child[c - 'a'];
        }
        node->isEnd = true;
    }

    // DFS
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchString(root, word, 0);
    }

    bool searchString(TrieNode *node, string &word, int i) {
        if (i == word.size())
            return node->isEnd;
        if (word[i] != '.')
            return node->child[word[i] - 'a'] ? searchString(node->child[word[i] - 'a'], word, i + 1) : false;
        for (TrieNode *p : node->child)
            if (p && searchString(p, word, i + 1))
                return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */