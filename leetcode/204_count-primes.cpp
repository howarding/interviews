//Description:
//
//Count the number of prime numbers less than a non-negative number, n.

#include <iostream>
#include <vector>

using namespace std;

class Solution_204 {
public:
    // Exp: https://discuss.leetcode.com/topic/13654/my-simple-java-solution
    // Time:	O(n^2)
    // Space:	O(n)
    int countPrimes(int n) {
        vector<bool> notPrime(n, false);
        int count = 0;
        for (int i = 2; i < n; i++)
            if (notPrime[i] == false) {
                count++;
                for (int j = 2; i*j < n; j++)
                    notPrime[i*j] = true;
            }

        return count;
    }
};