//The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
//
//Determine the maximum amount of money the thief can rob tonight without alerting the police.
//
//Example 1:
//     3
//    / \
//   2   3
//    \   \
//     3   1
//Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
//Example 2:
//        3
//       / \
//      4   5
//     / \   \
//    1   3   1
//Maximum amount of money the thief can rob = 4 + 5 = 9.

#include <iostream>
#include <unordered_map>
#include <vector>

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
class Solution_337 {
public:
    // Exp: https://discuss.leetcode.com/topic/39834/step-by-step-tackling-of-the-problem
    // DP
    // Time:	O(n)
    // Space:	O(n)
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dict;
        return robSubtree(root, dict);
    }

    int robSubtree(TreeNode* node, unordered_map<TreeNode*, int>& dict) {
        if (!node) return 0;
        if (dict.count(node)) return dict[node];
        int val = 0;
        if (node->left)
            val += robSubtree(node->left->left, dict) + robSubtree(node->left->right, dict);
        if (node->right)
            val += robSubtree(node->right->left, dict) + robSubtree(node->right->right, dict);
        dict[node] = max(val + node->val, robSubtree(node->left, dict) + robSubtree(node->right, dict));
        return dict[node];
    }




    // DFS  faster
    // Time:	O(n)
    // Space:	O(n)
    int rob1(TreeNode* root) {
        vector<int> res = robSub(root);
        return max(res[0], res[1]);
    }

    vector<int> robSub(TreeNode* root) {
        if (!root) return vector<int>(2,0);

        vector<int> left(robSub(root->left));
        vector<int> right(robSub(root->right));

        vector<int> res(2,0);
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = root->val + left[0] + right[0];

        return res;
    }
};