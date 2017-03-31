//Given a collection of integers that might contain duplicates, nums, return all possible subsets.
//
//Note: The solution set must not contain duplicate subsets.
//
//For example,
//If nums = [1,2,2], a solution is:
//
//    [
//        [2],
//        [1],
//        [1,2,2],
//        [2,2],
//        [1,2],
//        []
//    ]

#include <iostream>
#include <vector>

using namespace std;

class Solution_090 {
public:
    // DFS
    // Time:	O(2^n)
    // Space:	O(2^n)
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> result;
        if (nums.empty()) return result;
        sort(nums.begin(), nums.end());
        vector<int> path;
        helper(nums, 0, path, result);
        return result;
    }

    void helper(vector<int> &nums, int start, vector<int> &path, vector<vector<int>> &result) {
        if (start == nums.size()) {
            result.push_back(path);
            return;
        }

        path.push_back(nums[start]);
        helper(nums, start + 1, path, result);
        path.pop_back();
        if (path.empty() || nums[start] != path.back())
            helper(nums, start + 1, path, result);
    }


    // Iterative
    // Exp:     https://discuss.leetcode.com/topic/4661/c-solution-and-explanation
    // Time:
    // Space:
    vector<vector<int>> subsetsWithDup_1(vector<int> &nums) {
        vector<vector<int>> result({{}});
        if (nums.empty()) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size();) {
            int j = i + 1;
            while (j < nums.size() && nums[j] == nums[j - 1])
                j++;
            int previousN = result.size();
            for (int k = 0; k < previousN; k++) {
                vector<int> ele(result[k]);
                for (int l = i; l < j; l++) {
                    ele.push_back(nums[l]);
                    result.push_back(ele);
                }
            }
            i = j;
        }
        return result;
    }
};


//int main() {
//    vector<vector<int>> result{{}};
//    cout << "result.empty():\t" << result.empty() << endl;
//    cout << "result.size():\t" << result.size() << endl;
//}