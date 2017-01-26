//Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
//
//If there are multiple solutions, return any subset is fine.
//
//Example 1:
//
//    nums: [1,2,3]
//
//    Result: [1,2] (of course, [1,3] will also be ok)
//Example 2:
//
//    nums: [1,2,4,8]
//
//    Result: [1,2,4,8]

#include <iostream>
#include <vector>

using namespace std;

class Solution_368 {
public:
    // Exp: https://discuss.leetcode.com/topic/49456/c-solution-with-explanations
    // Time:	O(n^2)
    // Space:	O(n)
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        vector<int> result;
        if (!nums.size()) return result;
        if (nums.size() == 1) return nums;
        sort(nums.begin(), nums.end());
        vector<int> T(nums.size(), 1);
        vector<int> parent(nums.size(), -1);

        int m = 0, m_index = -1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0 && T[i] < T[j] + 1) {
                    T[i] = T[j] + 1;
                    parent[i] = j;
                }
                if (m < T[i]) {
                    m = T[i];
                    m_index = i;
                }
            }
        }

        while (parent[m_index] != -1) {
            result.push_back(nums[m_index]);
            m_index = parent[m_index];
        }
        result.push_back(nums[m_index]);
        return result;
    }
};