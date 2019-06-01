//Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//For example,
//Given [3,2,1,5,6,4] and k = 2, return 5.
//
//Note:
//You may assume k is always valid, 1 ≤ k ≤ array's length.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution_215 {
public:
    // BEST: Quick Select
    // Exp: https://discuss.leetcode.com/topic/15256/4-c-solutions-using-partition-max-heap-priority_queue-and-multiset-respectively
    // Time:	O(n)
    // Space:	O(1)
    int findKthLargest(vector<int> &nums, int k) {
        return quick_select(nums, 0, nums.size() - 1, k);
    }

    int quick_select(vector<int> &nums, int left, int right, int k) {
        int i = partition(nums, left, right);   // left,right 都参与排序
        int len = i - left + 1;
        if (len == k) return nums[i];
        if (len < k)
            return quick_select(nums, i + 1, right, k - len);
        else
            return quick_select(nums, left, i - 1, k);
    }

    int partition(vector<int> &nums, int left, int right) {
        int pivot = nums[left]; // pivot是左边数
        int start = left++;
        while (left <= right) {
            if (nums[left] < pivot && nums[right] > pivot)  // 这是降序排列，改变符号是升序
                swap(nums[left++], nums[right--]);
            if (nums[left] >= pivot) left++;    // 这是降序排列，改变符号是升序
            if (nums[right] <= pivot) right--;  // 这是降序排列，改变符号是升序
        }
        swap(nums[start], nums[right]);         // 因为pivot是左边数，所以和nums[right]替换
        return right;
    }

    // min heap
    // Time:    O(n*log(k))
    // Space:   O(k)
    int findKthLargest2(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> que;
        for (int num: nums) {
            que.push(num);
            if (que.size() > k)
                que.pop();
        }
        return que.top();
    }
};


//int main() {
//    vector<int> nums({1,2,3,4});
//    int k = 1;
//    Solution_215 sol;
//    cout << sol.findKthLargest(nums, k) << endl;
//}