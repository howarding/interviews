//Write a program to find the nth super ugly number.
//
//Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
//
//Note:
//    (1) 1 is a super ugly number for any given primes.
//    (2) The given numbers in primes are in ascending order.
//    (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.

#include <iostream>
#include <vector>

using namespace std;

class Solution_313 {
public:
    // Exp: https://discuss.leetcode.com/topic/34841/java-three-methods-23ms-36-ms-58ms-with-heap-performance-explained
    // Time:	O(kn)
    // Space:	O(n+k)
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        vector<int> ugly(n, INT_MAX);
        vector<int> indices(primes.size(), 0);

        ugly[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < primes.size(); j++)
                ugly[i] = min(ugly[i], ugly[indices[j]] * primes[j]);
            for (int j = 0; j < primes.size(); j++)
                if (ugly[i] == ugly[indices[j]] * primes[j])
                    indices[j]++;
        }
        return ugly[n - 1];
    }
};