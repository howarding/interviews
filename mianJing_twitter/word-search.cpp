//Given a 2D board and a word, find if the word exists in the grid.
//
//The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
//For example,
//    Given board =
//
//    [
//    ['A','B','C','E'],
//    ['S','F','C','S'],
//    ['A','D','E','E']
//    ]
//word = "ABCCED", -> returns true,
//word = "SEE", -> returns true,
//word = "ABCB", -> returns false.

#include <iostream>
#include <vector>

using namespace std;

class Solution_079 {
public:
    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visit(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, visit, word, 0, i, j))
                    return true;
        return false;
    }

    bool dfs(vector<vector<char>> &board, vector<vector<int>> &visit, string &word, int ind, int i, int j) {
        if (ind == word.size())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;
        if (visit[i][j])
            return false;
        if (board[i][j] != word[ind])
            return false;
        visit[i][j] = 1;
        bool ret = dfs(board, visit, word, ind + 1, i + 1, j) ||
                   dfs(board, visit, word, ind + 1, i - 1, j) ||
                   dfs(board, visit, word, ind + 1, i, j + 1) ||
                   dfs(board, visit, word, ind + 1, i, j - 1);
        visit[i][j] = 0;
        return ret;
    }





    //    2. Given words = ["oath","pea","eat","rain"] and board =
    //
    //    [
    //        ['o','a','a','n'],
    //        ['e','t','a','e'],
    //        ['i','h','k','r'],
    //        ['i','f','l','v']
    //    ]
    //Return ["eat","oath"].

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