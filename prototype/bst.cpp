#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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

    while (node || !sta.empty()) {
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
        tmp = nullptr;
        while (!sta.empty()) {
            node = sta.top();
            sta.pop();
            if (tmp == node->right) {
                cout << node->val << " ";
                tmp = node;
            } else {
                sta.push(node);
                node = node->right;
                break;
            }
        }
    } while (!sta.empty());
}


/*
 *  bt: binary tree
 *  reverse(InOrder(bt)) == PostOrder(bt, order(right, left, root))
 *
 */



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


// delete a node with val == key from BST and return the root node
// Recursive
// Exp: https://discuss.leetcode.com/topic/65792/recursive-easy-to-understand-java-solution
// Time:	O(log(n))
// Space:	O(1)
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;
    if (root->val < key) root->right = deleteNode(root->right, key);
    else if (root->val > key) root->left = deleteNode(root->left, key);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        TreeNode* node = root->right;
        while (node->left) node = node->left;
        node->left = root->left;
        return root->right;
    }
    return root;
}


// Iterative
// Exp: https://discuss.leetcode.com/topic/67962/iterative-solution-in-java-o-h-time-and-o-1-space
// Time:	O(log(n))
// Space:	O(1)

TreeNode* deleteRootNode(TreeNode* node) {
    if (!node) return node;
    if (!node->left) return node->right;
    if (!node->right) return node->left;
    TreeNode* tmp = node->right;
    while (tmp->left) tmp = tmp->left;
    tmp->left = node->left;
    return node->right;
}

TreeNode* deleteNode1(TreeNode* root, int key) {
    if (!root) return root;
    TreeNode *parent = nullptr, *node = root;
    while (node && node->val != key) {
        parent = node;
        if (node->val > key) node = node->left;
        else node = node->right;
    }
    if (!parent) return deleteRootNode(node);
    if (parent->left == node) parent->left = deleteRootNode(node);
    else parent->right = deleteRootNode(node);
    return root;
}