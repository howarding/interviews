//Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.
//
//Note:
//    The array size can be very large. Solution that uses too much extra space will not pass the judge.
//
//Example:
//
//    int[] nums = new int[] {1,2,3,3,3};
//    Solution solution = new Solution(nums);
//
//    // pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
//    solution.pick(3);
//
//    // pick(1) should return 0. Since in the array only nums[0] is equal to 1.
//    solution.pick(1);

#include <iostream>
#include <vector>

using namespace std;

// Do NOT use iterator, iterator will be destroyed after the constructor finishes.
// Exp: https://discuss.leetcode.com/topic/58301/simple-reservoir-sampling-solution
// Time:    O(n)
// Space:   O(1)
class Solution_398 {
    vector<int> nums_;
public:
    Solution_398(vector<int> nums) {
        nums_ = nums;
    }

    int pick(int target) {
        int count = 1, result = -1;
        for (int i = 0; i < nums_.size(); i++)
            if (nums_[i] == target && rand() % count++ == 0)
                result = i;
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */


//int main() {
//    vector<int> nums({1});
//    int target = 1;
//    Solution_398 sol(nums);
//    cout << sol.pick(target) << endl;
//}