//Given an unsorted array of integers, find the length of longest increasing subsequence.
//
//For example,
//Given [10, 9, 2, 5, 3, 7, 101, 18],
//The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
//
//Your algorithm should run in O(n^2) complexity.
//
//Follow up: Could you improve it to O(n log n) time complexity?

#include <iostream>
#include <vector>

using namespace std;

class Solution_300 {
public:
    // Binary Search (My own)
    // Time:	O(nlog(n))
    // Space:	O(n)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> mins;
        for (int num : nums) {
            if (mins.empty()) {
                mins.push_back(num);
                continue;
            }
            int left = 0, right = mins.size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (mins[mid] == num) {
                    left = mid;
                    break;
                }
                if (mins[mid] > num)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            if (left == mins.size())
                mins.push_back(num);
            else
                mins[left] = min(mins[left], num);
        }
        return mins.size();
    }
};