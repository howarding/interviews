//Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.
//
//Examples:
//
//    "123", 6 -> ["1+2+3", "1*2*3"]
//    "232", 8 -> ["2*3+2", "2+3*2"]
//    "105", 5 -> ["1*0+5","10-5"]
//    "00", 0 -> ["0+0", "0-0", "0*0"]
//    "3456237490", 9191 -> []

#include <iostream>
#include <vector>

using namespace std;

class Solution_282 {
public:
    // Backtracking
    // Exp: https://discuss.leetcode.com/topic/24523/java-standard-backtrace-ac-solutoin-short-and-clear
    // Time:	O(4^n)
    // Space:	O(4^n)
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.empty()) return result;
        string path;
        helper(num, target, 0, 0, 0, path, result);
        return result;
    }


    // last 是用来表示到目前为止的path中，最近的一个乘积项的值
    // 如果path = 1 + 2 + 3, 那么last = 3
    // 如果path = 2 + 3 * 2, 那么last = 3 * 2
    // 如果path = 1 - 3 * 5 * 6, 那么last = - 3 * 5 * 6
    void helper(string &num, int target, int start, long eval, long last, string &path, vector<string> &result) {
        if (start == num.size()) {
            if (eval == target)
                result.push_back(path);
            return;
        }

        for (int i = start; i < num.size(); i++) {
            if (i > start && num[start] == '0') break;    // ignore those numbers starting w/ 0
            string ele = num.substr(start, i - start + 1);  // 从start到i的字符串作为数字
            long cur = stol(ele);
            int len = path.size();
            if (start == 0) {
                path.append(ele);
                helper(num, target, i + 1, cur, cur, path, result);
                path.erase(len);
            } else {
                path.append("+" + ele);
                helper(num, target, i + 1, eval + cur, cur, path, result);
                path[len] = '-';
                helper(num, target, i + 1, eval - cur, -cur, path, result);
                path[len] = '*';
                helper(num, target, i + 1, eval - last + last * cur, last * cur, path, result);
                path.erase(len);
            }
        }
    }
};