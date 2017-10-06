//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//    You may assume that duplicates do not exist in the tree.

#include <iostream>
#include <vector>
#include <stack>

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

// PreOrder + InOrder
class Solution_105 {
public:
    // Recursive
    // Exp: https://discuss.leetcode.com/topic/3695/my-accepted-java-solution/27
    // Time:	O(n^2)
    // Space:	O(1)
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return tree(preorder, preorder.begin(), preorder.end(), inorder, inorder.begin(), inorder.end());
    }

    TreeNode *tree(
            vector<int> &preorder, vector<int>::iterator pre_begin, vector<int>::iterator pre_end,
            vector<int> &inorder, vector<int>::iterator in_begin, vector<int>::iterator in_end
    ) {
        if (pre_begin == pre_end) return nullptr;
        TreeNode *result = new TreeNode(*pre_begin);
        vector<int>::iterator in = find(in_begin, in_end, *pre_begin);
        int left_len = in - in_begin;
        result->left = tree(preorder, pre_begin + 1, pre_begin + left_len + 1, inorder, in_begin, in_begin + left_len);
        result->right = tree(preorder, pre_begin + left_len + 1, pre_end, inorder, in + 1, in_end);
        return result;
    }


    // Iterative, Stack    faster
    // Exp: https://discuss.leetcode.com/topic/795/the-iterative-solution-is-easier-than-you-think/24
    // Time:	O(n)
    // Space:	O(n)
    TreeNode *buildTree1(vector<int> &preorder, vector<int> &inorder) {
        if (inorder.empty()) return nullptr;
        int i = 0, j = 0;
        stack<TreeNode *> stk;
        TreeNode *result = new TreeNode(preorder[j++]);
        stk.push(result);

        while (j < preorder.size()) {
            if (stk.top()->val == inorder[i]) {
                TreeNode *p = stk.top();
                stk.pop();
                if (++i == inorder.size()) break;
                if (!stk.empty() && stk.top()->val == inorder[i])
                    continue;
                p->right = new TreeNode(preorder[j]);
                stk.push(p->right);
            } else {
                stk.top()->left = new TreeNode(preorder[j]);
                stk.push(stk.top()->left);
            }
            j++;
        }
        return result;
    }
};



// InOrder + PostOrder
class Solution_106 {
public:
    // Recursive
    // Time:	O(n^2)
    // Space:	O(1)
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return tree(inorder, inorder.begin(), inorder.end(), postorder, postorder.begin(), postorder.end());
    }

    TreeNode *tree(
            vector<int> &inorder, vector<int>::iterator in_begin, vector<int>::iterator in_end,
            vector<int> &postorder, vector<int>::iterator pos_begin, vector<int>::iterator pos_end
    ) {
        if (pos_begin == pos_end) return nullptr;
        TreeNode *result = new TreeNode(*(pos_end - 1));
        vector<int>::iterator in = find(in_begin, in_end, result->val);
        int right_len = in_end - in - 1;
        result->left = tree(inorder, in_begin, in, postorder, pos_begin, pos_end - right_len - 1);
        result->right = tree(inorder, in + 1, in_end, postorder, pos_end - right_len - 1, pos_end - 1);
        return result;
    }


    // Iterative, Stack     faster
    // Exp: https://discuss.leetcode.com/topic/4746/my-comprehension-of-o-n-solution-from-hongzhi
    // Time:	O(n)
    // Space:	O(n)
    TreeNode *buildTree1(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty()) return nullptr;
        int i = inorder.size() - 1, j = postorder.size() - 1;
        stack<TreeNode *> stk;
        TreeNode *result = new TreeNode(postorder[j--]);
        stk.push(result);

        while (j >= 0) {
            if (stk.top()->val == inorder[i]) {
                TreeNode *p = stk.top();
                stk.pop();
                if (--i < 0) break;
                if (!stk.empty() && stk.top()->val == inorder[i])
                    continue;
                p->left = new TreeNode(postorder[j]);
                stk.push(p->left);
            } else {
                stk.top()->right = new TreeNode(postorder[j]);
                stk.push(stk.top()->right);
            }
            j--;
        }
        return result;
    }
};