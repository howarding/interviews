//Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.
//
//The returned array must be in sorted order.
//
//Expected time complexity: O(n)
//
//Example:
//    nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,
//
//    Result: [3, 9, 15, 33]
//
//    nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5
//
//    Result: [-23, -5, 1, 7]

#include <iostream>
#include <vector>

using namespace std;

class Solution_360 {
public:
    // Exp: https://discuss.leetcode.com/topic/48424/java-o-n-incredibly-short-yet-easy-to-understand-ac-solution
    // Time:	O(n)
    // Space:	O(n)
    vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> sorted(n);
        int i = 0, j = n - 1;
        int index = a >= 0 ? n - 1 : 0;
        while (i <= j) {
            if (a >= 0)
                sorted[index--] =
                    quad(nums[i], a, b, c) > quad(nums[j], a, b, c) ? quad(nums[i++], a, b, c) : quad(nums[j--], a, b, c);
            else
                sorted[index++] =
                    quad(nums[i], a, b, c) > quad(nums[j], a, b, c) ? quad(nums[j--], a, b, c) : quad(nums[i++], a, b, c);
        }
        return sorted;
    }

    int quad(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
};