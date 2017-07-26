//Numbers can be regarded as product of its factors. For example,
//
//    8 = 2 x 2 x 2;
//      = 2 x 4.
//Write a function that takes an integer n and return all possible combinations of its factors.
//
//Note:
//    1. You may assume that n is always positive.
//    2. Factors should be greater than 1 and less than n.
//Examples:
//input: 1
//output:
//    []
//input: 37
//output:
//    []
//input: 12
//output:
//    [
//      [2, 6],
//      [2, 2, 3],
//      [3, 4]
//    ]
//input: 32
//output:
//    [
//      [2, 16],
//      [2, 2, 8],
//      [2, 2, 2, 4],
//      [2, 2, 2, 2, 2],
//      [2, 4, 4],
//      [4, 8]
//    ]

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution_254 {
public:
    // Exp: https://discuss.leetcode.com/topic/21082/my-recursive-dfs-java-solution
    // Time:	O(n)
    // Space:	O(n)
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        if (n == 1) return result;
        vector<int> path;
        helper(n, 2, path, result);
        return result;
    }


    void helper(int n, int start, vector<int>& path, vector<vector<int>>& result) {
        if (n == 1) {
            if (path.size() > 1)
                result.push_back(path);
            return;
        }
        for (int i = start; i <= n; i++)
            if (n % i == 0) {
                path.push_back(i);
                helper(n / i, i, path, result);
                path.pop_back();
            }
    }
};



//int main() {
//    Solution_254 sol;
//    int n = 12;
//    vector<vector<int>> result(sol.getFactors(n));
//    for (auto&& path : result) {
//        for (int n : path)
//            cout << n << '\t';
//        cout << endl;
//    }
//}