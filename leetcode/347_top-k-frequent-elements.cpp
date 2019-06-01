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
    // Time:	O(n * log(k))
    // Space:	O(n)
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> result;
        unordered_map<int, int> dict;   // 先统计每个num次数
        for (int num : nums)
            dict[num]++;

        // pair<first, second>: first is number,  second is frequency
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> min_heap;
        for (auto pair : dict) {
            min_heap.push(pair);
            if (min_heap.size() > k)
                min_heap.pop();
        }
        while (!min_heap.empty()) {
            pair<int, int> ele = min_heap.top();
            result.push_back(ele.first);
            min_heap.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }

    struct cmp {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        }
    };
};


//int main() {
//    Solution_347 sol;
//    vector<int> nums{1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
//    vector<int> result = sol.topKFrequent(nums, 3);
//    for (int num: result)
//        cout << num << "\t";
//}