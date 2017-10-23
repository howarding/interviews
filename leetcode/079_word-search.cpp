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
    // Exp: https://discuss.leetcode.com/topic/77865/concise-java-solution
    // Time:	O(mn * 4^k)     k: length of word
    // Space:	O(1)
    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visit(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                // if (dfs(board, visit, word, 0, i, j))
                if (dfs(board, word, 0, i, j))
                    return true;
        return false;
    }

    // No more space, but board is changed.
    bool dfs(vector<vector<char>> &board, string &word, int ind, int i, int j) {
        if (ind == word.size())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;
        if (board[i][j] != word[ind])
            return false;
        char c = board[i][j];
        board[i][j] = '#';
        bool ret = dfs(board, word, ind + 1, i + 1, j) ||
                   dfs(board, word, ind + 1, i - 1, j) ||
                   dfs(board, word, ind + 1, i, j + 1) ||
                   dfs(board, word, ind + 1, i, j - 1);
        board[i][j] = c;
        return ret;
    }

    // Space: O(mn)
    // board is not changed.
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
};