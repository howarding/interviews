//Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
//
//Example:
//    For num = 5 you should return [0,1,1,2,1,2].
//
//Follow up:
//
//    It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
//    Space complexity should be O(n).
//    Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
//Hint:
//
//    1. You should make use of what you have produced already.
//    2. Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
//    3. Or does the odd/even status of the number help you in calculating the number of 1s?

#include <iostream>
#include <vector>

using namespace std;

class Solution_338 {
public:
    // Exp: https://discuss.leetcode.com/topic/40262/four-lines-c-time-o-n-space-o-n
    // Time:	O(n)
    // Space:	O(1)
    vector<int> countBits(int num) {
        //// My own answer
        // vector<int> result({0});
        // int power = 0, base = 1, ele = 1;
        // while ((base *= 2) <= num) power++;
        // for (int i = 0; i <= power; i++) {
        //     for(int n = ele; n < min(ele * 2, num+1); n++)
        //         result.push_back(result[n-ele]+1);
        //     ele *= 2;
        // }
        // return result;

        //// From discussion, more efficient.
        vector<int> ret(num + 1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i & (i - 1)] + 1;
        return ret;
    }
};