//Given a 2D board and a list of words from the dictionary, find all words in the board.
//
//Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
//
//For example,
//    Given words = ["oath","pea","eat","rain"] and board =
//
//    [
//        ['o','a','a','n'],
//        ['e','t','a','e'],
//        ['i','h','k','r'],
//        ['i','f','l','v']
//    ]
//Return ["eat","oath"].
//Note:
//    You may assume that all inputs are consist of lowercase letters a-z.
//
//You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?
//
//If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.

#include <iostream>
#include <vector>

using namespace std;

class Solution_212 {
public:
    // Trie, Backtracking
    struct TrieNode {
        string word = "";
        vector<TrieNode *> child;

        TrieNode() : child(26) {}
    };

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        vector<string> result;
        if (board.empty()) return result;
        TrieNode *root = new TrieNode();
        for (string word : words)
            insert(root, word);
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                search(board, visit, root, i, j, result);
        return result;
    }

    void insert(TrieNode *root, string word) {
        for (char c : word) {
            if (!root->child[c - 'a'])
                root->child[c - 'a'] = new TrieNode();
            root = root->child[c - 'a'];
        }
        root->word = word;
    }

    void search(vector<vector<char>>& board, vector<vector<bool>>& visit, TrieNode *p, int i, int j,
                vector<string>& result) {
        int m = board.size(), n = board[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n) return;
        p = p->child[board[i][j] - 'a'];
        if (!p || visit[i][j]) return;
        if (!p->word.empty()) {
            result.push_back(p->word);
            p->word.clear();
        }
        visit[i][j] = true;
        search(board, visit, p, i + 1, j, result);
        search(board, visit, p, i - 1, j, result);
        search(board, visit, p, i, j + 1, result);
        search(board, visit, p, i, j - 1, result);
        visit[i][j] = false;
    }
};