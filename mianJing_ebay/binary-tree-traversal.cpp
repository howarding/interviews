#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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
    // Level Order
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            int num = que.size();
            vector<int> level;
            while (num-- > 0) {
                TreeNode *p = que.front();
                level.push_back(p->val);
                que.pop();
                if (p->left) que.push(p->left);
                if (p->right) que.push(p->right);
            }
            result.push_back(level);
        }
        return result;
    }


    // PreOrder
    // 1. Recursive
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }

    void dfs(TreeNode *root, vector<int> &result) {
        if (root == NULL)
            return;
        result.push_back(root->val);
        dfs(root->left, result);
        dfs(root->right, result);
    }


    // 2. Iterative
    vector<int> preorderTraversal1(TreeNode *root) {
        vector<int> result;
        if (!root) return result;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            root = stk.top();
            result.push_back(root->val);
            stk.pop();
            if (root->right) stk.push(root->right);
            if (root->left) stk.push(root->left);
        }
        return result;
    }
};