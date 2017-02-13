//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//        3
//       / \
//      9  20
//        /  \
//       15   7
//return its level order traversal as:
//    [
//        [3],
//        [9,20],
//        [15,7]
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
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        queue<TreeNode *> que;
        int curr = 0;
        int next = 0;
        if (root) {
            que.push(root);
            curr++;
        }
        while (curr) {
            vector<int> level;
            while (curr--) {
                TreeNode *p = que.front();
                level.push_back(p->val);
                que.pop();
                if (p->left) {
                    que.push(p->left);
                    next++;
                }
                if (p->right) {
                    que.push(p->right);
                    next++;
                }
            }
            result.push_back(level);
            curr = next;
            next = 0;
        }
        return result;
    }
};