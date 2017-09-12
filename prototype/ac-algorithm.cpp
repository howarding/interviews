#include <iostream>
#include <vector>
#include <queue>

#define N 26
using namespace std;

struct TrieNode {
    // no need to have parent pointer.
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


// Time:    O(n)    n: length of s
vector<pair<int, string>> search(TrieNode* root, vector<string>& words, string& s) {
    vector<pair<int, string>> result;
    TrieNode* node = root;
    for (int i = 0; i < s.size(); i++) {
        while (!node->child[s[i] - 'a'] && node != root) node = node->fail;
        if (!node->child[s[i] - 'a']) continue;
        node = node->child[s[i] - 'a'];
        TrieNode* tmp = node;
        while (tmp != root) {
            if (tmp->ind != -1)
                result.push_back({i - words[tmp->ind].size() + 1, words[tmp->ind]});
            tmp = tmp->fail;
        }
    }
    return result;
};



//int main() {
//    vector<string> words({
//            "he",
//            "her",
//            "she",
//            "hers",
//            "his"
//                         });
//    string s("shershers");

//    vector<string> words({"nihao","hao","hs","hsr"});
//    string s("sdmfhsgnshejfgnihaofhsrnihao");
//    vector<string> words({"xabc", "abc", "b", "a"});
//    string s("xabc");
//    TrieNode* trie = buildTrie(words);
//    buildFailPath(trie);
//    vector<pair<int, string>> result(search(trie, words, s));
//    for (auto&& pair: result)
//        cout << pair.first << "\t" << pair.second << endl;
//}