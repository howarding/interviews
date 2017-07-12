//Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
//For example:
//Given "25525511135",
//
//return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

#include <iostream>
#include <vector>

using namespace std;

class Solution_093 {
public:
    // Backtracking, fewer cases
    // Exp: https://discuss.leetcode.com/topic/3919/my-code-in-java/22
    // Time:	O(n)
    // Space:	O(1)
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if (s.empty()) return result;
        string path = "";
        helper(s, 0, 0, path, result);
        return result;
    }

    void helper(string& s, int start, int count, string& path, vector<string>& result) {
        if (count == 4 || start == s.size()) {
            if (count == 4 && start == s.size())
                result.push_back(path);
            return;
        }
        for (int i = start; i < (s[start] == '0' ? start + 1 : start + 3) && i < s.size(); i++) {
            int n = path.size();
            int num = stoi(s.substr(start, i - start + 1));
            if (num > 255) return;
            path.append(s.substr(start, i - start + 1) + (count == 3 ? "" : "."));
            helper(s, i+1, count+1, path, result);
            path.erase(n);
        }
    }



    // My own, more cases
    void helper1(string& s, int i, int count, int num, string& path, vector<string>& result) {
        if (count == 4 || i == s.size()) {
            if (count == 4 && i == s.size())
                result.push_back(path);
            return;
        }
        num = num * 10 + s[i] - '0';
        if (num > 255) return;
        int n = path.size();
        path.append(to_string(num) + (count == 3 ? "" : "."));
        helper1(s, i+1, count+1, 0, path, result);
        path.erase(n);
        if (num == 0 && s[i] == '0') return;
        helper1(s, i+1, count, num, path, result);
    }
};


//int main() {
//    Solution_093 sol;
//    string s("010010");
//    vector<string> result(sol.restoreIpAddresses(s));
//    for (string& str : result)
//        cout << str << endl;
//}