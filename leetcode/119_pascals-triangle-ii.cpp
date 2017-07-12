//Given an index k, return the kth row of the Pascal's triangle.
//
//For example, given k = 3,
//Return [1,3,3,1].
//
//Note:
//Could you optimize your algorithm to use only O(k) extra space?

#include <iostream>
#include <vector>

using namespace std;

class Solution_119 {
public:
    // DP (My own)
    // Time:	O(n^2)
    // Space:	O(n)
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        if (rowIndex < 0) return result;
        result.push_back(1);
        for (int i = 0; i < rowIndex; i++) {
            int n = result.size(), pre = result[0];
            for (int j = 1; j < n; j++) {
                int tmp = result[j];
                result[j] += pre;
                pre = tmp;
            }
            result.push_back(1);
        }
        return result;
    }
};