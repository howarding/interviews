//Write an algorithm to determine if a number is "happy".
//
//A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
//
//Example: 19 is a happy number
//
//12 + 92 = 82
//82 + 22 = 68
//62 + 82 = 100
//12 + 02 + 02 = 1

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution_202 {
public:
    // Iterative (My own), faster
    // Time:	O(n)
    // Space:	O(n)
    bool isHappy(int n) {
        unordered_set<int> nums;
        int current = 0;
        while (n != 1 && nums.find(n) == nums.end()) {
            nums.insert(n);
            while (n) {
                int remainder = n % 10;
                current += remainder * remainder;
                n /= 10;
            }
            n = current;
            current = 0;
        }
        return n == 1;
    }



    // Detect cycle
    // https://discuss.leetcode.com/topic/12587/my-solution-in-c-o-1-space-and-no-magic-math-property-involved
    // Time:	Longer time
    // Space:	O(1)
    bool isHappy1(int n) {
        int slow(n), fast(next(n));
        while (slow != 1 && fast != 1 && slow != fast) {
            slow = next(slow);
            fast = next((next(fast)));
        }
        return slow == 1 || fast == 1;
    }

    int next(int num) {
        int result = 0;
        while (num) {
            int remainder = num % 10;
            result += remainder * remainder;
            num /= 10;
        }
        return result;
    }
};