//Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
//
//Hint:
//
//    1. Expected runtime complexity is in O(log n) and the input is sorted.

#include <iostream>
#include <vector>

using namespace std;

class Solution_274 {
public:
    // Binary Search
    // Exp: https://discuss.leetcode.com/topic/23399/standard-binary-search
    // Time:	O(log(n))
    // Space:	O(1)
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] == n - mid)
                return citations[mid];
            if (citations[mid] > n - mid)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return n - left;
    }
};