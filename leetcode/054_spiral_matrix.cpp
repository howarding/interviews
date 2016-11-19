//Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
//For example,
//    Given the following matrix:
//
//[
//[ 1, 2, 3 ],
//[ 4, 5, 6 ],
//[ 7, 8, 9 ]
//]
//You should return [1,2,3,6,9,8,7,4,5].

#include <iostream>
#include <vector>

using namespace std;


class Solution_054 {
public:
    // Exp: https://discuss.leetcode.com/topic/3713/super-simple-and-easy-to-understand-solution
    // Time:	O(m*n)
    // Space:	O(m*n)
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        int m = matrix.size(), n = matrix[0].size();
        int x0 = 0, x1 = m - 1;
        int y0 = 0, y1 = n - 1;
        while (x0 <= x1 && y0 <= y1) {
            for (int j = y0; j <= y1; j++)
                result.push_back(matrix[x0][j]);
            x0++;
            for (int i = x0; i <= x1; i++)
                result.push_back(matrix[i][y1]);
            y1--;
            if (x0 > x1) break;
            for (int j = y1; j >= y0; j--)
                result.push_back(matrix[x1][j]);
            x1--;
            if (y0 > y1) break;
            for (int i = x1; i >= x0; i--)
                result.push_back(matrix[i][y0]);
            y0++;
        }
        return result;
    }
};


//int main() {
//    Solution_054 sol;
////    vector<vector<int> > matrix({{1,2,3}, {4,5,6}, {7,8,9}});
//    vector<vector<int> > matrix({{2,3}});
//    vector<int> result(sol.spiralOrder(matrix));
//    for (int i = 0; i < result.size(); i++)
//        cout << result[i] << "\t";
//    cout << endl;
//}