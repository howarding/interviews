//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water
// it is able to trap after raining.
//
//For example,
//    Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

#include <iostream>
#include <vector>

using namespace std;

class Solution_042 {
public:
    // 2Pointers
    // Exp: https://discuss.leetcode.com/topic/5125/sharing-my-simple-c-code-o-n-time-o-1-space
    // Time:	O(n)
    // Space:	O(1)
    int trap(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        int total = 0;
        int max_left = 0, max_right = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] > max_left)
                    max_left = height[left];
                else
                    total += max_left - height[left];
                left++;
            } else {
                if (height[right] > max_right)
                    max_right = height[right];
                else
                    total += max_right - height[right];
                right--;
            }
        }
        return total;
    }
};


//int main() {
//    Solution_042 sol;
//    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
//    cout << sol.trap(height) << endl;
//}