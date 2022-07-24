//Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//
//Note: You may not slant the container and n is at least 2.

#include <iostream>
#include <vector>

using namespace std;

class Solution_011 {
public:
    // 2Pointers
    // Exp: https://discuss.leetcode.com/topic/16754/simple-and-fast-c-c-with-explanation
    // Time:	O(n)
    // Space:	O(1)
    int maxArea(vector<int> &height) {
        int water = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int h = min(height[left], height[right]);
            water = max(water, (right - left) * h);
            // For those heights less than h, just skip them. No need to do max every time.
            while (height[left] <= h && left < right) left++;
            while (height[right] <= h && left < right) right--;
        }
        return water;
    }
};