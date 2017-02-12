//1. 有个dictionary，然后有个人在type word，你要补全他的word，返回所有的suggestion
//2. Input：英文字典（每个单词有个rank属性）和 user input string. Output：top 5 autocompletions for user input in ascending rank
//    D:用trie存所有的word，每个node可以保存一个vector，里面存所有经过此node的string，这样取的时候O(n). n是type word长度

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class typeahead {
    struct TrieNode {
        unordered_map<char, TrieNode *> child;
        vector<string> words;

        TrieNode() {};
    };

    TrieNode *root;
public:
    typeahead(vector<string> &dict) {
        root = new TrieNode();
        TrieNode *p = root;
        for (string &str : dict) {
            for (char c : str) {
                if (p->child.find(c) == p->child.end())
                    p->child[c] = new TrieNode();
                p->child[c]->words.push_back(str);
                p = p->child[c];
            }
        }
    }

    // Time:    O(n)    n: len of query
    vector<string> getSuggestion(string query) {
        vector<string> result;
        if (query.empty()) return result;
        TrieNode *p = root;
        for (char c : query) {
            if (p->child.find(c) == p->child.end())
                return {};
            p = p->child[c];
        }
        return p->words;
    }

};