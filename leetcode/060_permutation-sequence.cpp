//The set [1,2,3,…,n] contains a total of n! unique permutations.
//
//By listing and labeling all of the permutations in order,
//We get the following sequence (ie, for n = 3):
//
//    1. "123"
//    2. "132"
//    3. "213"
//    4. "231"
//    5. "312"
//    6. "321"
//Given n and k, return the kth permutation sequence.
//
//Note: Given n will be between 1 and 9 inclusive.

#include <iostream>
#include <vector>

using namespace std;

class Solution_060 {
public:
    // Backtrack
    // Exp: https://discuss.leetcode.com/topic/17348/explain-like-i-m-five-java-solution-in-o-n
    // Time:	O(n)
    // Space:	O(n)
    string getPermutation(int n, int k) {
        string result;
        vector<int> nums;
        vector<int> factorial;
        factorial.push_back(1);
        int sum = 1;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
            sum *= i;
            factorial.push_back(sum);
        }

        k--;
        for (int i = 1; i <= n; i++) {
            int index = k / factorial[n - i];
            result.push_back('0' + nums[index]);
            nums.erase(nums.begin() + index);
            k -= index * factorial[n - i];
        }
        return result;
    }
};