//求double sqrt(double x).
//while退出后check left和right，被面试官指出应该返回mid
//Follow-up:你的程序如何handle input小于1的情况？复杂度？

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_sdx {
    // Set up an error threshold, when (high - low) < err, return.
    // Time:    O(log(x/err))
    double sqrt_double(double x) {
        // x > 1
        double err = 1e-6;
        double low = 1, high = x;
        while (low < high - err) {
            double mid = low + (high - low) / 2;
            double divider = x / mid;
            if (mid == divider) return mid;
            if (mid < divider) low = mid;
            else high = mid;
        }
        return high;
    }

    // Time:    O(log(x/err))
    double sqrt_double_1(double x) {
        // x < 1
        double err = 1e-6;
        double low = 1, high = x;
        while (low < high - err) {
            double mid = low + (high - low) / 2;
            double square = mid * mid;
            if (square == x) return mid;
            if (square < x) low = mid;
            else high = mid;
        }
        return high;
    }

    int mySqrt(int x) {
        if (!x) return 0;
        int low = 1, high = x;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            int divider = x / mid;
            if (mid == divider) return mid;
            if (mid < divider) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};