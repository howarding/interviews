//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
//
//According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
//
//         _______3______
//        /              \
//     ___5__          ___1__
//    /      \        /      \
//   6      _2       0       8
//         /  \
//         7   4
//For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

#include <iostream>
#include <unordered_set>

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
    // Recursive
    // Exp: https://discuss.leetcode.com/topic/18561/4-lines-c-java-python-ruby
    // Time:	O(n)
    // Space:	O(1)
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        return left ? (right ? root : left) : right;
    }
};




//Lowest Common Ancestor of a Binary Search Tree
class Solution_235 {
public:
    // Recursive
    // Exp: https://discuss.leetcode.com/topic/18387/3-lines-with-o-1-space-1-liners-alternatives
    // Time:    O(n)    Only 1 path of the tree.
    // Space:   O(1)
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        return (root->val - p->val) * (root->val - q->val) <= 0 ? root :
               lowestCommonAncestor(root->val > p->val ? root->left : root->right, p, q);
    }


    // Iterative    faster
    // Time:    O(h)    Only 1 path of the tree.
    // Space:   O(1)
    TreeNode *lowestCommonAncestor_1(TreeNode *root, TreeNode *p, TreeNode *q) {
        while (root) {
            if ((root->val - p->val) * (root->val - q->val) <= 0)
                return root;
            root = root->val > p->val ? root->left : root->right;
        }
        return root;
    }
};



//函数要改成 public TreeNode lowestCommonAncestor(TreeNode root,set<TreeNode> set). 就是找一个set里面所有的子节点 的共同祖先  这道题如果用递归 base case应该怎么写啊？
class Solution_fu {
public:
    // Recursive
    TreeNode *lowestCommonAncestor(TreeNode *root, unordered_set<TreeNode*>& nodes) {
        if (!root || nodes.find(root) != nodes.end()) return root;
        TreeNode *left = lowestCommonAncestor(root->left, nodes);
        TreeNode *right = lowestCommonAncestor(root->right, nodes);
        return left ? (right ? root : left) : right;
    }
};