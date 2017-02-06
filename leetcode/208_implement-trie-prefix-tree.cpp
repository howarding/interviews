//Implement a trie with insert, search, and startsWith methods.
//
//Note:
//You may assume that all inputs are consist of lowercase letters a-z.

#include <iostream>
#include <vector>

using namespace std;

// My own
// Exp: https://discuss.leetcode.com/topic/13463/maybe-the-code-is-not-too-much-by-using-next-26-c
// Time:
// Space:
class Trie {
    struct TrieNode {
        bool isEnd;
        vector<TrieNode *> child;

        TrieNode(int n) : isEnd(false), child(n) {}
    };

    int N = 26;
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode(N);
        root->isEnd = true;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.empty()) return;
        if (root->isEnd) root->isEnd = false;
        TrieNode *p = root;
        for (char c : word) {
            if (!p->child[c - 'a'])
                p->child[c - 'a'] = new TrieNode(N);
            p = p->child[c - 'a'];
        }
        p->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for (char c : word) {
            if (!p->child[c - 'a']) return false;
            p = p->child[c - 'a'];
        }
        return p->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (char c : prefix) {
            if (!p->child[c - 'a']) return false;
            p = p->child[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */