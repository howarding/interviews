//Given a non-empty array of integers, return the k most frequent elements.
//
//For example,
//    Given [1,1,1,2,2,3] and k = 2, return [1,2].
//
//Note:
//    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
//    Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution_347 {
public:
    // Hash Table, Heap
    // Exp: https://discuss.leetcode.com/topic/44226/c-o-n-log-n-k-unordered_map-and-priority_queue-maxheap-solution
    // Time:	O(n * log(n-k))
    // Space:	O(n)
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> result;
        if (nums.empty()) return result;
        unordered_map<int, int> dict;
        for (int num : nums)
            dict[num]++;

        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> max_heap;
        for (auto pair : dict) {
            max_heap.push({pair.second, pair.first});
            if (max_heap.size() > (int) dict.size() - k) {
                result.push_back(max_heap.top().second);
                max_heap.pop();
            }
        }
        return result;
    }

    struct cmp {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.first < b.first;
        }
    };
};