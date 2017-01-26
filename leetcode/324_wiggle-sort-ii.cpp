//Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
//
//Example:
//    (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
//(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
//
//Note:
//    You may assume all input has valid answer.
//
//Follow Up:
//Can you do it in O(n) time and/or in-place with O(1) extra space?

#include <iostream>
#include <vector>

using namespace std;

class Solution_324 {
public:
    // Exp: https://discuss.leetcode.com/topic/41464/step-by-step-explanation-of-index-mapping-in-java
    // Exp: http://blog.sina.com.cn/s/blog_eb52001d0102w2b4.html
    // Quick Select
    // Time:	O(n)
    // Space:	O(1)
    void wiggleSort(vector<int> &nums) {
        int mid = quick_select(nums, 0, nums.size() - 1, (nums.size() + 1) / 2);
        int n = nums.size();

        int left = 0, i = 0, right = n - 1;
        while (i <= right) {
            if (nums[newIndex(i, n)] > mid)
                swap(nums[newIndex(left++, n)], nums[newIndex(i++, n)]);
            else if (nums[newIndex(i, n)] < mid)
                swap(nums[newIndex(right--, n)], nums[newIndex(i, n)]);
            else
                i++;
        }
    }

    int newIndex(int index, int n) {
        return (1 + 2 * index) % (n | 1);
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