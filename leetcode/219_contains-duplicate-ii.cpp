//Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution_219 {
public:
    // Set (My own)
    // Time:	O(n)
    // Space:	O(1)
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1 || k == 0) return false;
        unordered_set<int> num_set(nums.begin(), nums.begin() + min(k+1, n));
        if (num_set.size() < min(k+1, n)) return true;
        for (int i = k+1; i < n; i++) {
            num_set.erase(nums[i-k-1]);
            if (num_set.find(nums[i]) != num_set.end()) return true;
            num_set.insert(nums[i]);
        }
        return false;
    }
};