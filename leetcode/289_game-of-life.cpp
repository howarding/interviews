//According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
//
//Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
//
//1. Any live cell with fewer than two live neighbors dies, as if caused by under-population.
//2. Any live cell with two or three live neighbors lives on to the next generation.
//3. Any live cell with more than three live neighbors dies, as if by over-population..
//4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
//Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.
//
//Example:
//
//Input:
//[
//[0,1,0],
//[0,0,1],
//[1,1,1],
//[0,0,0]
//]
//Output:
//[
//[0,0,0],
//[1,0,1],
//[0,1,1],
//[0,1,0]
//]
//Follow up:
//
//1. Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
//2. In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution_289 {
public:
    // Exp: https://discuss.leetcode.com/topic/26112/c-o-1-space-o-mn-time
    // Time:	O(mn)
    // Space:	O(1)
    void gameOfLife(vector<vector<int>> &board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i == 1 && j == 0)
                    cout << endl;
                int num = live_num(i, j, m, n, board);
                if (num > 4 && num < 8)
                    board[i][j] += 2;
            }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] /= 2;
    }

    int live_num(int i, int j, int m, int n, vector<vector<int>> &board) {
        int num = 0;
        for (int k = max(0, i - 1); k < min(i + 2, m); k++)
            for (int l = max(0, j - 1); l < min(j + 2, n); l++)
                if (k != i || l != j)
                    num += board[k][l] % 2;
        return board[i][j] % 2 + num * 2;
    }

    // Follow up 2: Infinite board solution
    // Exp: https://discuss.leetcode.com/topic/26236/infinite-board-solution
//    def gameOfLifeInfinite(self, live):
//        ctr = collections.Counter((I, J)
//        for i, j in live
//        for I in range(i-1, i+2)
//        for J in range(j-1, j+2)
//        if I != i or J != j)
//        return {ij
//            for ij in ctr
//            if ctr[ij] == 3 or ctr[ij] == 2 and ij in live}
//
//    def gameOfLife(self, board):
//        live = {(i, j) for i, row in enumerate(board) for j, live in enumerate(row) if live}
//        live = self.gameOfLifeInfinite(live)
//        for i, row in enumerate(board):
//            for j in range(len(row)):
//                row[j] = int((i, j) in live)

    void gameOfLifeInfinite(vector<vector<int>>& board) {
        vector<vector<int>> live;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j])
                    live.push_back({i, j});
        map<int, int> hist = update(board, live);
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++) {
                int ind = i * board.size() + j;
                board[i][j] = hist.find(ind) != hist.end() ? 1 : 0;
            }
    }

    map<int, int> update(vector<vector<int>>& board, vector<vector<int>>& live) {
        int m = board.size();
        map<int, int> hist;
        for (auto&& pair: live) {
            int i = pair[0], j = pair[1];
            for (int k = i - 1; k < i + 2; k++)
                for (int l = j - 1; l < j + 2; l++)
                    if (k != i || l != j)
                        hist[k * m + l]++;
        }
        for (auto&& pair: hist) {
            int i = pair.first / m, j = pair.first % m;
            int count = pair.second;
            if (board[i][j] && (count < 2 || count > 3))
                hist.erase(pair.first);
        }
        return hist;
    }
};


//int main() {
//    vector<vector<int> > a({{1}});
//    a = {{1, 1}, {1, 0}};
//    Solution_289 sol;
//    sol.gameOfLife(a);
//    int m = a.size(), n = a[0].size();
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++)
//            cout << a[i][j] << "\t";
//        cout << endl;
//    }
//}