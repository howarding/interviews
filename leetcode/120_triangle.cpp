//Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
//For example, given the following triangle
//[
//     [2],
//    [3,4],
//   [6,5,7],
//  [4,1,8,3]
//]
//The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
//Note:
//Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

#include <iostream>
#include <vector>

using namespace std;

class Solution_120 {
public:
    // DP
    // Exp: https://discuss.leetcode.com/topic/1669/dp-solution-for-triangle
    // Time:	O(n)
    // Space:	O(1)
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> result(triangle[n-1]);
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                result[j] = min(result[j], result[j+1]) + triangle[i][j];
        return result[0];
    }
};