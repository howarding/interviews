//From any string, we can form a subsequence of that string by deleting some number of characters (possibly no deletions).
//Given two strings source and target, return the minimum number of subsequences of source such that their concatenation
//equals target. If the task is impossible, return -1.
//
//Example 1:
//
//    Input: source = "abc", target = "abcbc"
//    Output: 2
//    Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".
//Example 2:
//
//    Input: source = "abc", target = "acdbc"
//    Output: -1
//    Explanation: The target string cannot be constructed from the subsequences of source string due to the character
//    "d" in target string.
//Example 3:
//
//    Input: source = "xyz", target = "xzyxz"
//    Output: 3
//    Explanation: The target string can be constructed as follows "xz" + "y" + "xz".
//
//
//Constraints:
//
//    Both the source and target strings consist of only lowercase English letters from "a"-"z".
//    The lengths of source and target string are between 1 and 1000.

#include <iostream>
#include <vector>

using namespace std;

class Solution_1055 {
public:
    // Time:    O(mn)
    // Space:   O(1)
    int shortestWay(string source, string target) {
        vector<bool> chars(26);
        for (char c: source) chars[c - 'a'] = true;
        int result = 0;
        int i = 0, j = 0;
        while (j < target.size()) {
            if (!chars[target[j] - 'a']) return -1;
            if (i == source.size()) {
                i = 0;
                result++;
            }
            if (source[i] == target[j]) j++;
            i++;
        }
        result++;   // 当j移动到target末尾时，这时候又匹配了一次
        return result;
    }

    // No Set
    // Time:    O(mn)
    // Space:   O(1)  no set
    int shortestWay1(string source, string target) {
        int result = 0;
        int i = 0, j = 0, prev_j = 0;
        while (j < target.size()) {
            if (i == source.size()) {
                if (j == prev_j) return -1;
                i = 0;
                prev_j = j;
                result++;
            }
            if (source[i] == target[j]) j++;
            i++;
        }
        result++;   // 当j移动到target末尾时，这时候又匹配了一次
        return result;
    }

    // Binary Search
    // Time:    O(log(m)*n)
    // Space:   O(m)
    int shortestWay2(string source, string target) {
        vector<vector<int>> indices(26);
        for (int i = 0; i < source.size(); i++)
            indices[source[i] - 'a'].push_back(i);
        int result = 0;
        int i = 0, j = 0;
        while (j < target.size()) {
            vector<int>& arr = indices[target[j] - 'a'];
            if (arr.empty()) return -1;
            if (i == source.size()) {
                i = 0;
                result++;
            }
            int left = 0, right = arr.size() - 1;
            // binary search
            while (left <= right) {
                int mid = (left + right) / 2;
                if (arr[mid] >= i)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            int ind = right + 1;
            if (ind == arr.size()) {
                i = arr[0] + 1;
                result++;
            } else
                i = arr[ind] + 1;
            j++;
        }
        result++;
        return result;
    }

    // BEST
    // Time:    O(n)
    // Space:   O(m)
    int shortestWay3(string source, string target) {
        vector<vector<int>> indices(26, vector<int>(source.size(), -1));
        vector<bool> chars(26);
        for (int i = 0; i < source.size(); i++) {
            indices[source[i] - 'a'][i] = i;
            chars[source[i] - 'a'] = true;
        }
        for (int i = 0; i < 26; i++) {
            int pre = 0;
            for (int j = source.size() - 1; j >= 0; j--) {
                if (indices[i][j] == -1) indices[i][j] = pre;
                else pre = indices[i][j];
            }
        }
        int result = 0, i = 0;
        for (int j = 0; j < target.size(); j++) {
            if (!chars[target[j] - 'a']) return -1;
            if (i == source.size()) {
                i = 0;
                result++;
            }
            i = indices[target[j] - 'a'][i];
            if (i == 0) {
                result++;
                j--;
            }
        }
        result++;
        return result;
    }
};

//int main() {
//    Solution_1055 sol;
////    string source("abc"), target("abcbc");
//    string source("adbsc"), target("addddddddddddsbc");
//    int result = sol.shortestWay2(source, target);
//    cout << result << endl;
//}