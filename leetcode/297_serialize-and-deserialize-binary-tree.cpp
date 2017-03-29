//Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
//
//Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
//
//For example, you may serialize the following tree
//
//        1
//       / \
//      2   3
//         / \
//        4   5
//as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
//Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

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
class Codec {
public:
    // Preorder, Recursive
    // Exp: https://discuss.leetcode.com/topic/32470/clean-c-solution
    // Time:	O(n)
    // Space:	O(1)
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }


    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        return mydeserialize(data);
    }

    TreeNode *mydeserialize(string &data) {
        if (data[0] == '#') {
            if (data.size() > 1) data = data.substr(2);
            return nullptr;
        } else {
            TreeNode *node = new TreeNode(helper(data));
            node->left = mydeserialize(data);
            node->right = mydeserialize(data);
            return node;
        }
    }

    int helper(string &data) {
        int pos = data.find(',');
        int val = stoi(data.substr(0, pos));
        data = data.substr(pos + 1);
        return val;
    }

    // Level Order, BFS, Less space
    // Time:	O(n)
    // Space:	O(n)
    // Encodes a tree to a single string.
    string serialize1(TreeNode *root) {
        string result;
        if (!root) return result;
        queue<TreeNode *> que;
        result = to_string(root->val);
        que.push(root);
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            if (node->left) {
                que.push(node->left);
                result += "," + to_string(node->left->val);
            } else
                result += ",#";
            if (node->right) {
                que.push(node->right);
                result += "," + to_string(node->right->val);
            } else
                result += ",#";
        }
        while (result.back() == '#')
            result.erase(result.size() - 2);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize1(string data) {
        TreeNode *result = nullptr;
        if (data.empty()) return result;
        queue<TreeNode *> que;
        int start = 0, next = 0;
        string delimiter = ",";
        start = data.find(delimiter, 0);
        result = new TreeNode(stoi(data.substr(0, start)));
        TreeNode *node = result;
        que.push(node);
        while (start++ != string::npos) {
            node = que.front();
            que.pop();
            next = data.find(delimiter, start);
            if (data[start] != '#') {
                node->left = new TreeNode(stoi(data.substr(start, next)));
                que.push(node->left);
            }
            if (next == string::npos)
                break;
            start = next + 1;
            next = data.find(delimiter, start);
            if (data[start] != '#') {
                node->right = new TreeNode(stoi(data.substr(start, next)));
                que.push(node->right);
            }
            start = next;
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


//int main() {
//    Codec codec;
//    string data = "1,2";
//    TreeNode* root = codec.deserialize(data);
//    cout << codec.serialize(root) << endl;
//}