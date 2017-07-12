//Given a binary tree, return the postorder traversal of its nodes' values.
//
//For example:
//Given binary tree {1,#,2,3},
//   1
//    \
//     2
//    /
//   3
//return [3,2,1].
//
//Note: Recursive solution is trivial, could you do it iteratively?

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
class Solution {
public:
    // Iterative, Stack
    // Time:	O(n)
    // Space:	O(n)
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        stack<TreeNode*> stk;

        TreeNode *tmp, *node(root);
        do {
            while (node) {
                stk.push(node);
                node = node->left;
            }
            tmp = nullptr;
            while (!stk.empty()) {
                node = stk.top();
                stk.pop();
                if (tmp == node->right) {
                    result.push_back(node->val);
                    tmp = node;
                } else {
                    stk.push(node);
                    node = node->right;
                    break;
                }
            }
        } while (!stk.empty());
        return result;
    }
};