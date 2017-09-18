//Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
//Try to solve it in linear time/space.
//
//Return 0 if the array contains less than 2 elements.
//
//You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

#include <iostream>
#include <vector>

using namespace std;

class Solution_164 {
public:
    // Bucket Sort
    // Exp: https://discuss.leetcode.com/topic/5999/bucket-sort-java-solution-with-explanation-o-n-time-and-space/55
    // Time:	O(n)
    // Space:	O(n)
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int minVal = nums[0], maxVal = nums[0], n = nums.size();
        for (int num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }
        int gap = max((maxVal - minVal) / (n - 1), 1);
        int m = (maxVal - minVal) / gap + 1;
        vector<vector<int>> buckets(m, {INT_MAX, INT_MIN});
        for (int num : nums) {
            int ind = (num - minVal) / gap;
            buckets[ind][0] = min(buckets[ind][0], num);
            buckets[ind][1] = max(buckets[ind][1], num);
        }
        int i = 0, j, result = buckets[0][1] - buckets[0][0];
        while (i < m) {
            j = i + 1;
            while (j < m && buckets[j][0] == INT_MAX) j++;
            if (j < m) result = max(result, buckets[j][0] - buckets[i][1]);
            i = j;
        }
        return result;
    }
};


int main() {
    Solution_164 sol;
    vector<int> nums({1,1,1,1});
    cout << sol.maximumGap(nums) << endl;
}