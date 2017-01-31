//Given a binary tree, find the length of the longest consecutive sequence path.
//
//The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).
//
//For example,
//       1
//        \
//         3
//        / \
//       2   4
//            \
//             5
//Longest consecutive sequence path is 3-4-5, so return 3.
//       2
//        \
//         3
//        /
//       2
//      /
//     1
//Longest consecutive sequence path is 2-3,not3-2-1, so return 2.

#include <iostream>
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
class Solution_298 {
public:
    // Exp: https://discuss.leetcode.com/topic/28234/easy-java-dfs-is-there-better-time-complexity-solution
    // DFS
    // Time:	O(n)
    // Space:	O(1)
    int longestConsecutive(TreeNode *root) {
        int count = 0;
        dfs(root, 0, 0, count);
        return count;
    }

    void dfs(TreeNode *node, int next, int length, int &count) {
        if (!node) return;
        if (node->val == next) length++;
        else length = 1;
        next = node->val + 1;
        count = max(count, length);
        dfs(node->left, next, length, count);
        dfs(node->right, next, length, count);
    }
};