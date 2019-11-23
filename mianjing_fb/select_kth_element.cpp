//Suppose you have an array of integers 5, 3, 9, 1 (the array is length n) and value k
//
//Find the kth largest value in the array e.g.
//
//    k = 0 => 9
//    k = 1 => 5
//    k = n - 1 => 1

#include <vector>
#include <queue>

using namespace std;

class kthElement {
public:
    // BEST: Quick Select
    // LC 215: Kth Largest Element in an Array
    // Exp: https://discuss.leetcode.com/topic/15256/4-c-solutions-using-partition-max-heap-priority_queue-and-multiset-respectively
    // Time:
    //      best/avg:   O(n)
    //      worst:      O(n^2)
    // Space:	O(1)
    int kthLargest(vector<int>& nums, int k) {
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


    // K < N / 2:   Min Heap
    // K > N / 2:   Max Heap
    // Time:    O(n*log(k))
    // Space:   O(k)
    int kthLargest2(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> que;
        for (int num: nums) {
            que.push(num);
            if (que.size() > k)
                que.pop();
        }
        return que.top();
    }
};