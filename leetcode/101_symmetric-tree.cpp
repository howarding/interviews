//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
//For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//        1
//       / \
//      2   2
//     / \ / \
//    3  4 4  3
//But the following [1,2,2,null,3,null,3] is not:
//      1
//     / \
//    2   2
//     \   \
//     3    3
//Note:
//    Bonus points if you could solve it both recursively and iteratively.

#include <iostream>
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
class Solution_101 {
public:
    // Recursive
    // Exp: https://discuss.leetcode.com/topic/4332/my-c-accepted-code-in-16ms-with-iteration-solution
    // Time:	O(n)
    // Space:	O(1)
    bool isSymmetric(TreeNode *root) {
        return !root || helper(root->left, root->right);
    }

    bool helper(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (!left != !right) return false;
        return left->val == right->val && helper(left->left, right->right) && helper(left->right, right->left);
    }


    // Iterative
    // Exp: https://discuss.leetcode.com/topic/4332/my-c-accepted-code-in-16ms-with-iteration-solution
    // Time:	O(n)
    // Space:	O(n)
    bool isSymmetric1(TreeNode *root) {
        if (!root) return true;
        queue<TreeNode *> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty()) {
            TreeNode *left = q1.front(), *right = q2.front();
            q1.pop();
            q2.pop();
            if (!left && !right) continue;
            if (!left || !right || left->val != right->val) return false;
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
};