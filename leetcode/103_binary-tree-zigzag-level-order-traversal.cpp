//Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//        3
//       / \
//      9  20
//        /  \
//       15   7
//return its zigzag level order traversal as:
//    [
//      [3],
//      [20,9],
//      [15,7]
//    ]

#include <iostream>
#include <vector>
#include <stack>

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
class Solution_103 {
public:
    // Stack
    // Time:	O(n)
    // Space:	O(n)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        stack<TreeNode*> stk1, stk2;

        bool reverse = false;
        stk1.push(root);
        while (!stk1.empty()) {
            vector<int> path;
            while (!stk1.empty()) {
                TreeNode* node = stk1.top();
                stk1.pop();
                if (!node) continue;
                path.push_back(node->val);
                if (reverse) {
                    stk2.push(node->right);
                    stk2.push(node->left);
                } else {
                    stk2.push(node->left);
                    stk2.push(node->right);
                }
            }
            if (!path.empty())
                result.push_back(path);
            reverse = !reverse;
            stk1.swap(stk2);
        }
        return result;
    }
};