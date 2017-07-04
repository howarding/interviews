//You are climbing a stair case. It takes n steps to reach to the top.
//
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//
//Note: Given n will be a positive integer.

#include <iostream>

using namespace std;

class Solution_070 {
public:
    // DP (My own)
    // Time:	O(n)
    // Space:	O(1)
    int climbStairs(int n) {
        if(n < 0) return 0;
        if(n <= 2) return n;
        int pre = 1, cur = 2;
        for(int i = 3; i <= n; i++){
            cur += pre;
            pre = cur - pre;
        }
        return cur;
    }
};