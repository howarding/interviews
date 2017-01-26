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


// preorder the bst
void preOrder(TreeNode *node) {
    if (!node) return;
    cout << node->val << " ";
    preOrder(node->left);
    preOrder(node->right);
}


// inorder the bst
void inOrder(TreeNode *node) {
    if (!node) return;
    inOrder(node->left);
    cout << node->val << " ";
    inOrder(node->right);
}


// postorder the bst
void postOrder(TreeNode *node) {
    if (!node) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->val << " ";
}


// iterative preorder the bst
void iterativePreOrder(TreeNode *node) {
    if (!node) return;
    stack<TreeNode *> sta;

    sta.push(node);
    while (!sta.empty()) {
        node = sta.top();
        sta.pop();
        cout << node->val << " ";
        if (node->right)
            sta.push(node->right);
        if (node->left)
            sta.push(node->left);
    }
}


// iterative inorder the bst
void iterativeInOrder(TreeNode *node) {
    if (!node) return;
    stack<TreeNode *> sta;

    while (!sta.empty() || node) {
        if (node) {
            sta.push(node);
            node = node->left;
        } else {
            node = sta.top();
            sta.pop();
            cout << node->val << " ";
            node = node->right;
        }
    }
}


// iterative postorder the bst
void iterativePostOrder(TreeNode *node) {
    if (!node) return;
    stack<TreeNode *> sta;

    TreeNode *tmp;
    do {
        while (node) {
            sta.push(node);
            node = node->left;
        }
        tmp = NULL;
        while (!sta.empty()) {
            node = sta.top();
            sta.pop();
            if (tmp == node->right) {
                cout << node->val << " ";
                tmp = node->right;
            } else {
                sta.push(node);
                node = node->right;
                break;
            }
        }
    } while (!sta.empty());
}


// search a node with val == key in bst, recursive
TreeNode *search(TreeNode *node, int key) {
    if (!node || node->val == key)
        return node;
    if (node->val < key)
        return search(node->left, key);
    else
        return search(node->right, key);
}


// search a node with val == key in bst, iterative
TreeNode *iterativeSearch(TreeNode *node, int key) {
    TreeNode *x = node;
    while (x && x->val != key) {
        if (x->val < key)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}


// find the node with minimum val in bst
TreeNode *minimum(TreeNode *node) {
    if (!node)
        return NULL;
    while (!node->left)
        node = node->left;
    return node;
}


// find the node with maximum val in bst
TreeNode *maximum(TreeNode *node) {
    if (!node)
        return NULL;
    while (!node->right)
        node = node->right;
    return node;
}


// find successor of key in BST. iterative
// Exp: http://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/
// Time:	O(h)
// Space:	O(1)
TreeNode *iterativeSuccessor(TreeNode *node, int key) {
    TreeNode *suc = NULL;
    if (!node) return suc;
    while (node) {
        if (node->val > key) {
            suc = node;
            node = node->left;
        } else
            node = node->right;
    }
    return suc;
}


// find successor of key in BST. recursive
// Exp: http://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/
// Time:	O(h)
// Space:	O(1)
TreeNode *successor(TreeNode *node, TreeNode *suc, int key) {
    if (!node) return suc;
    if (node->val > key)
        return successor(node->left, node, key);
    else
        return successor(node->right, suc, key);
}


// find predecessor of key in BST. iterative
// Similar to iterativeSuccessor
// Time:	O(h)
// Space:	O(1)
TreeNode *iterativPredecessor(TreeNode *node, int key) {
    TreeNode *pre = NULL;
    if (!node) return pre;
    while (node) {
        if (node->val < key) {
            pre = node;
            node = node->right;
        } else
            node = node->left;
    }
    return pre;
}


// find predecessor of key in BST. recursive
// Similar to successor
// Time:	O(h)
// Space:	O(1)
TreeNode *predecessor(TreeNode *node, TreeNode *pre, int key) {
    if (!node) return pre;
    if (node->val < key)
        return predecessor(node->right, node, key);
    else
        return predecessor(node->left, pre, key);
}


// insert a node into BST. recursive
// A new key is always inserted at leaf.
// Exp: http://quiz.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
// Time:	O(h)
// Space:	O(1)
void insert(TreeNode *&root, TreeNode *node) {
    if (!root) {
        root = node;
        return;
    }
    if (root->val < node->val)
        insert(root->right, node);
    else if (root->val > node->val)
        insert(root->left, node);
}


// remove a node with val == key from BST and return the removed node
// Exp: http://quiz.geeksforgeeks.org/binary-search-tree-set-2-delete/
// not finished.
TreeNode *remove(TreeNode *node, TreeNode *parent, int key) {
    if (!node) return NULL;
    if (node->val < key)
        return remove(node->right, node, key);
    if (node->val > key)
        return remove(node->left, node, key);
    if (!node->left) {
        TreeNode *tmp = node;
    }
}