//Given a roman numeral, convert it to an integer.
//
//Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>

using namespace std;

class Solution_013 {
public:
    // My own
    // Time:	O(log(n))
    // Space:	O(1)
    int romanToInt(string s) {
        int result;
        for (int i = 0; i < s.size(); i++) {
            int val1 = transfer(s[i]);
            if (i < s.size() - 1) {
                int val2 = transfer(s[i+1]);
                if (val1 >= val2)
                    result += val1;
                else {
                    result += val2 - val1;
                    i++;
                }
            } else
                result += val1;
        }
        return result;
    }

    int transfer(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
    }
};


//int main() {
//    Solution_013 sol;
//    string s = "MCMXCVI";
//    cout << sol.romanToInt(s) << endl;
//}