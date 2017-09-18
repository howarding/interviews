//Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
//
//Examples:
//[2,3,4] , the median is 3
//
//[2,3], the median is (2 + 3) / 2 = 2.5
//
//Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.
//
//For example,
//Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
//
//    Window position                Median
//    ---------------               -----
//    [1  3  -1] -3  5  3  6  7       1
//    1 [3  -1  -3] 5  3  6  7       -1
//    1  3 [-1  -3  5] 3  6  7       -1
//    1  3  -1 [-3  5  3] 6  7       3
//    1  3  -1  -3 [5  3  6] 7       5
//    1  3  -1  -3  5 [3  6  7]      6
//Therefore, return the median sliding window as [1,-1,-1,3,5,6].
//
//Note:
//You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution_480 {
public:
    // Exp: https://discuss.leetcode.com/topic/74679/o-n-log-n-time-c-solution-using-two-heaps-and-a-hash-table
    // Time:	O(n * log(k))
    // Space:	O(k)
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        unordered_map<int, int> dict;
        priority_queue<int, vector<int>, less<int>> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;

        int i = 0;

        while (i < k) max_heap.push(nums[i++]);
        for (int count = 0; count < k / 2; count++) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        while (true) {
            // Get median
            if (k % 2) result.push_back(max_heap.top());
            else result.push_back(max_heap.top() / 2.0 + min_heap.top() / 2.0);

            if (i == nums.size()) break;
            int m = nums[i - k], n = nums[i++], balance = 0;

            // What happens to the number m that is moving out of the window
            if (m <= max_heap.top()) {
                balance--;
                if (m == max_heap.top()) max_heap.pop();
                else dict[m]++;
            } else {
                balance++;
                if (m == min_heap.top()) min_heap.pop();
                else dict[m]++;
            }

            // Insert the new number n that enters the window
            if (!max_heap.empty() && n <= max_heap.top()) {
                balance++;
                max_heap.push(n);
            } else {
                balance--;
                min_heap.push(n);
            }

            // Rebalance the bottom and top heaps
            if (balance < 0) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
            if (balance > 0) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }

            // Remove numbers that should be discarded at the top of the two heaps
            while (!max_heap.empty() && dict[max_heap.top()]) {
                dict[max_heap.top()]--;
                max_heap.pop();
            }
            while (!min_heap.empty() && dict[min_heap.top()]) {
                dict[min_heap.top()]--;
                min_heap.pop();
            }
        }

        return result;
    }
};