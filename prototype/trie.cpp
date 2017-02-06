#include <iostream>
#include <vector>

#define N 26
using namespace std;

struct TrieNode {
    bool isEnd;
    char val;
    vector<TrieNode *> child;

    TrieNode(char c, int n) : isEnd(false), val(c), child(n) {}
};


// insert a string
void insertStr(TrieNode *root, string &s) {
    if (!root) {
        root = new TrieNode('\0', N);
        root->isEnd = true;
    }
    for (char c : s) {
        int ind = c - 'a';
        if (!root->child[ind])
            root->child[ind] = new TrieNode(c, N);
        root = root->child[ind];
    }
    root->isEnd = true;
}

// Search a string. Iterative
bool searchStr(TrieNode *root, string &s) {
    if (!root) return false;
    for (char c : s) {
        int ind = c - 'a';
        if (!root->child[ind]) return false;
        root = root->child[ind];
    }
    return root->isEnd;
}


// Erase a string from Trie.
bool erase(TrieNode *root, string &s) {

}