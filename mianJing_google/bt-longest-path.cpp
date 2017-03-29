//binary tree的最大路径 返回路径

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_blp {
    // Backtracking
    vector<int> longestPath(TreeNode *root) {
        vector<int> result;
        if (!root) return result;
        vector<int> path;
        path.push_back(root->val);
        helper(root, path, result);
        return result;
    }

    void helper(TreeNode *node, vector<int> &path, vector<int> &result) {
        path.push_back(node->val);
        if (!node->left && !node->right && path.size() > result.size()) {
            result = path;
            return;
        }
        if (node->left)
            helper(node->left, path, result);
        if (node->right)
            helper(node->right, path, result);
        path.pop_back();
    }


    // Maximum Depth of Binary Tree
    int maxDepth(TreeNode *root) {
        return helper(root, 0);
    }

    int helper(TreeNode *node, int count) {
        if (!node) return count;
        return max(helper(node->left, count + 1), helper(node->right, count + 1));
    }


    // Minimum Depth of Binary Tree
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        return helper1(root, 0);
    }

    int helper1(TreeNode *node, int count) {
        if (!node->left && !node->right) return count + 1;
        return min(node->left ? helper(node->left, count + 1) : INT_MAX,
                   node->right ? helper(node->right, count + 1) : INT_MAX);
    }
};