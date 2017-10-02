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
            for (int j = result.size() - 1; j > 0; j--)
                result[j] += result[j-1];
            result.push_back(1);
        }
        return result;
    }
};