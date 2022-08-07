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
    // Backtrack
    // Exp: https://discuss.leetcode.com/topic/11327/straight-forward-java-solution-using-backtracking
    // Time:	O(n^2)
    // Space:	O(n^2)
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> columns(9, vector<bool>(9, false));
        vector<vector<bool>> boxes(9, vector<bool>(9, false));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int k = i / 3 * 3 + j / 3;
                    rows[i][num] = columns[j][num] = boxes[k][num] = true;
                }
        solve(0, board, rows, columns, boxes);
    }

    bool solve(int k, vector<vector<char>>& board, vector<vector<bool>>& rows, vector<vector<bool>>& columns, vector<vector<bool>>& boxes) {
        if (k == board.size() * board[0].size()) return true;
        int m = k / 9, n = k % 9;
        int l = m / 3 * 3 + n / 3;
        if (board[m][n] != '.') return solve(k + 1, board, rows, columns, boxes);
        for (int i = 0; i < 9; i++) {
            if (rows[m][i] || columns[n][i] || boxes[l][i])
                continue;
            board[m][n] = i + '1';
            rows[m][i] = columns[n][i] = boxes[l][i] = true;
            if (solve(k + 1, board, rows, columns, boxes)) return true;
            board[m][n] = '.';
            rows[m][i] = columns[n][i] = boxes[l][i] = false;
        }
        return false;
    }
};

//int main() {
//    Solution_037 solution037;
//    vector<vector<char>> board{
//        {'5','3','.','.','7','.','.','.','.'},
//        {'6','.','.','1','9','5','.','.','.'},
//        {'.','9','8','.','.','.','.','6','.'},
//        {'8','.','.','.','6','.','.','.','3'},
//        {'4','.','.','8','.','3','.','.','1'},
//        {'7','.','.','.','2','.','.','.','6'},
//        {'.','6','.','.','.','.','2','8','.'},
//        {'.','.','.','4','1','9','.','.','5'},
//        {'.','.','.','.','8','.','.','7','9'}
//    };
//
//    solution037.solveSudoku(board);
//    for (auto&& line: board) {
//        for (auto c: line)
//            cout << c << "  ";
//        cout << endl;
//    }
//}