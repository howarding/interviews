//Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_560 {
public:

    // DP + HashMap     BEST!
    // Time:    O(n)
    // Space:   O(n)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        int sum = 0, count = 0;
        for (int num : nums) {
            dict[sum]++;
            sum += num;
            if (dict.find(sum - k) != dict.end())
                count += dict[sum - k];
        }
        return count;
    }



    // DP
    // Time:    O(n^2)
    // Space:   O(n)
    int subarraySum1(vector<int>& nums, int k) {
        int count = 0;
        if (nums.empty()) return count;
        vector<int> sums(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++)
            sums[i] = sums[i-1] + nums[i-1];
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j <= nums.size(); j++)
                if (sums[j] - sums[i] == k) count++;
        return count;
    }

};