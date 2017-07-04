//Given an unsorted integer array, find the first missing positive integer.
//
//For example,
//Given [1,2,0] return 3,
//and [3,4,-1,1] return 2.
//
//Your algorithm should run in O(n) time and uses constant space.

#include <iostream>
#include <vector>

using namespace std;

class Solution_041 {
public:
    // Exp: https://discuss.leetcode.com/topic/8293/my-short-c-solution-o-1-space-and-o-n-time
    // Time:	O(n)
    // Space:	O(1)
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i + 1)
                return i + 1;
        return nums.size() + 1;
    }
};


//int main() {
//    Solution_041 sol;
//    vector<int> nums({3,4,-1,1});
//    cout << sol.firstMissingPositive(nums) << endl;
//}