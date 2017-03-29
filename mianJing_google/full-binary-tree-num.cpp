//给定leaf node数量，生成所有可能的full binary tree的结构

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

class Solution_fbtn {
    vector<TreeNode *> generateFullBinaryTree(int n) {
        vector<TreeNode *> result;
        if (n == 0) return result;
        vector<vector<TreeNode *>> dp(n, vector<TreeNode *>());
        dp[0].push_back(new TreeNode(0));
        for (int k = 1; k < n; k++) {
            for (int i = 0; i < k; i++) {
                vector<TreeNode *> leftNodes = dp[i];
                vector<TreeNode *> rightNodes = dp[k - i];
                for (TreeNode *left : leftNodes)
                    for (TreeNode *right : rightNodes) {
                        TreeNode *root = new TreeNode(0);
                        root->left = left;
                        root->right = right;
                        dp[k].push_back(root);
                    }
            }
        }
        return dp[n - 1];
    }
};