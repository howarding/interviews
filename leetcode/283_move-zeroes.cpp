//Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//
//For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
//
//Note:
//    You must do this in-place without making a copy of the array.
//    Minimize the total number of operations.

#include <iostream>
#include <vector>

using namespace std;

class Solution_283 {
public:
    // 2Pointers
    // Exp: https://discuss.leetcode.com/topic/24716/simple-o-n-java-solution-using-insert-index
    // Time:	O(n)
    // Space:	O(1)
    void moveZeroes(vector<int> &nums) {
        if (nums.empty()) return;
        int insertPos = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i])
                swap(nums[i], nums[insertPos++]);
    }


    // Move zeros and return the count of non-zeros elements. The order of non-zero elements does not matter.
    int moveZeroes_fb(vector<int> &nums) {
        if (nums.empty()) return 0;
        int insertPos = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i])
                swap(nums[i], nums[insertPos++]);
        return insertPos;
    }
};


//int main() {
//    Solution_283 sol;
//    vector<int> nums({1, 0, 0, 1, 0, 3, 0, 0, 5, 6});
//    cout << sol.moveZeroes_fb(nums) << endl;
//}