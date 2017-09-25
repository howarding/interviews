//Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
//
//Example 1:
//Given tree s:
//
//        3
//       / \
//      4   5
//     / \
//    1   2
//Given tree t:
//      4
//     / \
//    1   2
//Return true, because t has the same structure and node values with a subtree of s.
//Example 2:
//Given tree s:
//
//        3
//       / \
//      4   5
//     / \
//    1   2
//       /
//      0
//Given tree t:
//      4
//     / \
//    1   2
//Return false.

#include <iostream>

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
class Solution_572 {
public:
    // preOrder to string
    // Exp: https://leetcode.com/problems/subtree-of-another-tree/solution/
    // Time:	O(m^2 + n^2 + mn)
    // Space:	O(mn)
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string s_str = preOrder(s, true);
        string t_str = preOrder(t, true);
        return s_str.find(t_str) != string::npos;
    }

    string preOrder(TreeNode* node, bool left) {
        if (!node) return left ? "lnull" : "rnull";
        return "#" + to_string(node->val) +  " "
               + preOrder(node->left, true) + " "
               + preOrder(node->right, false);
    }


    // BEST!
    // Time:	O(mn)
    // Space:	O(1)
    bool isSubtree1(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        bool result = s->val == t->val ? equals(s, t) : false;
        return result || isSubtree1(s->left, t) || isSubtree1(s->right, t);
    }

    bool equals(TreeNode* x, TreeNode* y) {
        if (!x && !y) return true;
        if (!x || !y) return false;
        return x->val == y->val && equals(x->left, y->left) && equals(x->right, y->right);
    }


};