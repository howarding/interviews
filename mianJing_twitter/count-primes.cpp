//Description:
//
//Count the number of prime numbers less than a non-negative number, n.

#include <iostream>
#include <vector>
#include <unordered_set>

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

    // Print first 100 prime numbers
    // Time:	O(n^2)
    // Space:	O(n^2)
    vector<int> primeNums(int n) {
        vector<int> result;
        unordered_set<int> visited;
        int num = 2;
        while (result.size() < n) {
            if (visited.find(num) == visited.end())
                result.push_back(num);
            for (int start = 2; start <= num; start++)
                visited.insert(start * num);
            num++;
        }
        return result;
    }
};


//int main() {
//    Solution_204 sol;
//    int n = 100;
//    vector<int> result(sol.primeNums(n));
//    for (int num : result)
//        cout << num << "\t";
//    cout << endl;
//}