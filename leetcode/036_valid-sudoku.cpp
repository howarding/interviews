//Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
//
//A partially filled sudoku which is valid.
//
//Note:
//A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

#include <iostream>
#include <vector>

using namespace std;

class Solution_036 {
public:
    // Exp: https://discuss.leetcode.com/topic/8241/my-short-solution-by-c-o-n2
    // Time:	O(n^2)
    // Space:	O(n^2)
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(vector<vector<bool>>(9, vector<bool>(9, false)));
        vector<vector<bool>> column(vector<vector<bool>>(9, vector<bool>(9, false)));
        vector<vector<bool>> box(vector<vector<bool>>(9, vector<bool>(9, false)));
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int k = i / 3 * 3 + j / 3;
                    if (row[i][num] || column[j][num] || box[k][num]) return false;
                    row[i][num] = column[j][num] = box[k][num] = true;
                }
        return true;
    }
};