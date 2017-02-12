//Implement int sqrt(int x).
//
//Compute and return the square root of x.

#include <iostream>

using namespace std;

class Solution_069 {
public:
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
        return low;
    }
};