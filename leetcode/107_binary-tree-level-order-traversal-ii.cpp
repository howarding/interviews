//Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//        3
//       / \
//      9  20
//        /  \
//       15   7
//return its bottom-up level order traversal as:
//    [
//        [15,7],
//        [9,20],
//        [3]
//    ]

#include <iostream>
#include <vector>
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
class Solution_107 {
public:
    // Queue, Reverse
    // Time:	O(n)
    // Space:	O(n)
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            vector<int> path;
            int n = que.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = que.front();
                que.pop();
                path.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(path);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};