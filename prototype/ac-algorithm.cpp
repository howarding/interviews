#include <iostream>
#include <vector>
#include <queue>

#define N 26
using namespace std;

struct TrieNode {
    int ind;
    vector<TrieNode*> child;
    TrieNode* fail;
    TrieNode(int n): ind(-1), child(n), fail(nullptr) {}
};


TrieNode* buildTrie(vector<string>& words) {
    TrieNode* root = new TrieNode(N);
    TrieNode* node;
    for (int i = 0; i < words.size(); i++) {
        node = root;
        for (char c : words[i]) {
            if (!node->child[c - 'a'])
                node->child[c - 'a'] = new TrieNode(N);
            node = node->child[c - 'a'];
        }
        node->ind = i;
    }
    return root;
}


void buildFailPath(TrieNode* root) {
    queue<TrieNode*> que;
    for (TrieNode* node : root->child)
        if (node) {
            que.push(node);
            node->fail = root;
        }

    while (!que.empty()) {
        int num = que.size();
        while (num-- > 0) {
            TrieNode* node = que.front();
            que.pop();
            for (int i = 0; i < node->child.size(); i++) {
                if (!node->child[i]) continue;
                que.push(node->child[i]);
                TrieNode* fail = node->fail;
                while (fail) {
                    if (fail->child[i]) {
                        node->child[i]->fail = fail->child[i];
                        break;
                    }
                    fail = fail->fail;
                }
                if (!fail) node->child[i]->fail = root;
            }
        }
    }
}


vector<pair<int, string>> search(TrieNode* root, vector<string>& words, string& s) {
    vector<pair<int, string>> result;
    for (int i = 0; i < s.size(); i++) {

    }
};