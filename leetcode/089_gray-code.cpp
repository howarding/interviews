//The gray code is a binary numeral system where two successive values differ in only one bit.
//
//Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
//
//For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
//
//    00 - 0
//    01 - 1
//    11 - 3
//    10 - 2
//Note:
//For a given n, a gray code sequence is not uniquely defined.
//
//For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
//
//For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

#include <iostream>
#include <vector>

using namespace std;

class Solution_089 {
public:
    // DP (My own)
    // Time:	O(2^n)
    // Space:	O(2^n)
    vector<int> grayCode(int n) {
        vector<int> result;
        if (n < 0) return result;
        result.push_back(0);
        for (int i = 1; i <= n; i++)
            for (int j = result.size() - 1; j >= 0; j--)
                result.push_back(result[j] + (1 << (i-1)));
        return result;
    }
};


//int main() {
//    Solution_089 sol;
//    int n = 2;
//    vector<int> result(sol.grayCode(n));
//    for (int n : result)
//        cout << n << endl;
//}