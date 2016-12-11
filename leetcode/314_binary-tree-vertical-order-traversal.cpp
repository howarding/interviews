//Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
//
//If two nodes are in the same row and column, the order should be from left to right.
//
//Examples:
//
//    1. Given binary tree [3,9,20,null,null,15,7],
//       3
//      /\
//     /  \
//     9  20
//        /\
//       /  \
//      15   7
//    return its vertical order traversal as:
//    [
//        [9],
//        [3,15],
//        [20],
//        [7]
//    ]
//    2. Given binary tree [3,9,8,4,0,1,7],
//         3
//        /\
//       /  \
//       9   8
//      /\  /\
//     /  \/  \
//     4  01   7
//    return its vertical order traversal as:
//    [
//        [4],
//        [9],
//        [3,0,1],
//        [8],
//        [7]
//    ]
//    3. Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
//         3
//        /\
//       /  \
//       9   8
//      /\  /\
//     /  \/  \
//     4  01   7
//        /\
//       /  \
//       5   2
//    return its vertical order traversal as:
//    [
//        [4],
//        [9,5],
//        [3,0,1],
//        [8,2],
//        [7]
//    ]

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution_314 {
public:
    // Exp: https://discuss.leetcode.com/topic/31109/my-solution-in-c
    // Time:	O(n)
    // Space:	O(n)
    vector<vector<int>> verticalOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (!root) return result;
        map<int, vector<int> > col_vals;
        queue<TreeNode *> nodes;
        queue<int> cols;
        nodes.push(root);
        cols.push(0);
        while (!nodes.empty()) {
            TreeNode *p = nodes.front();
            nodes.pop();
            int col = cols.front();
            cols.pop();
            col_vals[col].push_back(p->val);
            if (p->left) {
                nodes.push(p->left);
                cols.push(col - 1);
            }
            if (p->right) {
                nodes.push(p->right);
                cols.push(col + 1);
            }
        }
        for (map<int, vector<int>>::iterator iter = col_vals.begin(); iter != col_vals.end(); iter++)
            result.push_back(iter->second);
        return result;
    }

};