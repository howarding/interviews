//You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
//
//Define a pair (u,v) which consists of one element from the first array and one element from the second array.
//
//Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
//
//Example 1:
//    Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
//
//    Return: [1,2],[1,4],[1,6]
//
//    The first 3 pairs are returned from the sequence:
//    [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
//Example 2:
//    Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
//
//    Return: [1,1],[1,1]
//
//    The first 2 pairs are returned from the sequence:
//    [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
//Example 3:
//    Given nums1 = [1,2], nums2 = [3],  k = 3
//
//    Return: [1,3],[2,3]
//
//    All possible pairs are returned from the sequence:
//    [1,3],[2,3]

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution_373 {
public:
    // Exp: https://discuss.leetcode.com/topic/50885/simple-java-o-klogk-solution-with-explanation
    // Time:	O(klog(k))
    // Space:	O(k)
    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<pair<int, int>> result;
        priority_queue<vector<int>, vector<vector<int>>, cmp> min_heap;
        if (nums1.empty() || nums2.empty() || k == 0) return result;
        for (int i = 0; i < min(int(nums1.size()), k); i++) min_heap.push({nums1[i], nums2[0], 0});
        while (k-- > 0 && !min_heap.empty()) {
            auto cur = min_heap.top();
            min_heap.pop();
            result.push_back(pair<int, int>(cur[0], cur[1]));
            if (cur[2] == nums2.size() - 1) continue;
            min_heap.push({cur[0], nums2[cur[2] + 1], cur[2] + 1});
        }
        return result;
    }

    struct cmp {
        bool operator()(vector<int> a, vector<int> b) {
            return (a[0] + a[1]) > (b[0] + b[1]);
        }
    };
};


//int main() {
//    vector<int> nums1({1});
//    vector<int> nums2({3, 5, 6, 7, 8, 100});
//    int k = 4;
//    Solution_373 sol;
//    cout << sol.kSmallestPairs(nums1, nums2, k).size() << endl;
//}