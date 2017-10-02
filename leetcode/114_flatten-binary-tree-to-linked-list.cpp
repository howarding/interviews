//Given a binary tree, flatten it to a linked list in-place.
//
//For example,
//Given
//
//         1
//        / \
//       2   5
//      / \   \
//     3   4   6
//The flattened tree should look like:
//   1
//    \
//     2
//      \
//       3
//        \
//         4
//          \
//           5
//            \
//             6
//click to show hints.
//
//Hints:
//If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

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
class Solution_114 {
public:
    // preOrder (My own)
    // Time:	O(n)
    // Space:	O(1)
    void flatten(TreeNode *root) {
        if (!root) return;
        TreeNode* pre = new TreeNode(-1);
        preOrder(root, pre);
    }

    void preOrder(TreeNode* node, TreeNode* &pre) {
        if (!node) return;
        pre->left = nullptr;
        pre->right = node;
        pre = node;
        TreeNode* right = node->right;
        preOrder(node->left, pre);
        preOrder(right, pre);
    }


    // Iterative
    // Exp: https://discuss.leetcode.com/topic/9933/16-lines-iterative-c-solution
    void flatten2(TreeNode *root) {
        while(root){
            if(root->left == NULL)
                root = root->right;
            else {
                if(root->right){
                    TreeNode *l = root->left;
                    while(l->right) l = l->right;
                    l->right = root->right;
                }
                root->right = root->left;
                root->left = NULL;
                root = root->right;
            }
        }
    }


    // PostOrder
    // Exp: https://discuss.leetcode.com/topic/11444/my-short-post-order-traversal-java-solution-for-share
    // Time:	O(n)
    // Space:	O(1)
    void flatten1(TreeNode *root) {
        if (!root) return;
        TreeNode* pre = nullptr;
        postOrder(root, pre);
    }

    void postOrder(TreeNode* node, TreeNode* &pre) {
        if (!node) return;
        postOrder(node->left, pre);
        postOrder(node->right, pre);
        node->right = pre;
        node->left = nullptr;
        pre = node;
    }
};


//int main() {
//    Solution_114 sol;
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    sol.flatten(root);
//}