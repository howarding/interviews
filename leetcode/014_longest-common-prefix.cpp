//Write a function to find the longest common prefix string amongst an array of strings.

#include <iostream>
#include <vector>

using namespace std;

class Solution_014 {
public:
    // Exp: my own
    // Time:	O(mn)   n: # strings in strs, m: length of each string
    // Space:	O(m)
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string result = strs[0];
        int i = 0;
        while (i < result.size()) {
            for (int j = 1; j < strs.size(); j++)
                if (i == strs[j].size() || strs[j][i] != result[i])
                    return result.substr(0, i);
            i++;
        }
        return result;
    }
};


//int main() {
//    Solution_014 sol;
//    vector<string> strs({"c", "c"});
//    cout << sol.longestCommonPrefix(strs) << endl;
//}