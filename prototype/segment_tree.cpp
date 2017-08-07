#include <iostream>

using namespace std;

// Segment tree node structure
struct stNode {
    int low, high, cover;
    stNode *left, *right;
    stNode(int low, int high) : low(low), high(high), cover(0), left(nullptr), right(nullptr) {};
};



// Build a segment tree
stNode* build(int low, int high) {
    if (low >= high) return nullptr;
    auto node = new stNode(low, high);
    if (low < high - 1) {
        int mid = (low + high) >> 1;
        node->left = build(low, mid);
        node->right = build(mid, high);
    }
    return node;
}



// Insert a segment
void insert(int low, int high, stNode* root) {
    if (!root || low >= high) return;
    if (low <= root->low && high >= root->high) {
        root->cover++;
        return;
    }
    int mid = (root->low + root->high) >> 1;
    if (low < mid) insert(low, high, root->left);
    if (high > mid) insert(low, high, root->right);
}



// Remove a segment
void remove(int low, int high, stNode* root) {
    if (!root || low >= high) return;
    if (low <= root->low && high >= root->high) {
        root->cover--;
        return;
    }
    int mid = (root->low + root->high) >> 1;
    if (low < mid) remove(low, high, root->left);
    if (high > mid) remove(low, high, root->right);
}


// Count the length covered
int coverLen(stNode* root) {
    if (!root) return 0;
    if (root->cover) return root->high - root->low;
    return coverLen(root->left) + coverLen(root->right);
}