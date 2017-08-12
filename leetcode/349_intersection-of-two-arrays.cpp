//Given two arrays, write a function to compute their intersection.
//
//Example:
//Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
//
//Note:
//    Each element in the result must be unique.
//    The result can be in any order.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution_349 {
public:
    // Fastest
    // Set
    // Time:	O(m+n)
    // Space:	O(min(m,n))
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if (nums1.size() > nums2.size()) return intersection(nums2, nums1);
        unordered_set<int> nums(nums1.begin(), nums1.end());
        for (int num : nums2)
            if (nums.count(num)) {
                result.push_back(num);
                nums.erase(num);
            }
        return result;
    }


    // 2 Pointers
    // Time:	O(mlog(m) + nlog(n))
    // Space:	O(min(m,n))
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        unordered_set<int> nums;
        int i = 0, j= 0;
        while (i < nums1.size() && j < nums2.size())
            if (nums1[i] == nums2[j]) {
                nums.insert(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        vector<int> result(nums.begin(), nums.end());
        return result;
    }



    // Binary Search
    // Time:	O((m+n)log(min(m,n)))
    // Space:	O(min(m,n))
    vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return intersection(nums2, nums1);
        unordered_set<int> nums;
        sort(nums1.begin(), nums1.end());
        for (int num : nums2)
            if (binarySearch(nums1, num))
                nums.insert(num);
        vector<int> result(nums.begin(), nums.end());
        return result;
    }

    bool binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};