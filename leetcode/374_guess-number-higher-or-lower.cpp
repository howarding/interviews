//We are playing the Guess Game. The game is as follows:
//
//    I pick a number from 1 to n. You have to guess which number I picked.
//
//Every time you guess wrong, I'll tell you whether the number is higher or lower.
//
//You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
//
//    -1 : My number is lower
//    1 : My number is higher
//    0 : Congrats! You got it!
//Example:
//    n = 10, I pick 6.
//
//    Return 6.

#include <iostream>

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num, int real) {
    if (real > num) return 1;
    if (real < num) return -1;
    return 0;
};

class Solution_374 {
public:
    // Exp: https://discuss.leetcode.com/topic/51034/short-java-code-using-binary-search
    // Time:	O(log(n))
    // Space:	O(1)
    int guessNumber(int n, int real) {
        int i = 1, j = n, mid;
        while (i <= j) {
            mid = ((j - i) >> 1) + i;
            int res = guess(mid, real);
            if (res == 0) return mid;
            if (res == 1)
                i = mid + 1;
            else
                j = mid - 1;
        }
        return -1;
    }
};


//int main() {
//    int n = 10, real = 6;
//    Solution_374 sol;
//    cout << sol.guessNumber(n, real) << endl;
//}