//The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//Given an integer n, return all distinct solutions to the n-queens puzzle.
//
//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//
//For example,
//There exist two distinct solutions to the 4-queens puzzle:
//
//    [
//        [".Q..",  // Solution 1
//        "...Q",
//        "Q...",
//        "..Q."],
//
//        ["..Q.",  // Solution 2
//        "Q...",
//        "...Q",
//        ".Q.."]
//    ]

#include <iostream>
#include <vector>

using namespace std;

class Solution_051 {
public:
    // Exp: https://discuss.leetcode.com/topic/13617/accepted-4ms-c-solution-use-backtracking-and-bitmask-easy-understand
    // Time:	O(n^2)
    // Space:	O(n)
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        if (n <= 0) return result;
        if (n == 1) return {{"Q"}};
        vector<bool> row(n, false);
        vector<bool> column(n, false);
        vector<bool> slash(2 * n - 1, false);
        vector<bool> anti_slash(2 * n - 1, false);
        vector<string> path(n, string(n, '.'));
        helper(n, path, row, column, slash, anti_slash, 0, result);
        return result;
    }


    void helper(
        int n,
        vector<string>& path,
        vector<bool>& row,
        vector<bool>& column,
        vector<bool>& slash,
        vector<bool>& anti_slash,
        int x,
        vector<vector<string>>& result
    ) {
        if (x == n) {
            result.push_back(path);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (row[x] || column[j] || slash[x+j] || anti_slash[n-1+x-j])
                continue;
            path[x][j] = 'Q';
            row[x] = column[j] = slash[x+j] = anti_slash[n-1+x-j] = true;
            helper(n, path, row, column, slash, anti_slash, x + 1, result);
            path[x][j] = '.';
            row[x] = column[j] = slash[x+j] = anti_slash[n-1+x-j] = false;
        }
    }
};


//int main() {
//    Solution_051 sol;
//    int n = 3;
//    vector<vector<string>> result(sol.solveNQueens(n));
//    for (auto&& path : result) {
//        for (string& s : path)
//            cout << s << endl;
//        cout << endl;
//    }
//}