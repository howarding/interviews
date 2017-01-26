//One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
//
//         _9_
//        /   \
//       3     2
//      / \   / \
//     4   1  #  6
//    / \ / \   / \
//    # # # #   # #
//For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
//
//Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
//
//Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
//
//You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
//
//Example 1:
//"9,3,4,#,#,1,#,#,2,#,6,#,#"
//Return true
//
//Example 2:
//"1,#"
//Return false
//
//Example 3:
//"9,#,#,1"
//Return false

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution_331 {
public:
    // Exp: https://discuss.leetcode.com/topic/45326/c-4ms-solution-o-1-space-o-n-time
    // Time:    O(n)
    // Space:   O(1)
    bool isValidSerialization(string preorder) {
        int null_count = 1;
        vector<string> strings = split(preorder);
        for (int i = 0; i < strings.size(); i++) {
            null_count += strings[i] != "#" ? 1 : -1;
            if ((null_count == 0) != (i == strings.size() - 1))
                return false;
        }
        return true;
    }

    vector<string> split(string s) {
        vector<string> result;
        string ele;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ',' && !ele.empty()) {
                result.push_back(ele);
                ele = "";
                continue;
            }
            ele += s[i];
        }
        result.push_back(ele);
        return result;
    }
};


//int main() {
//    string s= "9,3,4,#,#,1,#,#,2,#,6,#,#";
//    Solution_331 sol;
//    cout << sol.isValidSerialization(s) << endl;
//}