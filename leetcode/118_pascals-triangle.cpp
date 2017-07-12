//Given numRows, generate the first numRows of Pascal's triangle.
//
//For example, given numRows = 5,
//Return
//
//    [
//         [1],
//        [1,1],
//       [1,2,1],
//      [1,3,3,1],
//     [1,4,6,4,1]
//    ]

#include <iostream>
#include <vector>

using namespace std;

class Solution_118 {
public:
    // My own
    // Time:	O(n)
    // Space:	O(1)
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows <= 0) return result;
        result.push_back({1});
        for (int i = 1; i < numRows; i++) {
            result.push_back({1});
            for (int j = 0; j < result[i-1].size() - 1; j++)
                result[i].push_back(result[i-1][j] + result[i-1][j+1]);
            result[i].push_back(1);
        }
        return result;
    }
};