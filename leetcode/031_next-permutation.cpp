//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
//The replacement must be in-place, do not allocate extra memory.
//
//Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//1,2,3 → 1,3,2
//3,2,1 → 1,2,3
//1,1,5 → 1,5,1

#include <iostream>
#include <vector>

using namespace std;


class Solution_031 {
public:
    // Exp: https://discuss.leetcode.com/topic/2542/share-my-o-n-time-solution
    // Time:	O(n)
    // Space:	O(1)
    void nextPermutation(vector<int> &nums) {
        if (nums.size() < 2) return;
        int i = nums.size() - 1, j;
        while (i > 0 && nums[i - 1] >= nums[i])
            i--;
        if (i > 0) {
            for (j = i; j < nums.size() && nums[i - 1] < nums[j]; j++);
            swap(nums, i - 1, j - 1);
        }
        reverse(nums.begin() + i, nums.end());
    }

    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};


//int main() {
////    vector<int> nums = {1, 2, 3};
//    vector<int> nums = {3, 2, 1};
////    vector<int> nums = {1, 1, 5};
//    Solution_031 sol;
//    sol.nextPermutation(nums);
//    for (int i = 0; i < nums.size(); i ++) {
//        cout << nums[i] << "\t";
//    }
//    cout << endl;
//}