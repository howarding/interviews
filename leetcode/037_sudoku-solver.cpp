//Write a program to solve a Sudoku puzzle by filling the empty cells.
//
//Empty cells are indicated by the character '.'.
//
//You may assume that there will be only one unique solution.
//
//
//A sudoku puzzle...
//
//
//...and its solution numbers marked in red.

#include <iostream>
#include <vector>

using namespace std;

class Solution_037 {
public:
    // Backtracking
    // Exp: https://discuss.leetcode.com/topic/11327/straight-forward-java-solution-using-backtracking
    // Time:	O(n^2)
    // Space:	O(n^2)
    void solveSudoku(vector<vector<char>>& board) {
        if (board.empty()) return;
        vector<vector<bool>> row(vector<vector<bool>>(9, vector<bool>(9, false)));
        vector<vector<bool>> column(vector<vector<bool>>(9, vector<bool>(9, false)));
        vector<vector<bool>> box(vector<vector<bool>>(9, vector<bool>(9, false)));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int k = i / 3 * 3 + j / 3;
                    row[i][num] = column[j][num] = box[k][num] = true;
                }
        solve(board, row, column, box, 0, 0);
    }

    bool solve(
            vector<vector<char>>& board,
            vector<vector<bool>>& row,
            vector<vector<bool>>& column,
            vector<vector<bool>>& box,
            int m,
            int n
    ) {
        if (m == board.size()) return true;
        int next_m = n == board[0].size() - 1 ? m + 1 : m;
        int next_n = n == board[0].size() - 1 ? 0 : n + 1;
        if (board[m][n] != '.') return solve(board, row, column, box, next_m, next_n);
        int k = m / 3 * 3 + n / 3;
        for (char c = '1'; c <= '9'; c++) {
            if (row[m][c-'1'] || column[n][c-'1'] || box[k][c-'1'])
                continue;
            board[m][n] = c;
            row[m][c-'1'] = column[n][c-'1'] = box[k][c-'1'] = true;
            if (solve(board, row, column, box, next_m, next_n)) return true;
            board[m][n] = '.';
            row[m][c-'1'] = column[n][c-'1'] = box[k][c-'1'] = false;
        }
        return false;
    }
};