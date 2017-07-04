//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//    P   A   H   N
//    A P L S I I G
//    Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows:
//
//    string convert(string text, int nRows);
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

#include <iostream>
#include <vector>

using namespace std;

class Solution_006 {
public:
    // Exp: my own
    // Time:	O(n)
    // Space:	O(n)
    string convert(string s, int numRows) {
        if (numRows == 0) return "";
        if (numRows == 1) return s;
        vector<string> rows(numRows, "");
        vector<int> indices;
        for (int i = 0; i < numRows; i++) indices.push_back(i);
        for (int i = numRows - 2; i > 0; i--) indices.push_back(i);
        int length = indices.size();
        for (int i = 0; i < s.size(); i++)
            rows[indices[i % length]].push_back(s[i]);
        string result = "";
        for (string& s : rows)
            result.append(s);
        return result;
    }
};


//int main() {
//    Solution_006 sol;
//    string s = "ABCD";
//    int numRows = 3;
//    cout << sol.convert(s, numRows) << endl;
//}