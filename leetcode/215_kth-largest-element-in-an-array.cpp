//Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//For example,
//Given [3,2,1,5,6,4] and k = 2, return 5.
//
//Note:
//You may assume k is always valid, 1 ≤ k ≤ array's length.

#include <iostream>
#include <vector>

using namespace std;

class Solution_215 {
public:
    // Exp: https://discuss.leetcode.com/topic/15256/4-c-solutions-using-partition-max-heap-priority_queue-and-multiset-respectively
    // Quick Select
    // Time:	O(n)
    // Space:	O(1)
    int findKthLargest(vector<int> &nums, int k) {
        return quick_select(nums, 0, nums.size() - 1, k);
    }

    int quick_select(vector<int> &nums, int left, int right, int k) {
        int i = partition(nums, left, right);
        int len = i - left + 1;
        if (len == k) return nums[i];
        if (len < k)
            return quick_select(nums, i + 1, right, k - len);
        else
            return quick_select(nums, left, i - 1, k);
    }

    int partition(vector<int> &nums, int left, int right) {
        int pivot = nums[left];
        int start = left++;
        while (left <= right) {
            if (nums[left] < pivot && nums[right] > pivot)
                swap(nums[left++], nums[right--]);
            if (nums[left] >= pivot) left++;
            if (nums[right] <= pivot) right--;
        }
        swap(nums[start], nums[right]);
        return right;
    }
};


//int main() {
//    vector<int> nums({1,2,3,4});
//    int k = 1;
//    Solution_215 sol;
//    cout << sol.findKthLargest(nums, k) << endl;
//}