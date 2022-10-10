//Given a collection of distinct numbers, return all possible permutations.
//
//For example,
//[1,2,3] have the following permutations:
//    [
//        [1,2,3],
//        [1,3,2],
//        [2,1,3],
//        [2,3,1],
//        [3,1,2],
//        [3,2,1]
//    ]

#include <iostream>
#include <vector>

using namespace std;

class Solution_046 {
public:
    // Backtrack
    // Exp: https://leetcode.com/problems/permutations/solutions/222300/permutations/
    // Time:	O(sum_{k}{P(n,k)})
    // Space:	O(n!)
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(nums, 0, path, result);
        return result;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            path.push_back(nums[start]);
            backtrack(nums, start + 1, path, result);
            swap(nums[start], nums[i]);
            path.pop_back();
        }
    }



    //////////////////////////////////////////////
    // Google 输入是数字
    vector<vector<int>> permute(int num) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(num, path, result);
        return result;
    }

    void dfs(int num, vector<int>& path, vector<vector<int>>& result) {
        if (path.size() == num) {
            result.push_back(path);
            return;
        }
        for (int i = 1; i <= num; i++) {
            vector<int>::iterator iter = find(path.begin(), path.end(), i);
            if (iter == path.end()) {
                path.push_back(i);
                dfs(num, path, result);
                path.pop_back();
            }
        }
    }
};


//int main() {
//    Solution_046 sol;
//    int num = 5;
//    vector<vector<int>> result(sol.permute(num));
//    for (auto&& path: result) {
//        for (int& n: path)
//            cout << n << "\t";
//        cout << endl;
//    }
//}