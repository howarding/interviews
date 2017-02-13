//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
//For example,
//    If n = 4 and k = 2, a solution is:
//
//    [
//        [2,4],
//        [3,4],
//        [2,3],
//        [1,2],
//        [1,3],
//        [1,4],
//    ]

#include <iostream>
#include <vector>

using namespace std;

class Solution_077 {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> path;
        dfs(n, k, 1, 0, path, result);
        return result;
    }

    void dfs(int n, int k, int start, int num, vector<int> &path, vector<vector<int> > &result) {
        if (num == k) {
            result.push_back(path);
            return;
        }
        for (int i = start; i <= n; i++) {
            path.push_back(i);
            dfs(n, k, i + 1, num + 1, path, result);
            path.pop_back();
        }
    }
};