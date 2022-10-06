//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//For example:
//Given array A = [2,3,1,1,4]
//
//The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
//
//Note:
//You can assume that you can always reach the last index.

#include <iostream>
#include <vector>

using namespace std;

class Solution_045 {
public:
    // BFS
    // Exp: https://discuss.leetcode.com/topic/3191/o-n-bfs-solution/15
    // Time:	O(n)
    // Space:	O(1)
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int i = 0, current_reach = 0, next_reach = 0, level = 0;
        while (current_reach < nums.size() - 1) {
            for (; i <= current_reach; i++)
                next_reach = max(next_reach, nums[i] + i);
            if (next_reach == current_reach) return INT_MAX;    //***cannot move forward from this level
            level++;
            current_reach = next_reach;
        }
        return level;
    }



    // DP (My own)
    // Time:	O(n^2)
    // Space:	O(n)
    int jump1(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> jumps(nums.size(), INT_MAX);
        jumps[0] = 0;
        for (int i = 1; i < nums.size(); i++)
            for (int j = 0; j < i; j++)
                if (nums[j] + j >= i)
                    jumps[i] = min(jumps[j] + 1, jumps[i]);
        return jumps[jumps.size() - 1];
    }
};


//int main() {
//    Solution_045 sol;
//    vector<int> nums({2,3,1,1,4});
////    cout << sol.jump(nums) << endl;
//    cout << sol.jump1(nums) << endl;
//}