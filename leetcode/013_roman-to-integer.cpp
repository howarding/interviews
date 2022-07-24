//Given a roman numeral, convert it to an integer.
//
//Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution_013 {
public:
    // My own
    // Time:	O(1)
    // Space:	O(1)
    int romanToInt(string s) {
        unordered_map<char, int> values{
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000},
        };
        int result = 0, i = 0;
        while (i < s.size()) {
            if (i < s.size() - 1 && values[s[i]] < values[s[i + 1]]) {
                result += values[s[i + 1]] - values[s[i]];
                i += 2;
            } else {
                result += values[s[i]];
                i++;
            }
        }
        return result;
    }
};


//int main() {
//    Solution_013 sol;
//    string s = "MCMXCVI";
//    cout << sol.romanToInt(s) << endl;
//}