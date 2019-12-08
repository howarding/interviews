//In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not
// connected to any other 1s.)
//Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.
//Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)
//
//Example 1:
//    Input: [[0,1],[1,0]]
//    Output: 1
//
//Example 2:
//    Input: [[0,1,0],[0,0,0],[0,0,1]]
//    Output: 2
//
//Example 3:
//    Input: [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
//    Output: 1
//
//Note:
//    1 <= A.length = A[0].length <= 100
//    A[i][j] == 0 or A[i][j] == 1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution_934 {
public:
    // DFS & BFS
    // https://leetcode.com/problems/shortest-bridge/discuss/189293/C%2B%2B-BFS-Island-Expansion-%2B-UF-Bonus
    // Time:    O(mn)
    // Space:   O(mn)
    int shortestBridge(vector<vector<int>>& A) {
        vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        bool found = false;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[0].size(); j++) {
                found = paint(A, i, j, directions);
                if (found) break;
            }
            if (found) break;
        }
        cout << "found:\t" << found << endl;

        for (int ct = 2; ; ct++)
            for (int i = 0; i < A.size(); i++)
                for (int j = 0; j < A[0].size(); j++)
                    if (A[i][j] == ct && (expand(A, i - 1, j, ct) || expand(A, i + 1, j, ct) ||
                    expand(A, i, j - 1, ct) || expand(A, i, j + 1, ct)))
                        return ct - 2;
    }

    // DFS
    bool paint(vector<vector<int>>& A, int i , int j, vector<vector<int>>& directions) {
        if (i < 0 || i == A.size() || j < 0 || j == A[0].size() || A[i][j] == 0) return false;
        if (A[i][j] == 2) return true;
        A[i][j] = 2;
        for (vector<int>& dir: directions) paint(A, i + dir[0], j + dir[1], directions);
        return true;
    }

    // BFS
    bool expand(vector<vector<int>>& A, int i, int j, int ct) {
        if (i < 0 || i == A.size() || j < 0 || j == A[0].size() || A[i][j] > 1) return false;
        if (A[i][j] == 0) A[i][j] = ct + 1;
        return A[i][j] == 1;
    }
};


//int main() {
//    Solution_934 sol;
//    vector<vector<int>> A{{0, 1}, {1, 0}};
//    int result = sol.shortestBridge(A);
//    cout << result << endl;
//}